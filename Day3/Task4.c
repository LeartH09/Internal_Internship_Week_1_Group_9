#include <stdio.h>

int main() {
    int number;
    float price;

    int oldNumber;
    float oldPrice;

    int *pNumber;
    float *pPrice;

    printf("Enter an integer value: ");
    scanf("%d", &number);

    printf("Enter a float value: ");
    scanf("%f", &price);

    oldNumber = number;
    oldPrice = price;

    pNumber = &number;
    pPrice = &price;

    printf("\n--- Before Change ---\n");
    printf("Direct integer value: %d\n", number);
    printf("Integer address: %p\n", (void*)&number);
    printf("Integer value through pointer: %d\n", *pNumber);

    printf("Direct float value: %.2f\n", price);
    printf("Float address: %p\n", (void*)&price);
    printf("Float value through pointer: %.2f\n", *pPrice);

    *pNumber = *pNumber + 5;
    *pPrice = *pPrice - 2.5f;

    printf("\n--- After Change ---\n");
    printf("Updated integer value: %d\n", number);
    printf("Updated float value: %.2f\n", price);

    printf("\n--- Final Check ---\n");

    if (number > oldNumber) {
        printf("The integer value increased.\n");
    } else if (number < oldNumber) {
        printf("The integer value decreased.\n");
    } else {
        printf("The integer value stayed the same.\n");
    }

    if (price > oldPrice) {
        printf("The float value increased.\n");
    } else if (price < oldPrice) {
        printf("The float value decreased.\n");
    } else {
        printf("The float value stayed the same.\n");
    }

    if (number >= 0 && number <= 20) {
        printf("The final integer value is in the interval 0 to 20.\n");
    } else {
        printf("The final integer value is outside the interval 0 to 20.\n");
    }

    return 0;
}
