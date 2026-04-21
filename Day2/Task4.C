#include <stdio.h>

int main() {
    int age, workshopOption;
    char initial;
    double points;

    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Enter your initial: ");
    scanf(" %c", &initial);

    printf("Enter your preliminary points: ");
    scanf("%lf", &points);

    printf("Choose workshop (1-3): ");
    scanf("%d", &workshopOption);

    printf("\n--- Registration Summary ---\n");
    printf("Age: %d\n", age);
    printf("Initial: %c\n", initial);
    printf("Preliminary Points: %.2lf\n", points);

    if (age >= 15) {
        printf("Participation: Allowed\n");
    } else {
        printf("Participation: Not Allowed\n");
    }

    if (points < 50) {
        printf("Result: Needs More Practice\n");
    } else if (points < 80) {
        printf("Result: Ready to Continue\n");
    } else {
        printf("Result: Ready for Challenge\n");
    }

    switch (workshopOption) {
        case 1:
            printf("Workshop: Programming Basics\n");
            break;
        case 2:
            printf("Workshop: Web Development\n");
            break;
        case 3:
            printf("Workshop: Robotics\n");
            break;
        default:
            printf("Workshop: Invalid option\n");
    }

    return 0;
}
