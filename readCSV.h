#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
        printf("%s |", _product[i].Name);
        printf(" %s |", _product[i].Brand);
        printf(" %s |", _product[i].ProducType);
        printf(" %d |", _product[i].AmountInStorage);
        printf(" %.2f |", _product[i].Price);
        printf(" %s", _product[i].ExpireDate);
        printf("\n");
    }

    if (Flag == 1) {
        Update(Status, numSubject, _product, filename);
    }

}