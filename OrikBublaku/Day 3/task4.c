#include <stdio.h>

int main() {
    int num;
    float decimal;

    int originalNum;
    int *ptrNum;
    float *ptrDecimal;

    // Input values
    printf("Enter an integer value: ");
    scanf("%d", &num);

    printf("Enter a decimal value: ");
    scanf("%f", &decimal);

    // Save original value before change
    originalNum = num;

    // Assign addresses to pointers
    ptrNum = &num;
    ptrDecimal = &decimal;

    // Show direct values, addresses, and pointer values
    printf("\n--- Before Change ---\n");
    printf("Integer value directly: %d\n", num);
    printf("Integer address: %p\n", (void*)&num);
    printf("Integer value through pointer: %d\n", *ptrNum);

    printf("\nDecimal value directly: %.2f\n", decimal);
    printf("Decimal address: %p\n", (void*)&decimal);
    printf("Decimal value through pointer: %.2f\n", *ptrDecimal);

    // Change integer value through pointer
    *ptrNum = *ptrNum + 10;

    printf("\n--- After Change ---\n");
    printf("Original integer value: %d\n", originalNum);
    printf("New integer value: %d\n", num);

    // Final check with if/else
    if (num > originalNum) {
        printf("Final message: The integer value increased.\n");
    } else if (num < originalNum) {
        printf("Final message: The integer value decreased.\n");
    } else if (num >= 0 && num <= 20) {
        printf("Final message: The integer value stayed the same and is in the interval 0 to 20.\n");
    } else {
        printf("Final message: The integer value stayed the same.\n");
    }

    return 0;
}