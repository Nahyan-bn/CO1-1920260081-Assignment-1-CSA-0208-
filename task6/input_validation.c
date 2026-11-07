#include <stdio.h>

int main(void)
{
    unsigned short prev, curr;
    printf("Enter previous and current readings: ");

    /* Check the return value of scanf to ensure 2 valid integers were entered */
    if (scanf("%hu %hu", &prev, &curr) != 2) {
        printf("Error: Invalid meter reading input.\n");
        return 1;
    }

    unsigned short units = (unsigned short)(curr - prev);
    printf("Previous: %hu, Current: %hu | Units Consumed: %u\n", prev, curr, units);
    return 0;
}