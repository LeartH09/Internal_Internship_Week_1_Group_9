#include <stdio.h>

int main() {
    int size, choice;
    int i, j;

    printf("Enter pattern size (1-12): ");
    scanf("%d", &size);

    if (size < 1 || size > 12) {
        printf("Invalid input. Size must be between 1 and 12.\n");
        return 0;
    }

    printf("Choose pattern type:\n");
    printf("1 - Stars\n");
    printf("2 - Numbers\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("\nStar Pattern:\n");
        for (i = 1; i <= size; i++) {
            for (j = 1; j <= i; j++) {
                printf("*");
            }
            printf("\n");
        }
    }
    else if (choice == 2) {
        printf("\nNumber Pattern:\n");
        for (i = 1; i <= size; i++) {
            for (j = 1; j <= i; j++) {
                printf("%d", j);
            }
            printf("\n");
        }
    }
    else {
        printf("Invalid choice.\n");
    }

    return 0;
}
