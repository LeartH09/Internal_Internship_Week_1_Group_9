#include <stdio.h>

int main() {
    int start, end;
    int i;
    int evenCount = 0, oddCount = 0;
    int evenSum = 0, oddSum = 0;
    int totalValues = 0;

    printf("Enter the starting value: ");
    scanf("%d", &start);

    printf("Enter the ending value: ");
    scanf("%d", &end);

    if (start > end) {
        printf("Invalid interval. The starting value must be less than or equal to the ending value.\n");
        return 0;
    }

    for (i = start; i <= end; i++) {
        totalValues++;

        if (i % 2 == 0) {
            evenCount++;
            evenSum += i;
        } else {
            oddCount++;
            oddSum += i;
        }
    }

    printf("\n--- Interval Analysis ---\n");
    printf("Interval: %d to %d\n", start, end);
    printf("Total values: %d\n", totalValues);
    printf("Even numbers count: %d\n", evenCount);
    printf("Odd numbers count: %d\n", oddCount);
    printf("Sum of even numbers: %d\n", evenSum);
    printf("Sum of odd numbers: %d\n", oddSum);

    if (evenCount > oddCount) {
        printf("Category with more numbers: Even\n");
    } else if (oddCount > evenCount) {
        printf("Category with more numbers: Odd\n");
    } else {
        printf("Category with more numbers: Equal amount\n");
    }

    return 0;
}
