#include <stdio.h>

int main() {
    int start, end;
    int i;
    int countDiv3 = 0, countDiv5Not3 = 0;
    int sumDiv3 = 0, sumDiv5Not3 = 0;

    printf("Enter the starting value: ");
    scanf("%d", &start);

    printf("Enter the ending value: ");
    scanf("%d", &end);

    if (start > end) {
        printf("Invalid interval. Start must be less than or equal to end.\n");
        return 0;
    }

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

    printf("\n--- Interval Summary ---\n");
    printf("Interval: %d to %d\n", start, end);
    printf("Numbers divisible by 3: %d\n", countDiv3);
    printf("Sum of numbers divisible by 3: %d\n", sumDiv3);
    printf("Numbers divisible by 5 but not by 3: %d\n", countDiv5Not3);
    printf("Sum of numbers divisible by 5 but not by 3: %d\n", sumDiv5Not3);

    if (sumDiv3 > sumDiv5Not3) {
        printf("The greater sum is: Numbers divisible by 3\n");
    } else if (sumDiv5Not3 > sumDiv3) {
        printf("The greater sum is: Numbers divisible by 5 but not by 3\n");
    } else {
        printf("The sums are equal\n");
    }

    return 0;
}
