#include <stdio.h>

/* Use unsigned long long to avoid overflow when summing 35,040 watt-hour readings */
typedef unsigned long long energy_wh_t;

double compute_smart_bill(energy_wh_t normal_wh, energy_wh_t peak_wh, double rate_kwh) {
    double normal_kwh = (double)normal_wh / 1000.0;
    double peak_kwh = (double)peak_wh / 1000.0;
    
    /* Time-of-day tariff: 30% surcharge applied to peak units */
    double bill = (normal_kwh * rate_kwh) + (peak_kwh * (rate_kwh * 1.30));
    return bill;
}

int main(void) {
    /* Simulating 35,040 interval readings across a full year */
    energy_wh_t normal_interval_wh = 3500000ULL;
    energy_wh_t peak_interval_wh = 1200000ULL;
    double base_rate = 4.50; /* Rs 4.50 per kWh */

    double bill_amount = compute_smart_bill(normal_interval_wh, peak_interval_wh, base_rate);

    printf("=== Smart Meter Time-of-Day Billing (35,040 Readings/Year) ===\n");
    printf("Normal Consumption: %llu Wh (%.2f kWh)\n", normal_interval_wh, (double)normal_interval_wh / 1000.0);
    printf("Peak Consumption:   %llu Wh (%.2f kWh)\n", peak_interval_wh, (double)peak_interval_wh / 1000.0);
    printf("Base Tariff Rate:   Rs %.2f / kWh\n", base_rate);
    printf("Total Annual Bill:  Rs %.2f\n", bill_amount);

    return 0;
}