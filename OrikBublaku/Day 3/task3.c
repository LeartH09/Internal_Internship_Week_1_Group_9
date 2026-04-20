#include <stdio.h>

int main() {
    int start, end, i;
    int countDiv3 = 0, countDiv5Not3 = 0;
    int sumDiv3 = 0, sumDiv5Not3 = 0;

    // Input
    printf("Enter start of interval: ");
    scanf("%d", &start);

    printf("Enter end of interval: ");
    scanf("%d", &end);

    // Validate input
    if (start > end) {
        printf("Invalid interval! Start must be less than or equal to end.\n");
        return 1;
    }

    // Loop through interval
    for (i = start; i <= end; i++) {
        if (i % 3 == 0) {
            countDiv3++;
            sumDiv3 += i;
        } 
        else if (i % 5 == 0 && i % 3 != 0) {
            countDiv5Not3++;
            sumDiv5Not3 += i;
        }
    }

    // Output
    printf("\n--- Results ---\n");
    printf("Interval: %d to %d\n", start, end);

    printf("\nNumbers divisible by 3:\n");
    printf("Count: %d\n", countDiv3);
    printf("Sum: %d\n", sumDiv3);

    printf("\nNumbers divisible by 5 but not by 3:\n");
    printf("Count: %d\n", countDiv5Not3);
    printf("Sum: %d\n", sumDiv5Not3);

    // Compare sums
    printf("\n--- Comparison ---\n");
    if (sumDiv3 > sumDiv5Not3) {
        printf("The sum of numbers divisible by 3 is greater.\n");
    } else if (sumDiv5Not3 > sumDiv3) {
        printf("The sum of numbers divisible by 5 but not by 3 is greater.\n");
    } else {
        printf("Both sums are equal.\n");
    }

    return 0;
}