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

    printf("Statusi:\n");
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
        printf("Nuk ka te dhena.\n");
        return;
    }

    printf("\n===== LISTA E STUDENTEVE =====\n");
    for (i = 0; i < count; i++) {
        printf("Indeksi: %d\n", i);
        printf("ID: %d\n", students[i].id);
        printf("Emri: %s\n", students[i].name);
        printf("Progresi: %d\n", students[i].progress);
        printf("Statusi: ");
        printStatus(students[i].status);
        printf("\n-----------------------------\n");
    }
}

void showReport() {
    int i;
    int sum = 0;
    int max = 0;
    int completed = 0;
    float avg;

    if (count == 0) {
        printf("Nuk ka te dhena.\n");
        return;
    }

    for (i = 0; i < count; i++) {
        sum += students[i].progress;

        if (students[i].progress > max) {
            max = students[i].progress;
        }

        if (students[i].status == COMPLETED) {
            completed++;
        }
    }

    avg = (float)sum / count;

    printf("\n===== RAPORT ANALITIK =====\n");
    printf("Numri total: %d\n", count);
    printf("Te perfunduar: %d\n", completed);
    printf("Mesatarja: %.2f\n", avg);
    printf("Progresi maksimal: %d\n", max);

    if (avg >= 80) {
        printf("Performanca: Shume e mire\n");
    } else if (avg >= 50) {
        printf("Performanca: Mesatare\n");
    } else {
        printf("Performanca: E ulet\n");
    }
}

void updateStudent() {
    int id, i;
    int found = 0;
    int statusChoice;
    Student *s;

    printf("Shkruaj ID e studentit per update: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++) {
        if (students[i].id == id) {
            found = 1;
            s = &students[i];

            printf("Studenti u gjet: %s\n", s->name);

            printf("Emri i ri: ");
            scanf(" %[^\n]", s->name);

            printf("Progresi i ri (0-100): ");
            scanf("%d", &s->progress);

            if (s->progress < 0 || s->progress > 100) {
                printf("Progres i pavlefshem.\n");
                return;
            }

            printf("Statusi i ri:\n");
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

            printf("\n===== STUDENTI U GJET =====\n");
            printf("ID: %d\n", students[i].id);
            printf("Emri: %s\n", students[i].name);
            printf("Progresi: %d\n", students[i].progress);
            printf("Statusi: ");
            printStatus(students[i].status);
            printf("\n");

            if (students[i].progress < 50 && students[i].status != COMPLETED) {
                printf("Paralajmerim: Progres i ulet, duhet me shume pune!\n");
            } else if (students[i].progress >= 50 && students[i].progress < 80) {
                printf("Rekomandim: Vazhdoni keshtu.\n");
            } else if (students[i].progress >= 80) {
                printf("Shkelqyeshem: Performance shume e mire!\n");
            }

            return;
        }
    }

    if (!found) {
        printf("Asnje student nuk u gjet.\n");
    }
}

void sortStudents() {
    int i, j;
    Student temp;

    if (count == 0) {
        printf("Nuk ka te dhena.\n");
        return;
    }

    for (i = 0; i < count - 1; i++) {
        for (j = i + 1; j < count; j++) {
            if (students[i].progress < students[j].progress) {
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }

    printf("\n===== RENDITJA SIPAS PROGRESIT =====\n");
    for (i = 0; i < count; i++) {
        printf("%d. %s - %d%% - ", i + 1, students[i].name, students[i].progress);
        printStatus(students[i].status);
        printf("\n");
    }
}

void deleteStudent() {
    int id, i, j;
    int found = 0;

    if (count == 0) {
        printf("Nuk ka te dhena per fshirje.\n");
        return;
    }

    printf("Shkruaj ID e studentit per fshirje: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++) {
        if (students[i].id == id) {
            found = 1;

            for (j = i; j < count - 1; j++) {
                students[j] = students[j + 1];
            }

            count--;
            printf("Studenti u fshi me sukses.\n");
            return;
        }
    }

    if (!found) {
        printf("Studenti nuk u gjet.\n");
    }
}

int main() {
    int choice;

    do {
        printf("\n===== STUDENT PROGRESS TRACKER =====\n");
        printf("1. Shto regjistrim\n");
        printf("2. Shfaq regjistrimet\n");
        printf("3. Raport analitik\n");
        printf("4. Perditeso student\n");
        printf("5. Kerko student\n");
        printf("6. Rendit studentet\n");
        printf("7. Fshi student\n");
        printf("8. Dil\n");
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
                sortStudents();
                break;
            case 7:
                deleteStudent();
                break;
            case 8:
                printf("Programi u mbyll.\n");
                break;
            default:
                printf("Zgjedhje e pavlefshme.\n");
        }

    } while (choice != 8);

    return 0;
}