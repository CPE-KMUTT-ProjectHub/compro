#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 256
#define MAX_NAME_SIZE 100

struct product {
    char Name[MAX_NAME_SIZE];
    char Brand[MAX_NAME_SIZE];
    char ProducType[MAX_NAME_SIZE];
    int AmountInStorage;
    float Price;
    char ExpireDate[MAX_LINE_SIZE];
};

void readCSV(const char *filename, struct product *_product, int *numProduct) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_SIZE];
    *numProduct = 0;

    while (fgets(line, sizeof(line), file) != NULL) {
        char *token = strtok(line, ",");
        
        strncpy(_product[*numProduct].Name, token, MAX_NAME_SIZE - 1);
        _product[*numProduct].Name[MAX_NAME_SIZE - 1] = '\0';

        token = strtok(NULL, ",");
        strncpy(_product[*numProduct].Brand, token, MAX_NAME_SIZE - 1);
        _product[*numProduct].Brand[MAX_NAME_SIZE - 1] = '\0';

        token = strtok(NULL, ",");
        strncpy(_product[*numProduct].ProducType, token, MAX_NAME_SIZE - 1);
        _product[*numProduct].ProducType[MAX_NAME_SIZE - 1] = '\0';

        token = strtok(NULL, ",");
        sscanf(token, "%d", &_product[*numProduct].AmountInStorage);

        token = strtok(NULL, ",");
        sscanf(token, "%f", &_product[*numProduct].Price);

        token = strtok(NULL, ",");
        strncpy(_product[*numProduct].ExpireDate, token, MAX_NAME_SIZE - 1);
        _product[*numProduct].ExpireDate[MAX_NAME_SIZE - 1] = '\0';

        (*numProduct)++;
    }

    fclose(file);
}
void show(){
    const char *filename = "priceyCosmetics.csv";
    struct product _product[1000];
    int numSubject;
    FILE *fpt;
    readCSV(filename, _product, &numSubject);

    for (int i = 0; i < numSubject; i++) {
        printf("%s ", _product[i].Name);
        printf("%s ", _product[i].Brand);
        printf("%s ", _product[i].ProducType);
        printf("%d ", _product[i].AmountInStorage);
        printf("%.2f ", _product[i].Price);
        printf("%s", _product[i].ExpireDate);
        printf("\n");
    }
}

// This is a login system function (admin or cashier)  
// Chanya Kittichai 66070503412

int login()
{
    char code;
    printf("[0] Admin\n[1] Cashier\n[else] Exit\n");
    scanf("%c", &code);

    char psw[6];

    if ( code == '0')
    {
        printf("Please enter a password: ");
        scanf("%s", psw);
        while (strcmp(psw, "12345a")!=0)
        {
            printf("Please enter the password again.\n");
            scanf("%s", psw);
        }
        printf("Yeah! You are admin.\n");
        
    }
    if ( code == '1')
    {
        printf("Please enter a password: ");
        scanf("%s", psw);
        while (strcmp(psw, "12345c")!=0)
        {
            printf("Please enter the password again.\n");
            scanf("%s", psw);
        }
        printf("Yeah! You are cashier.\n");
    }
    
    return 0;
    
}


int main() {
    login();
    //show();
    return 0;
}
