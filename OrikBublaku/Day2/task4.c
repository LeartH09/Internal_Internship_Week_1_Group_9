#include <stdio.h>

int main() {
    int age, option;
    char initial;
    double points;

    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Enter your initial: ");
    scanf(" %c", &initial);

    printf("Enter your previous points: ");
    scanf("%lf", &points);

    printf("Choose workshop option (1-3): ");
    scanf("%d", &option);

    printf("\n--- Workshop Registration Summary ---\n");
    printf("Age: %d\n", age);
    printf("Initial: %c\n", initial);
    printf("Previous Points: %.2lf\n", points);

    if (age >= 15 && age <= 19) {
        printf("Age Status: Allowed to participate\n");
    } else {
        printf("Age Status: Not allowed to participate\n");
    }

    if (points < 50) {
        printf("Level: Needs more practice\n");
    } else if (points < 80) {
        printf("Level: Ready to continue\n");
    } else {
        printf("Level: Ready for challenge\n");
    }

    switch(option) {
        case 1:
            printf("Workshop: Programming Basics\n");
            break;
        case 2:
            printf("Workshop: Web Development\n");
            break;
        case 3:
            printf("Workshop: Problem Solving\n");
            break;
        default:
            printf("Workshop: Invalid option\n");
    }

    return 0;
}