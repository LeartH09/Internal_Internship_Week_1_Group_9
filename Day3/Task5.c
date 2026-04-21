#include <stdio.h>

enum Level {
    BEGINNER = 1,
    INTERMEDIATE,
    ADVANCED,
    EXPERT
};

int main() {
    int i, choice;
    int validCount = 0;
    int invalidCount = 0;
    enum Level level;

    for (i = 1; i <= 3; i++) {
        printf("Enter level for user %d (1-4): ", i);
        scanf("%d", &choice);

        if (choice < 1 || choice > 4) {
            printf("Invalid choice.\n");
            invalidCount++;
            continue;
        }

        level = choice;
        validCount++;

        switch (level) {
            case BEGINNER:
                printf("Level: Beginner - Start with basic exercises.\n");
                break;
            case INTERMEDIATE:
                printf("Level: Intermediate - You can continue with standard tasks.\n");
                break;
            case ADVANCED:
                printf("Level: Advanced - You are ready for more difficult tasks.\n");
                break;
            case EXPERT:
                printf("Level: Expert - You can handle challenging problems.\n");
                break;
            default:
                printf("Invalid choice.\n");
                invalidCount++;
        }
    }

    printf("\n--- Statistics ---\n");
    printf("Valid choices: %d\n", validCount);
    printf("Invalid choices: %d\n", invalidCount);

    return 0;
}
