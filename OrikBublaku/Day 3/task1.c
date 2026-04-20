#include <stdio.h>

int main() {
    int size, choice, i, j;

    // Ask for size
    printf("Enter a positive number (1-12): ");
    scanf("%d", &size);

    // Validate input
    if (size < 1 || size > 12) {
        printf("Invalid input! Please enter a number between 1 and 12.\n");
        return 1;
    }

    // Ask for pattern type
    printf("Choose pattern type:\n");
    printf("1. Star pattern\n");
    printf("2. Number pattern\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    // Print star pattern
    if (choice == 1) {
        printf("\nStar Pattern:\n");
        for (i = 1; i <= size; i++) {
            for (j = 1; j <= i; j++) {
                printf("* ");
            }
            printf("\n");
        }
    }
    // Print number pattern
    else if (choice == 2) {
        printf("\nNumber Pattern:\n");
        for (i = 1; i <= size; i++) {
            for (j = 1; j <= i; j++) {
                printf("%d ", j);
            }
            printf("\n");
        }
    }
    // Invalid pattern choice
    else {
        printf("Invalid choice! Please run the program again and choose 1 or 2.\n");
    }

    return 0;
}