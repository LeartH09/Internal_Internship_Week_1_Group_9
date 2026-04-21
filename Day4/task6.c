#include <stdio.h>
#include <string.h>

#define MAX 5

enum Status {
    NOT_STARTED = 1,
    IN_PROGRESS,
    COMPLETED
};

struct Record {
    int id;
    char name[50];
    int progress;
    enum Status status;
};

void updateProgress(int *progress) {
    *progress = *progress + 10;
    if (*progress > 100) {
        *progress = 100;
    }
}

int main() {
    struct Record records[MAX], temp;
    int count = 0;
    int choice, i, j;

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Add record\n");
        printf("2. Show records\n");
        printf("3. Show report\n");
        printf("4. Search by ID\n");
        printf("5. Update progress\n");
        printf("6. Rank records by progress\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int statusChoice;

                if (count == MAX) {
                    printf("Maximum records reached.\n");
                    break;
                }

                printf("Enter ID: ");
                scanf("%d", &records[count].id);

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
                        printf("ID: %d\n", records[i].id);
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

                    printf("\n--- REPORT ---\n");
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

            case 4: {
                int searchId;
                int found = 0;

                if (count == 0) {
                    printf("No records available.\n");
                    break;
                }

                printf("Enter ID to search: ");
                scanf("%d", &searchId);

                for (i = 0; i < count; i++) {
                    if (records[i].id == searchId) {
                        found = 1;

                        printf("\n--- RECORD FOUND ---\n");
                        printf("ID: %d\n", records[i].id);
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

                        printf("--- MESSAGE ---\n");

                        if (records[i].progress < 50 && records[i].status == NOT_STARTED) {
                            printf("Warning: Low progress and task not started.\n");
                        } else if (records[i].progress < 50 && records[i].status == IN_PROGRESS) {
                            printf("Recommendation: More work is needed.\n");
                        } else if (records[i].progress >= 80 && records[i].status == COMPLETED) {
                            printf("Excellent: Record is in very good condition.\n");
                        } else if (records[i].progress >= 50 && records[i].status == IN_PROGRESS) {
                            printf("Good: Progress is moving in the right direction.\n");
                        } else {
                            printf("Status is acceptable, but keep monitoring progress.\n");
                        }

                        break;
                    }
                }

                if (found == 0) {
                    printf("No matching record found.\n");
                }

                break;
            }

            case 5: {
                int updateId;
                int found = 0;

                if (count == 0) {
                    printf("No records available.\n");
                    break;
                }

                printf("Enter ID to update progress: ");
                scanf("%d", &updateId);

                for (i = 0; i < count; i++) {
                    if (records[i].id == updateId) {
                        found = 1;

                        printf("Progress before update: %d\n", records[i].progress);
                        updateProgress(&records[i].progress);
                        printf("Progress after update: %d\n", records[i].progress);
                        break;
                    }
                }

                if (found == 0) {
                    printf("Record not found.\n");
                }

                break;
            }

            case 6:
                if (count == 0) {
                    printf("No records to rank.\n");
                } else {
                    for (i = 0; i < count - 1; i++) {
                        for (j = i + 1; j < count; j++) {
                            if (records[j].progress > records[i].progress) {
                                temp = records[i];
                                records[i] = records[j];
                                records[j] = temp;
                            }
                        }
                    }

                    printf("\n--- RANKING BY PROGRESS ---\n");
                    for (i = 0; i < count; i++) {
                        printf("Rank %d\n", i + 1);
                        printf("ID: %d\n", records[i].id);
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
                        printf("-------------------\n");
                    }
                }
                break;

            case 7:
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }
}
