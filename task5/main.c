#include <stdio.h>
#include "billing.h"

unsigned int get_units(meter_t prev, meter_t curr) {
    return (unsigned short)(curr - prev);
}

long calculate_bill(unsigned int units) {
    long paise = FIXED_FEE;
#ifdef DEBUG
    printf("[DEBUG] Calculating bill for %u units...\n", units);
#endif
    if (units <= SLAB1_LIMIT) {
        paise += (long)units * RATE1;
    } else if (units <= SLAB2_LIMIT) {
        paise += (long)SLAB1_LIMIT * RATE1 + (long)(units - SLAB1_LIMIT) * RATE2;
    } else {
        paise += (long)SLAB1_LIMIT * RATE1 + (long)(SLAB2_LIMIT - SLAB1_LIMIT) * RATE2 + (long)(units - SLAB2_LIMIT) * RATE3;
    }
    return paise;
}

int main(void) {
    unsigned int units = get_units(65400, 120);
    long bill = calculate_bill(units);
    printf("Units: %u | Bill: Rs %ld.%02ld\n", units, bill / 100, bill % 100);
    return 0;
}