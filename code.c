#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "UpdateAndDelete.h"
#include "loginsystem.h"
#include "readCSV.h"
#define MAX_LINE_SIZE 256
#define MAX_NAME_SIZE 100


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

    } if(Status == 2)  {

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