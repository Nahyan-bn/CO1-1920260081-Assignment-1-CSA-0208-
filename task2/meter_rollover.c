#include <stdio.h>
#include <limits.h>

/* The meter register is a 16-bit counter: after 65535 it rolls over to 0 */
typedef unsigned short meter_t;

unsigned int consumption(meter_t previous, meter_t current)
{
    /*
     * Using 16-bit arithmetic:
     * When current < previous, casting (current - previous) to unsigned short
     * automatically wraps modulo 65536, yielding the exact consumed units.
     */
    return (unsigned short)(current - previous);
}

int main(void)
{
    printf("sizeof(meter_t) : %zu bytes; maximum reading : %u\n",
           sizeof(meter_t), (unsigned)USHRT_MAX);
    printf("Consumption: %u units\n", consumption(200, 350));
    printf("Consumption: %u units\n", consumption(65400, 120)); /* rolled over */
    return 0;
}