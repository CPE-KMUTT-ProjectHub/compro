#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE 100
#define MAX 100

struct list
{
    char code[MAX];
    char username[MAX];
    char password[MAX];

};

void readfile(const char *filename, struct list *list, int *count)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        perror("Can Not Open The File");
        exit(EXIT_FAILURE);
    }

    char line[LINE];
    *count = 0;

    while (fgets(line, sizeof(line), file) != NULL)
    {
        char *token = strtok(line, ",");
        
        strncpy(list[*count].code, token, MAX - 1);
        list[*count].code[MAX - 1] = '\0';

        token = strtok(NULL, ",");
        strncpy(list[*count].username, token, MAX - 1);
        list[*count].username[MAX - 1] = '\0';

        token = strtok(NULL, ",");
        strncpy(list[*count].password, token, MAX - 1);
        list[*count].password[MAX - 1] = '\0';

        (*count)++;
    }

    fclose(file);
}

int login()
{
    const char *filename = "UserList.csv";
    struct list list[100];
    int count;
    char input_username[MAX];
    char input_password[MAX];


    FILE *fpt;
    fpt = fopen("UserList.csv", "r");


    readfile(filename, list, &count);

    printf("Please enter username: ");
    scanf("%s", input_username);

    for (int i = 0; i < count; i++)
    {
        if(!strcmp(list[i].username,input_username))
        {
            printf("Please enter password: ");
            scanf("%s", input_password);
            while(strcmp(list[i].password,input_password)!=0){
                printf("Error please enter password agian: ");
                scanf("%s", input_password);
            }
            if(strcmp(list[i].password,input_password)==0)
            {
                printf("Yeah! Log in successfully.\n");
                if(strcmp(list[i].code,"0") == 0){
                    return 2;
                }
                if(strcmp(list[i].code,"1") == 0){
                    return 1;
                }
            }
            
        }
    }
    fclose(fpt);

    return 0;
}
