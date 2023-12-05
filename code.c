#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "UpdateAndDelete.h"

#define MAX_LINE_SIZE 256
#define MAX_NAME_SIZE 100

void readCSV(const char *filename, struct product *_product, int *numProduct) {
    FILE *file = fopen(filename, "r");
    int Flag = 0;
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_SIZE];
    *numProduct = 0;

    while (fgets(line, sizeof(line), file) != NULL) {

        if (Flag == 1) {
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

        Flag = 1;
        //The Flag variable is used to prevent the program from copying the first line in the file into the strings.
    }

    fclose(file);
}

void show(int Status, int Flag){
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

    if (Flag == 1) {
        Update(Status, numSubject, _product, filename);
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
        
        return 1;

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

        return 2;

    }
    
    return 0;
    
}

int main() {
    int Validity = 0, Input, Status;
    Status = login();
    
    if (Status == 1) {

        while (!Validity) {
            printf("Show all products: Press 0\n");
            printf("Create product(s): Press 1\n");
            printf("Update or delete product(s): Press 2\n");
            printf("Logout and exit: Press 3\n");
            printf("Choose what to do: ");

            if (scanf("%d", &Input) == 1 && Input == 0 || Input == 1 || Input == 2 || Input == 3) {

                if (Input == 0) {

                    show(Status, 0);

                } else if (Input == 1) {

                    create();

                } else if (Input == 2) {

                    show(Status, 1);

                } else {

                    return 0;

                }

            } else {
                
                while (getchar() != '\n');

                printf("You can only input 0, 1, or 2. Input again\n");
            }

        }

    } else {

        while (!Validity) {
            printf("Show all products: Press 0\n");
            printf("Update or delete product(s): Press 1\n");
            printf("Logout and exit: Press 2\n");
            printf("Choose what to do: ");

            if (scanf("%d", &Input) == 1 && Input == 0 || Input == 1 || Input == 2) {

                if (Input == 0) {

                    show(Status, 0);

                } else if (Input == 1) {

                    show(Status, 1);

                } else {

                    return 0;

                }

            } else {
                
                while (getchar() != '\n');

                printf("You can only input 0 or 1. Input again\n");
                printf("You can only input 0 or 1. Input again\n");
            }

        }

    }

    return 0;

}