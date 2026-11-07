#include <stdio.h>

typedef unsigned short meter_t;

#define SLAB1_LIMIT 100
#define SLAB2_LIMIT 200
#define RATE1 0
#define RATE2 225
#define RATE3 450
#define FIXED_FEE 5000

unsigned int get_units(meter_t prev, meter_t curr) {
    return (unsigned short)(curr - prev);
}

long calculate_bill(unsigned int units) {
    long paise = FIXED_FEE;
    if (units <= SLAB1_LIMIT) {
        paise += (long)units * RATE1;
    } else if (units <= SLAB2_LIMIT) {
        paise += (long)(units - SLAB1_LIMIT) * RATE2;
    } else {
        paise += (long)(SLAB2_LIMIT - SLAB1_LIMIT) * RATE2 + (long)(units - SLAB2_LIMIT) * RATE3;
    }
    return paise;
}

int main(void) {
    struct {
        meter_t prev;
        meter_t curr;
        const char *desc;
    } tests[] = {
        {100, 100, "Boundary: Zero units"},
        {100, 200, "Boundary: Exact 100 units"},
        {100, 300, "Boundary: Exact 200 units"},
        {65400, 120, "Rollover: 65400 to 120"},
        {100, 350, "Slab 3: Normal 250 units"}
    };

    printf("%-30s | %-6s | %-6s | %-6s | %-12s\n", "Test Case", "Prev", "Curr", "Units", "Total Bill");
    printf("----------------------------------------------------------------------\n");

    for (int i = 0; i < 5; i++) {
        unsigned int u = get_units(tests[i].prev, tests[i].curr);
        long b = calculate_bill(u);
        printf("%-30s | %6u | %6u | %6u | Rs %3ld.%02ld\n",
               tests[i].desc, tests[i].prev, tests[i].curr, u, b / 100, b % 100);
    }

    return 0;
}