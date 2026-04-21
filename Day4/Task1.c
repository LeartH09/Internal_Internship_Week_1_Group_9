#include <stdio.h>
#include <string.h>

#define MAX 5

struct Record {
    char name[50];
    int progress;
};

int main() {
    struct Record records[MAX];
    int count = 0;
    int choice;
    int i;

    while (1) {
        printf("\n1. Add record\n");
        printf("2. Show records\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            if (count == MAX) {
                printf("Maximum number of records reached.\n");
            } else {
                printf("Enter name: ");
                scanf("%s", records[count].name);

                printf("Enter progress: ");
                scanf("%d", &records[count].progress);

                count++;
                printf("Record added.\n");
            }
        }
        else if (choice == 2) {
            if (count == 0) {
                printf("No records found.\n");
            } else {
                for (i = 0; i < count; i++) {
                    printf("\nRecord %d\n", i + 1);
                    printf("Name: %s\n", records[i].name);
                    printf("Progress: %d\n", records[i].progress);
                }
            }
        }
        else if (choice == 3) {
            break;
        }
        else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
