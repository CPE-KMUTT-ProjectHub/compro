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
    if (file == NULL) 
    {
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

    for (int i = 0; i < numSubject; i++) 
    {
        printf("%s ", _product[i].Name);
        printf("%s ", _product[i].Brand);
        printf("%s ", _product[i].ProducType);
        printf("%d ", _product[i].AmountInStorage);
        printf("%.2lf ", _product[i].Price);
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
        printf("Please enter a passinitial: ");
        scanf("%s", psw);
        while (strcmp(psw, "12345a")!=0)
        {
            printf("Please enter the passinitial again.\n");
            scanf("%s", psw);
        }
        printf("Yeah! You are admin.\n");
        
    }
    if ( code == '1')
    {
        printf("Please enter a passinitial: ");
        scanf("%s", psw);
        while (strcmp(psw, "12345c")!=0)
        {
            printf("Please enter the passinitial again.\n");
            scanf("%s", psw);
        }
        printf("Yeah! You are cashier.\n");
    }
    
    return 0;
    
}


//ValidExpireDate function by 66070503438 Punyanuch Kajornchaikitti

char* ValidExpireDate(int day,int month,int year)
{
    char* expireDateinitial = (char*)malloc(11 * sizeof(char));
    int dayInMonth[]= {0,31,28,31,30,31,30,31,30,30,31,30,31};
    if ( month > 12 || month < 1 || day > 31 || day < 1)
    {
        printf("Invalid date, please enter Expire date again: ");
        scanf("%02d/%02d/%04d",&day,&month,&year);
        ValidExpireDate(day,month,year);
    }
    else if ( month == 2)
    {
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
            {
                    if ( day > 29)
                    {
                        printf("Invalid date, please enter Expire date again: ");
                        scanf("%02d/%02d/%04d",&day,&month,&year);
                        ValidExpireDate(day,month,year);
                    }
            }
            else if ( day > dayInMonth[month])
            {
                printf("Invalid date, please enter Expire date again: ");
                scanf("%02d/%02d/%04d",&day,&month,&year);
                ValidExpireDate(day,month,year);
            }
            else
            {
                sprintf(expireDateinitial, "%02d/%02d/%04d", day,month,year);
                return expireDateinitial;
            }      
    }
    else if (day <= dayInMonth[month])
    {
        sprintf(expireDateinitial, "%02d/%02d/%04d", day,month,year);
        return expireDateinitial;
    }
    
}

//LetterCheck function by 66070503438 Punyanuch Kajornchaikitti
int LetterCheck(char input[])
{
    int isLetter = 0;
    for ( int i = 0; input[i] != '\0'; i++)
    {
        if ( (input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z')  )
        {
            isLetter = 1;
        }
        else 
        {
            return -1;
        }
    }
    if ( isLetter == 1)
    {
        return 1;
    }
}

//NumberCheck function by 66070503438 Punyanuch Kajornchaikitti
int NumberCheck(char input[])
{
    for ( int i = 0; input[i] != '\0'; i++)
    {
        if (input[i] < '0' || input[i] > '9')
        {
            return -1;
        }
    }
    return atoi(input);
}

//PriceCheck function by 66070503438 Punyanuch Kajornchaikitti
int PriceCheck(char input[])
{
    int count = 0;
    for ( int i = 0; input[i] != '\0'; i++)
    {
        if (count > 1 )
        {
            return -1;
        }
        
        if ( input[i] == '.' )
        {
            count++;
        }
        else if (input[i] < '0' || input[i] > '9')
        {
           return -1;
        }
    }
    return atof(input);
}

//Create function by 66070503438 Punyanuch Kajornchaikitti
void create()
{
        char Name[1000];
        char Brand[1000];
        char ProductType[1000];
        char Price[1000];
        char Amount[1000];
        char day_initial[4];
        char month_initial[4];
        char year_initial[6];
        char* validExpireDate;
        int day,month,year;
        char amount_product_to_add_initial[10000];
        int amount_product_to_add;
        FILE *createptr = fopen("priceyCosmetics.csv","a");
        
        struct product product[1000];
        if ( createptr == NULL)
        {
            puts("could not open the file");
            exit(1);
        }

        printf("Enter amount of product you want to create: ");
        scanf("%s",amount_product_to_add_initial);
        while (NumberCheck(amount_product_to_add_initial) == -1 )
            {
                printf("Enter only integer(s): ");
                scanf("%s",amount_product_to_add_initial);
            }
        amount_product_to_add = NumberCheck(amount_product_to_add_initial);
        for ( int i = 0; i < amount_product_to_add ; i++)
        {
            printf("| Product number %d",i+1);

            printf("\nName: ");
            scanf("%s",Name);
            while (LetterCheck(Name) == -1 )
            {
                printf("Enter only letter(s): ");
                scanf("%s",Name);
            }
            strcpy(product[i].Name, Name);
            
            printf("Brand: ");
            scanf("%s",Brand);
            while (LetterCheck(Brand) == -1 )
            {
                printf("Enter only letter(s): ");
                scanf("%s",Brand);
            }
            strcpy(product[i].Brand, Brand);

            printf("Product Type: ");
            scanf("%s",ProductType);
            while (LetterCheck(ProductType) == -1 )
            {
                printf("Enter only letter(s): ");
                scanf("%s",ProductType);
            }
            strcpy(product[i].ProducType, ProductType);

            printf("Amount: ");
            scanf("%s",Amount);
            while (NumberCheck(Amount) == -1 )
            {
                printf("Enter only integer(s): ");
                scanf("%s",Amount);
            }
            product[i].AmountInStorage = NumberCheck(Amount);
            
            printf("Price: ");
            scanf("%s",Price);
            while (PriceCheck(Price) ==-1 )
            {
                printf("Enter only numbers: ");
                scanf("%s",Price);
            }
            product[i].Price = PriceCheck(Price);
            
            printf("Expire Date (DD/MM/YYYY): ");
            scanf("%02s/%02s/%04s",day_initial,month_initial,year_initial);
            while (NumberCheck(day_initial) == -1 || NumberCheck(month_initial) == -1 || NumberCheck(year_initial) == -1 )
            {
                printf("Please enter valid date: ");
                scanf("%02s/%02s/%04s",day_initial,month_initial,year_initial);
            }
            day = NumberCheck(day_initial);
            month = NumberCheck(month_initial);
            year = NumberCheck(year_initial);
            validExpireDate = ValidExpireDate(day,month,year);
            strcpy(product[i].ExpireDate,validExpireDate);
            printf("-----------------------------------\n");           
        }

        for ( int i = 0; i < amount_product_to_add ; i++)
        {
            fprintf(createptr,"%s,%s,%s,%d,%.2f,%s\n",product[i].Name,product[i].Brand,product[i].ProducType,product[i].AmountInStorage,product[i].Price,product[i].ExpireDate);       
        }

        printf("Completely add product(s)");

        fclose(createptr);
}


    


int main() {
    //login();
    create();
    //show();
    return 0;
}







