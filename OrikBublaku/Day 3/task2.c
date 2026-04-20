#include <stdio.h>

int main() {
    int start, end;
    int i;

    int evenCount = 0, oddCount = 0;
    int evenSum = 0, oddSum = 0;

    // Input interval
    printf("Enter start of interval: ");
    scanf("%d", &start);

    printf("Enter end of interval: ");
    scanf("%d", &end);

    // Validate interval
    if (start > end) {
        printf("Invalid interval! Start must be less than or equal to end.\n");
        return 1;
    }

    // Loop through interval
    for (i = start; i <= end; i++) {

        if (i % 2 == 0) {
            evenCount++;
            evenSum += i;
        } else {
            oddCount++;
            oddSum += i;
        }
    }

    // Total numbers
    int total = end - start + 1;

    // Output
    printf("\n--- Results ---\n");
    printf("Interval: %d to %d\n", start, end);
    printf("Total numbers: %d\n", total);

    printf("Even numbers count: %d\n", evenCount);
    printf("Odd numbers count: %d\n", oddCount);

    printf("Sum of even numbers: %d\n", evenSum);
    printf("Sum of odd numbers: %d\n", oddSum);

    // Which category is bigger
    if (evenCount > oddCount) {
        printf("More EVEN numbers in this interval.\n");
    } else if (oddCount > evenCount) {
        printf("More ODD numbers in this interval.\n");
    } else {
        printf("Equal number of EVEN and ODD numbers.\n");
    }

    return 0;
}