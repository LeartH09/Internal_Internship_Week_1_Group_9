#include <stdio.h>

#define MAX 5

enum Status {
    NOT_STARTED = 1,
    IN_PROGRESS,
    COMPLETED
};

struct Record {
    char name[50];
    int progress;
    enum Status status;
};

int main() {
    struct Record records[MAX];
    int count = 0;
    int choice, i;

    while (1) {
        printf("\n1. Add record\n");
        printf("2. Show records\n");
        printf("3. Show report\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int statusChoice;

                if (count == MAX) {
                    printf("Maximum records reached.\n");
                    break;
                }

                printf("Enter name: ");
                scanf("%s", records[count].name);

                printf("Enter progress: ");
                scanf("%d", &records[count].progress);

                printf("Choose status:\n");
                printf("1. Not Started\n");
                printf("2. In Progress\n");
                printf("3. Completed\n");
                printf("Enter status: ");
                scanf("%d", &statusChoice);

                switch (statusChoice) {
                    case 1:
                        records[count].status = NOT_STARTED;
                        count++;
                        printf("Record added.\n");
                        break;
                    case 2:
                        records[count].status = IN_PROGRESS;
                        count++;
                        printf("Record added.\n");
                        break;
                    case 3:
                        records[count].status = COMPLETED;
                        count++;
                        printf("Record added.\n");
                        break;
                    default:
                        printf("Invalid status.\n");
                }

                break;
            }

            case 2:
                if (count == 0) {
                    printf("No records found.\n");
                } else {
                    for (i = 0; i < count; i++) {
                        printf("\nRecord %d\n", i + 1);
                        printf("Name: %s\n", records[i].name);
                        printf("Progress: %d\n", records[i].progress);

                        switch (records[i].status) {
                            case NOT_STARTED:
                                printf("Status: Not Started\n");
                                break;
                            case IN_PROGRESS:
                                printf("Status: In Progress\n");
                                break;
                            case COMPLETED:
                                printf("Status: Completed\n");
                                break;
                        }
                    }
                }
                break;

            case 3:
                if (count == 0) {
                    printf("No records for report.\n");
                } else {
                    int completed = 0;
                    int total = 0;
                    int highest = records[0].progress;
                    int lowest = records[0].progress;
                    float average;

                    for (i = 0; i < count; i++) {
                        total += records[i].progress;

                        if (records[i].status == COMPLETED) {
                            completed++;
                        }

                        if (records[i].progress > highest) {
                            highest = records[i].progress;
                        }

                        if (records[i].progress < lowest) {
                            lowest = records[i].progress;
                        }
                    }

                    average = (float) total / count;

                    printf("\n--- Report ---\n");
                    printf("Total records: %d\n", count);
                    printf("Completed: %d\n", completed);
                    printf("Average progress: %.2f\n", average);
                    printf("Highest progress: %d\n", highest);
                    printf("Lowest progress: %d\n", lowest);

                    if (average >= 80) {
                        printf("Overall result: Very good\n");
                    } else if (average >= 50) {
                        printf("Overall result: Good\n");
                    } else {
                        printf("Overall result: Needs improvement\n");
                    }
                }
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }
}
