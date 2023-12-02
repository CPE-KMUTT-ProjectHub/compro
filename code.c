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

int delete(const char *filename, int i, int Status) {
    
    int Validity = 0, DeleteOrNot;

        while (!Validity) {
            printf("Press 0 to exit delete mode and press 1 to delete: ");

            if (scanf("%d", &DeleteOrNot) == 1 && DeleteOrNot == 0 || DeleteOrNot == 1) {
                Validity = 1;
            } else {
                
                while (getchar() != '\n');

                printf("You can only input either 0 or 1. Try again.\n");
            }

        }

        if (DeleteOrNot == 0) {

            return 1;

        } else {
            // Delete a row from a CSV file
            FILE *inputFile = fopen(filename, "r");
            FILE *outputFile = fopen("temp.csv", "w");

            if (inputFile == NULL || outputFile == NULL) {
                perror("Error opening files");
                exit(EXIT_FAILURE);
            }

            char line[MAX_LINE_SIZE];
            int currentRow = 0;

            while (fgets(line, sizeof(line), inputFile) != NULL) {
                if (currentRow != i + 1) {
                    fputs(line, outputFile);
                }
                currentRow++;
            }

            fclose(inputFile);
            fclose(outputFile);

            // Rename the temporary file to the original file
            remove(filename);
            rename("temp.csv", filename);
        

            printf("Deleted.\n");
        }
               
    }

void UpdateFile(int Num, struct product Product[]) {
    FILE *File = fopen("priceyCosmetics.csv", "w");
    int i;

    if (File == NULL) {
        perror("Error opening file.");
        exit(EXIT_FAILURE);
    }

    fprintf(File, "Name,Brand,ProductType,AmountInStorage,Price,ExpireDate\n");

    for (i = 0; i < Num; i++) {
        fprintf(File, "%s,%s,%s,%d,%.2f,%s", Product[i].Name, Product[i].Brand, Product[i].ProducType, Product[i].AmountInStorage, Product[i].Price, Product[i].ExpireDate);
    }

    fclose(File);
}

void UpdateStruct(struct product Product[], int Status, int i) {
    int Validity = 0, WhatToEdit, EditOrExit;

    if (Status == 1) {

        while (!Validity) {
            printf("Input the number corresponding to data you want to edit: ");

            if (scanf("%d", &WhatToEdit) != 1) {

                while (getchar() != '\n');

                printf("Invalid input. Input again.\n");
                continue;
            }

            if (WhatToEdit == 1) {

                while (getchar() != '\n');

                Validity = 1;
                printf("New name: ");
                scanf("%[^\n]", Product[i].Name);
            } else if (WhatToEdit == 2) {
                
                while (getchar() != '\n');

                Validity = 1;
                printf("New brand: ");
                scanf("%[^\n]", Product[i].Brand);
            } else if (WhatToEdit == 3) {
                
                while (getchar() != '\n');

                Validity = 1;
                printf("New type: ");
                scanf("%[^\n]", Product[i].ProducType);
            } else if (WhatToEdit == 4) {

                while (!Validity) {
                    printf("New quantity: ");

                    if (scanf("%d", &Product[i].AmountInStorage) == 1) {
                        Validity = 1;
                    } else {
                        
                        while (getchar() != '\n');

                        printf("You can only input an integer. Input again.\n");
                    }

                }

            } else if (WhatToEdit == 5) {
                
                while (!Validity) {
                    printf("New price: ");

                    if (scanf("%f", &Product[i].Price) == 1) {
                        Validity = 1;
                    } else {
                        
                        while (getchar() != '\n');

                        printf("You can only input a float number. Input again.\n");
                    }

                }

            } else if (WhatToEdit == 6) {
                
                while (getchar() != '\n');

                Validity = 1;
                printf("New expire: ");
                scanf("%[^\n]", Product[i].ExpireDate);
            } else {

                while (getchar() != '\n');

                printf("Invalid input. Input again.\n");
            }

        }

        Validity = 0;

        while (!Validity) {
            printf("Data was processed successfully. Press 0 to exit the editing mode and 1 to continue editing: ");

            if (scanf("%d", &EditOrExit) == 1 && EditOrExit == 0 || EditOrExit == 1) {
                Validity = 1;
            } else {
                
                while (getchar() != '\n');

                printf("You can only input either 0 or 1. Try again.\n");
            }

        }

        if (EditOrExit == 1) {

            UpdateStruct(Product, Status, i);

        }

    } else {

        while (!Validity) {
            printf("New quantity: ");

            if (scanf("%d", &Product[i].AmountInStorage) == 1) {
                Validity = 1;
            } else {
                
                while (getchar() != '\n');

                printf("You can only input an integer. Input again.\n");
            }

        }

        printf("Data was processed successfully.\n");
    }
}

int Update(int Status, int Num, struct product Product[], const char *filename) {
    char ProductName[MAX_NAME_SIZE];
    int NextOrEdit, i;

    while (getchar() != '\n');

    printf("Which product do you wish to edit its data: ");
    scanf("%[^\n]", ProductName);

    for (i = 0; i < Num; i++) {
        int Validity = 0;

        if (strstr(Product[i].Name, ProductName) != NULL) {
            printf("Found a result.\n");
            printf("1: Name: %s\n", Product[i].Name);
            printf("2: Brand: %s\n", Product[i].Brand);
            printf("3: Type: %s\n", Product[i].ProducType);
            printf("4: Quantity: %d\n", Product[i].AmountInStorage);
            printf("5: Price: %.2f\n", Product[i].Price);
            printf("6: Expire: %s", Product[i].ExpireDate);

            while (!Validity) {
                int BackFromDelete = 0;
                printf("Press 0 to view the next result, 1 to edit this result, and 2 to delete this result: ");

                if (scanf("%d", &NextOrEdit) == 1 && NextOrEdit == 0 || NextOrEdit == 1 || NextOrEdit == 2) {

                    if (NextOrEdit == 2) {

                        if (Status == 1) {
                            BackFromDelete = delete(filename, i, Status);

                            if (BackFromDelete == 0) {
                                Validity = 1;
                            }

                        } else {
                            printf("Only the admin can delete.\n");
                        }

                    } else {
                        Validity = 1;
                    }

                } else {

                    while (getchar() != '\n');

                    printf("You can only input 0, 1, or 2. Try again.\n");
                }

            }

            if (NextOrEdit == 0) {

                while (getchar() != '\n');

                continue;
            } else if (NextOrEdit == 1) {

                UpdateStruct(Product, Status, i);

                UpdateFile(Num, Product);

                Validity = 0;
                NextOrEdit = 2;

                while (!Validity) {
                    printf("Data updated successfully. Press 0 to exit and 1 to view the next result: ");

                    if (scanf("%d", &NextOrEdit) == 1 && NextOrEdit == 0 || NextOrEdit == 1) {
                        Validity = 1;
                    } else {

                        while (getchar() != '\n');

                        printf("You can only input either 0 or 1. Try again.\n");
                    }

                }

                if (NextOrEdit == 0) {

                    return 0;

                } else {

                    while (getchar() != '\n');

                    continue;
                }

            }

        }

    }

}

void show(int Status){
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

    Update(Status, numSubject, _product, filename);

}

int main() {
    int Validity = 0, Input, Status;
    Status = login();

    if (Status == 1 || Status == 2) {

        while (!Validity) {
            printf("Input 7 to call the update function: ");

            if (scanf("%d", &Input) == 1 && Input == 7) {
                Validity = 1;

                show(Status);

            } else {
                
                while (getchar() != '\n');

                printf("You can only input 7. Input again\n");
            }

        }

    }

    //show();
    return 0;
}
