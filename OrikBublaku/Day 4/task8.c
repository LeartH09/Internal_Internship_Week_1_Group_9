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

/* -------------------- Helper Functions -------------------- */

void printLine() {
    printf("========================================\n");
}

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

int isValidProgress(int progress) {
    return progress >= 0 && progress <= 100;
}

Status chooseStatus() {
    int choice;

    printf("Zgjidh statusin:\n");
    printf("1. Not Started\n");
    printf("2. In Progress\n");
    printf("3. Completed\n");
    printf("Zgjedhja: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            return NOT_STARTED;
        case 2:
            return IN_PROGRESS;
        case 3:
            return COMPLETED;
        default:
            return 0;
    }
}

void printStudent(Student s, int index) {
    printf("Indeksi : %d\n", index);
    printf("ID      : %d\n", s.id);
    printf("Emri    : %s\n", s.name);
    printf("Progres : %d\n", s.progress);
    printf("Statusi : ");
    printStatus(s.status);
    printf("\n");
}

int findStudentIndexById(int id) {
    int i;

    for (i = 0; i < count; i++) {
        if (students[i].id == id) {
            return i;
        }
    }

    return -1;
}

/* -------------------- Main Functionalities -------------------- */

void addStudent() {
    Status newStatus;

    if (count >= MAX_STUDENTS) {
        printf("Lista eshte e mbushur. Nuk mund te shtoni me shume regjistrime.\n");
        return;
    }

    printLine();
    printf("SHTO STUDENT\n");
    printLine();

    printf("Shkruaj ID: ");
    scanf("%d", &students[count].id);

    printf("Shkruaj emrin: ");
    scanf(" %[^\n]", students[count].name);

    printf("Shkruaj progresin (0-100): ");
    scanf("%d", &students[count].progress);

    if (!isValidProgress(students[count].progress)) {
        printf("Progres i pavlefshem. Duhet te jete nga 0 deri ne 100.\n");
        return;
    }

    newStatus = chooseStatus();

    if (newStatus == 0) {
        printf("Status i pavlefshem.\n");
        return;
    }

    students[count].status = newStatus;
    count++;

    printf("Regjistrimi u shtua me sukses.\n");
}

void showStudents() {
    int i;

    if (count == 0) {
        printf("Nuk ka regjistrime per te shfaqur.\n");
        return;
    }

    printLine();
    printf("LISTA E STUDENTEVE\n");
    printLine();

    for (i = 0; i < count; i++) {
        printStudent(students[i], i);
        printLine();
    }
}

void showReport() {
    int i;
    int completed = 0;
    int sum = 0;
    int max = students[0].progress;
    float average;

    if (count == 0) {
        printf("Nuk ka te dhena per raport.\n");
        return;
    }

    for (i = 0; i < count; i++) {
        sum += students[i].progress;

        if (students[i].status == COMPLETED) {
            completed++;
        }

        if (students[i].progress > max) {
            max = students[i].progress;
        }
    }

    average = (float)sum / count;

    printLine();
    printf("RAPORT ANALITIK\n");
    printLine();
    printf("Numri total i studenteve : %d\n", count);
    printf("Te perfunduar            : %d\n", completed);
    printf("Mesatarja e progresit    : %.2f\n", average);
    printf("Progresi maksimal        : %d\n", max);

    if (average >= 80) {
        printf("Vleresimi                : Shume e mire\n");
    } else if (average >= 50) {
        printf("Vleresimi                : Mesatare\n");
    } else {
        printf("Vleresimi                : E ulet\n");
    }

    printLine();
}

void updateStudent() {
    int id;
    int index;
    Student *s;
    Status newStatus;

    if (count == 0) {
        printf("Nuk ka te dhena per perditesim.\n");
        return;
    }

    printLine();
    printf("PERDITESO STUDENT\n");
    printLine();

    printf("Shkruaj ID e studentit: ");
    scanf("%d", &id);

    index = findStudentIndexById(id);

    if (index == -1) {
        printf("Studenti nuk u gjet.\n");
        return;
    }

    s = &students[index];

    printf("Studenti u gjet: %s\n", s->name);

    printf("Shkruaj emrin e ri: ");
    scanf(" %[^\n]", s->name);

    printf("Shkruaj progresin e ri (0-100): ");
    scanf("%d", &s->progress);

    if (!isValidProgress(s->progress)) {
        printf("Progres i pavlefshem.\n");
        return;
    }

    newStatus = chooseStatus();

    if (newStatus == 0) {
        printf("Status i pavlefshem.\n");
        return;
    }

    s->status = newStatus;

    printf("Te dhenat u perditesuan me sukses.\n");
}

void searchStudent() {
    int id;
    int index;

    if (count == 0) {
        printf("Nuk ka te dhena per kerkim.\n");
        return;
    }

    printLine();
    printf("KERKO STUDENT\n");
    printLine();

    printf("Shkruaj ID per kerkim: ");
    scanf("%d", &id);

    index = findStudentIndexById(id);

    if (index == -1) {
        printf("Asnje student nuk u gjet.\n");
        return;
    }

    printStudent(students[index], index);
    printLine();

    if (students[index].progress < 50 && students[index].status != COMPLETED) {
        printf("Paralajmerim: Progres i ulet, duhet me shume pune.\n");
    } else if (students[index].progress >= 50 && students[index].progress < 80) {
        printf("Rekomandim: Vazhdoni keshtu, jeni ne rruge te mire.\n");
    } else if (students[index].progress >= 80 && students[index].status == COMPLETED) {
        printf("Shkelqyeshem: Student me performance shume te mire.\n");
    } else {
        printf("Vleresim: Studenti ka progres normal.\n");
    }
}

void sortStudents() {
    int i, j;
    Student temp;

    if (count == 0) {
        printf("Nuk ka te dhena per renditje.\n");
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

    printLine();
    printf("RENDITJA SIPAS PROGRESIT\n");
    printLine();

    for (i = 0; i < count; i++) {
        printf("%d. %s - %d%% - ", i + 1, students[i].name, students[i].progress);
        printStatus(students[i].status);
        printf("\n");
    }

    printLine();
}

void deleteStudent() {
    int id;
    int index;
    int i;

    if (count == 0) {
        printf("Nuk ka te dhena per fshirje.\n");
        return;
    }

    printLine();
    printf("FSHI STUDENT\n");
    printLine();

    printf("Shkruaj ID e studentit per fshirje: ");
    scanf("%d", &id);

    index = findStudentIndexById(id);

    if (index == -1) {
        printf("Studenti nuk u gjet.\n");
        return;
    }

    for (i = index; i < count - 1; i++) {
        students[i] = students[i + 1];
    }

    count--;
    printf("Studenti u fshi me sukses.\n");
}

void showMenu() {
    printLine();
    printf("STUDENT PROGRESS TRACKER\n");
    printLine();
    printf("1. Shto regjistrim\n");
    printf("2. Shfaq regjistrimet\n");
    printf("3. Raport analitik\n");
    printf("4. Perditeso student\n");
    printf("5. Kerko student\n");
    printf("6. Rendit studentet\n");
    printf("7. Fshi student\n");
    printf("8. Dil\n");
    printLine();
    printf("Zgjedh nje opsion: ");
}

/* -------------------- Main -------------------- */

int main() {
    int choice;

    do {
        showMenu();
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
                printf("Zgjedhje e pavlefshme. Provo perseri.\n");
        }

    } while (choice != 8);

    return 0;
}