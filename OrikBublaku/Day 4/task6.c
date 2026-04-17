#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 5

typedef enum {
    NOT_STARTED = 1,
    IN_PROGRESS = 2,
    COMPLETED = 3
} Status;

typedef struct {
    int id;
    char name[50];
    int progress;
    Status status;
} Student;

Student students[MAX_STUDENTS];
int count = 0;

void printStatus(Status status) {
    switch (status) {
        case NOT_STARTED: printf("Not Started"); break;
        case IN_PROGRESS: printf("In Progress"); break;
        case COMPLETED: printf("Completed"); break;
        default: printf("Unknown");
    }
}

void addStudent() {
    int statusChoice;

    if (count >= MAX_STUDENTS) {
        printf("Lista eshte e mbushur.\n");
        return;
    }

    printf("ID: ");
    scanf("%d", &students[count].id);

    printf("Emri: ");
    scanf(" %[^\n]", students[count].name);

    printf("Progresi (0-100): ");
    scanf("%d", &students[count].progress);

    if (students[count].progress < 0 || students[count].progress > 100) {
        printf("Progres i pavlefshem.\n");
        return;
    }

    printf("Status (1-3): ");
    scanf("%d", &statusChoice);

    switch (statusChoice) {
        case 1: students[count].status = NOT_STARTED; break;
        case 2: students[count].status = IN_PROGRESS; break;
        case 3: students[count].status = COMPLETED; break;
        default: printf("Status i pavlefshem.\n"); return;
    }

    count++;
    printf("U shtua me sukses.\n");
}

void showStudents() {
    if (count == 0) {
        printf("Nuk ka te dhena.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        printf("\nID: %d\nEmri: %s\nProgresi: %d\nStatusi: ",
               students[i].id, students[i].name, students[i].progress);
        printStatus(students[i].status);
        printf("\n");
    }
}

void showReport() {
    if (count == 0) {
        printf("Nuk ka te dhena.\n");
        return;
    }

    int sum = 0, max = 0, completed = 0;

    for (int i = 0; i < count; i++) {
        sum += students[i].progress;
        if (students[i].progress > max) max = students[i].progress;
        if (students[i].status == COMPLETED) completed++;
    }

    float avg = (float)sum / count;

    printf("\nTotal: %d\nCompleted: %d\nAverage: %.2f\nMax: %d\n",
           count, completed, avg, max);
}

void updateStudent() {
    int id;
    printf("ID per update: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            Student *s = &students[i];

            printf("Progres i ri: ");
            scanf("%d", &s->progress);

            if (s->progress < 0 || s->progress > 100) {
                printf("Invalid.\n");
                return;
            }

            int st;
            printf("Status (1-3): ");
            scanf("%d", &st);

            if (st == 1) s->status = NOT_STARTED;
            else if (st == 2) s->status = IN_PROGRESS;
            else if (st == 3) s->status = COMPLETED;
            else {
                printf("Invalid.\n");
                return;
            }

            printf("Updated.\n");
            return;
        }
    }

    printf("Nuk u gjet.\n");
}

void searchStudent() {
    int id;
    printf("ID per kerkim: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {

            printf("\n%s - %d%%\n", students[i].name, students[i].progress);

            if (students[i].progress < 50)
                printf("Dobet.\n");
            else if (students[i].progress < 80)
                printf("Mesatare.\n");
            else
                printf("Shkelqyeshem.\n");

            return;
        }
    }

    printf("Nuk u gjet.\n");
}

void sortStudents() {
    if (count == 0) {
        printf("Nuk ka te dhena.\n");
        return;
    }

    Student temp;

    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (students[i].progress < students[j].progress) {
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }

    printf("\nRenditja:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s (%d%%)\n", i + 1,
               students[i].name, students[i].progress);
    }
}

int main() {
    int choice;

    do {
        printf("\n1.Add\n2.Show\n3.Report\n4.Update\n5.Search\n6.Sort\n7.Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: showStudents(); break;
            case 3: showReport(); break;
            case 4: updateStudent(); break;
            case 5: searchStudent(); break;
            case 6: sortStudents(); break;
            case 7: printf("Bye\n"); break;
            default: printf("Invalid\n");
        }

    } while (choice != 7);

    return 0;
}