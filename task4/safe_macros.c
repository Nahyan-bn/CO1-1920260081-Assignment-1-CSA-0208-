#include <stdio.h>

/* Fully parenthesized to avoid operator precedence issues */
#define SQUARE(x) ((x) * (x))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define RUPEES_TO_PAISE(r) ((long)((r) * 100))

int main(void)
{
    int val = 3;
    /* SQUARE(val + 1) expands safely to ((3 + 1) * (3 + 1)) = 16 */
    printf("SQUARE(3 + 1) = %d\n", SQUARE(val + 1));

    int a = 15, b = 25;
    printf("MAX(%d, %d) = %d\n", a, b, MAX(a, b));
    printf("Rs 2.25 converted to paise = %ld\n", RUPEES_TO_PAISE(2.25));
    return 0;
}