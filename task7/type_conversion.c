#include <stdio.h>

int main(void)
{
    /* 1. Implicit conversion pitfall: integer division */
    int units = 150;
    double bad_rate = units / 100;          /* Evaluates to 1.0 (integer division) */
    double correct_rate = (double)units / 100; /* Evaluates to 1.5 */
    printf("Integer division loss: %.2f vs Explicit cast: %.2f\n", bad_rate, correct_rate);

    /* 2. Truncation and overflow when casting large types */
    long long large_reading = 70000LL;
    short truncated_reading = (short)large_reading; /* Exceeds short range (-32768 to 32767) */
    printf("Original value: %lld | Truncated to short: %d\n", large_reading, truncated_reading);

    /* 3. Safe paise conversion avoiding float precision loss */
    double rupees = 12.35;
    long paise = (long)(rupees * 100.0 + 0.5); /* Proper rounding */
    printf("Rupees: %.2f -> Paise: %ld\n", rupees, paise);

    return 0;
}