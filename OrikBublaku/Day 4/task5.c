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
        case NOT_STARTED:
            printf("Not Started");
            break;
        case IN_PROGRESS:
            printf("In Progress");
            break;
        case COMPLETED:
            printf("Completed");
            break;
        default:
            printf("Unknown");
    }
}

void addStudent() {
    int statusChoice;

    if (count >= MAX_STUDENTS) {
        printf("Lista eshte e mbushur. Nuk mund te shtoni me shume regjistrime.\n");
        return;
    }

    printf("Shkruaj ID: ");
    scanf("%d", &students[count].id);

    printf("Shkruaj emrin: ");
    scanf(" %[^\n]", students[count].name);

    printf("Shkruaj progresin (0 - 100): ");
    scanf("%d", &students[count].progress);

    if (students[count].progress < 0 || students[count].progress > 100) {
        printf("Progres i pavlefshem. Duhet te jete nga 0 deri ne 100.\n");
        return;
    }

    printf("Zgjidh statusin:\n");
    printf("1. Not Started\n");
    printf("2. In Progress\n");
    printf("3. Completed\n");
    printf("Zgjedhja: ");
    scanf("%d", &statusChoice);

    switch (statusChoice) {
        case 1:
            students[count].status = NOT_STARTED;
            break;
        case 2:
            students[count].status = IN_PROGRESS;
            break;
        case 3:
            students[count].status = COMPLETED;
            break;
        default:
            printf("Status i pavlefshem.\n");
            return;
    }

    count++;
    printf("Regjistrimi u shtua me sukses.\n");
}

void showStudents() {
    int i;

    if (count == 0) {
        printf("Nuk ka regjistrime per te shfaqur.\n");
        return;
    }

    printf("\n--- Lista e Studenteve ---\n");
    for (i = 0; i < count; i++) {
        printf("ID: %d\n", students[i].id);
        printf("Emri: %s\n", students[i].name);
        printf("Progresi: %d\n", students[i].progress);
        printf("Statusi: ");
        printStatus(students[i].status);
        printf("\n--------------------------\n");
    }
}

void showReport() {
    int i;
    int total = count;
    int completed = 0;
    int sumProgress = 0;
    int maxProgress = 0;

    if (count == 0) {
        printf("Nuk ka te dhena per raport.\n");
        return;
    }

    for (i = 0; i < count; i++) {
        sumProgress += students[i].progress;

        if (students[i].status == COMPLETED) {
            completed++;
        }

        if (students[i].progress > maxProgress) {
            maxProgress = students[i].progress;
        }
    }

    float average = (float)sumProgress / count;

    printf("\n===== RAPORT ANALITIK =====\n");
    printf("Numri total i studenteve: %d\n", total);
    printf("Te perfunduar: %d\n", completed);
    printf("Mesatarja e progresit: %.2f\n", average);
    printf("Progresi maksimal: %d\n", maxProgress);

    if (average >= 80) {
        printf("Performanca: Shume e mire\n");
    } else if (average >= 50) {
        printf("Performanca: Mesatare\n");
    } else {
        printf("Performanca: E ulet\n");
    }

    printf("===========================\n");
}

void updateStudent() {
    int id, i;
    int found = 0;
    int statusChoice;

    printf("Shkruaj ID e studentit per update: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++) {
        if (students[i].id == id) {
            found = 1;

            Student *s = &students[i];

            printf("Studenti u gjet: %s\n", s->name);

            printf("Shkruaj progres te ri (0 - 100): ");
            scanf("%d", &s->progress);

            if (s->progress < 0 || s->progress > 100) {
                printf("Progres i pavlefshem.\n");
                return;
            }

            printf("Zgjidh status te ri:\n");
            printf("1. Not Started\n");
            printf("2. In Progress\n");
            printf("3. Completed\n");
            printf("Zgjedhja: ");
            scanf("%d", &statusChoice);

            switch (statusChoice) {
                case 1:
                    s->status = NOT_STARTED;
                    break;
                case 2:
                    s->status = IN_PROGRESS;
                    break;
                case 3:
                    s->status = COMPLETED;
                    break;
                default:
                    printf("Status i pavlefshem.\n");
                    return;
            }

            printf("Te dhenat u perditesuan me sukses.\n");
            return;
        }
    }

    if (!found) {
        printf("Studenti nuk u gjet.\n");
    }
}

void searchStudent() {
    int id, i;
    int found = 0;

    printf("Shkruaj ID per kerkim: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++) {
        if (students[i].id == id) {
            found = 1;

            printf("\n--- Studenti u gjet ---\n");
            printf("ID: %d\n", students[i].id);
            printf("Emri: %s\n", students[i].name);
            printf("Progresi: %d\n", students[i].progress);
            printf("Statusi: ");
            printStatus(students[i].status);
            printf("\n");

            if (students[i].progress < 50 && students[i].status != COMPLETED) {
                printf("Paralajmerim: Progres i ulet, duhet me shume pune!\n");
            } else if (students[i].progress >= 50 && students[i].progress < 80) {
                printf("Rekomandim: Vazhdoni keshtu, jeni ne rruge te mire.\n");
            } else if (students[i].progress >= 80) {
                printf("Shkelqyeshem: Performance shume e mire!\n");
            }

            printf("------------------------\n");
            return;
        }
    }

    if (!found) {
        printf("Asnje student nuk u gjet.\n");
    }
}

int main() {
    int choice;

    do {
        printf("\n===== Student Progress Tracker =====\n");
        printf("1. Shto regjistrim\n");
        printf("2. Shfaq regjistrimet\n");
        printf("3. Raport analitik\n");
        printf("4. Perditeso student\n");
        printf("5. Kerko student\n");
        printf("6. Dil\n");
        printf("Zgjedh nje opsion: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                showStudents();
                break;
            case 3:
                showReport();
                break;
            case 4:
                updateStudent();
                break;
            case 5:
                searchStudent();
                break;
            case 6:
                printf("Programi u mbyll.\n");
                break;
            default:
                printf("Zgjedhje e pavlefshme. Provo perseri.\n");
        }

    } while (choice != 6);

    return 0;
}