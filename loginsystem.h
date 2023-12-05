// This is a login system function (admin or cashier)  
// Chanya Kittichai 66070503412

#include <stdio.h>
#include <string.h>

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