#include <stdio.h>

int main() {
    int age;
    char initial;
    float height;
    double average;
    short s_number = 10;
    long l_number = 100000;

    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Enter your initial: ");
    scanf(" %c", &initial);

    printf("Enter your height: ");
    scanf("%f", &height);

    printf("Enter your average: ");
    scanf("%lf", &average);

    printf("\n--- User Profile ---\n");
    printf("Age: %d\n", age);
    printf("Initial: %c\n", initial);
    printf("Height: %.2f\n", height);
    printf("Average: %.2lf\n", average);
    printf("Short number: %d\n", s_number);
    printf("Long number: %ld\n", l_number);

    return 0;
}