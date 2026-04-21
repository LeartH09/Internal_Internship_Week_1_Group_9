#include <stdio.h>
#include <string.h>

// 1. ENUM - Për statusin e detyrës
typedef enum {
    TODO = 1,
    IN_PROGRESS,
    DONE
} Status;

// 2. STRUCT - Për të ruajtur të dhënat (si zëvendësim për Class)
typedef struct {
    char titulli[50];
    Status statusi;
} Detyra;

// Prototipet e funksioneve
void shtoDetyre(Detyra lista[], int *count);
void shfaqDetyrat(Detyra lista[], int count);
const char* merrStatusinString(Status s);

int main() {
    Detyra listaDetyrave[100]; // Array për të ruajtur deri në 100 detyra
    int nrDetyrave = 0;
    int zgjedhja;
    char buffer[10];

    printf("--- SISTEMI I MENAXHIMIT (GJUHA C) ---\n");

    while (1) {
        printf("\nMENUJA KRYESORE:\n");
        printf("1. Shto Detyre\n");
        printf("2. Shfaq Detyrat\n");
        printf("0. Dil\n");
        printf("Zgjedhja juaj: ");

        // Validimi i input-it për menunë
        scanf("%s", buffer);
        zgjedhja = atoi(buffer); // Konverton string në int, kthen 0 nëse nuk është numër

        switch (zgjedhja) {
            case 1:
                shtoDetyre(listaDetyrave, &nrDetyrave);
                break;
            case 2:
                shfaqDetyrat(listaDetyrave, nrDetyrave);
                break;
            case 0:
                printf("Duke u mbyllur...\n");
                return 0;
            default:
                printf(" Gabim: Zgjedhje e pavlefshme! Provo 0, 1 ose 2.\n");
        }
    }

    return 0;
}

// Funksioni për të shtuar një detyrë
void shtoDetyre(Detyra lista[], int *count) {
    printf("\nShkruani titullin e detyres: ");
    scanf(" %[^\n]s", lista[*count].titulli); // Lexon stringun me hapësira

    int statusZgjedhja = 0;
    
    // Validim i fortë për statusin (Enum)
    while (statusZgjedhja < 1 || statusZgjedhja > 3) {
        printf("Zgjidhni Statusin (1: TODO, 2: IN PROGRESS, 3: DONE): ");
        char statusBuffer[10];
        scanf("%s", statusBuffer);
        statusZgjedhja = atoi(statusBuffer);

        if (statusZgjedhja >= 1 && statusZgjedhja <= 3) {
            lista[*count].statusi = (Status)statusZgjedhja;
        } else {
            printf(" Gabim: Ju lutem zgjidhni nje nga numrat 1, 2 ose 3.\n");
        }
    }

    (*count)++;
    printf(" Detyra u shtua me sukses!\n");
}

// Funksioni për të listuar detyrat
void shfaqDetyrat(Detyra lista[], int count) {
    if (count == 0) {
        printf("\nNuk ka asnje regjistrim.\n");
        return;
    }

    printf("\n--- LISTA E REGJISTRIMEVE ---\n");
    for (int i = 0; i < count; i++) {
        printf("%d. [%-12s] %s\n", i + 1, merrStatusinString(lista[i].statusi), lista[i].titulli);
    }
}

// Funksion ndihmës për të kthyer Enum-in në tekst
const char* merrStatusinString(Status s) {
    switch (s) {
        case TODO: return "TO DO";
        case IN_PROGRESS: return "IN PROGRESS";
        case DONE: return "DONE";
        default: return "UNKNOWN";
    }
}
