#include <stdio.h>

int main(void) {
    long long households = 600000LL;
    long avg_bill_paise = 27500L; /* Rs 275.00 */

    /* Total in integer paise using 64-bit long long */
    long long total_paise = households * avg_bill_paise;
    
    /* Equivalent calculation using double */
    double total_double_rupees = households * 275.00;

    printf("District-Scale Billing Analysis (600,000 households):\n");
    printf("Total using long long paise: %lld paise (Rs %lld.%02lld)\n", 
           total_paise, total_paise / 100, total_paise % 100);
    printf("Total using floating point:  Rs %.2f\n", total_double_rupees);

    return 0;
}