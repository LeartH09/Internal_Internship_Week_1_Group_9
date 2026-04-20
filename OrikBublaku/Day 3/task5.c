#include <stdio.h>

// Create enum
enum Level {BEGINNER = 1, INTERMEDIATE, ADVANCED, EXPERT};

int main() {
    int choice;
    int validCount = 0, invalidCount = 0;

    // Loop for 3 users
    for (int i = 1; i <= 3; i++) {
        printf("\nUser %d\n", i);
        printf("Choose level:\n");
        printf("1. Beginner\n");
        printf("2. Intermediate\n");
        printf("3. Advanced\n");
        printf("4. Expert\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case BEGINNER:
                printf("You are a beginner.\n");
                validCount++;
                break;

            case INTERMEDIATE:
                printf("You are intermediate.\n");
                validCount++;
                break;

            case ADVANCED:
                printf("You are advanced.\n");
                validCount++;
                break;

            case EXPERT:
                printf("You are an expert.\n");
                validCount++;
                break;

            default:
                printf("Invalid choice!\n");
                invalidCount++;
        }
    }

    // Final statistics
    printf("\n--- Statistics ---\n");
    printf("Valid choices: %d\n", validCount);
    printf("Invalid choices: %d\n", invalidCount);

    return 0;
}