#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define bool int
#define true 1
#define false 0

int menu();
char* decimal_to_roman(int number);
int roman_to_decimal(char * roman);
void print_roman_list();
void help();
void clear_input();

int main()
{
    int number;
    char * romanNumber = (char *)malloc(64);
    bool loopControl = true;

    do
    {  
        switch (menu())
        {
            case 1:
                system("clear");
                printf("Please enter the number you want to convert: ");
                scanf("%d",&number);
                decimal_to_roman(number);
                break;
            case 2:
                system("clear");
                printf("Please enter the number you want to convert: ");
                scanf("%s",romanNumber);
                roman_to_decimal(romanNumber);
                break;
            case 3:
                print_roman_list();
                break;
            case 4:
                help();
                break;
            default:
                loopControl = false;
                break;
        }
        clear_input();
        getchar();
    }while(loopControl);

    return 0;
}

int menu(){
    int choice = 0;
    system("clear");
    do
    {
        printf("*****Welcome to Roman Numerals Converter!*****\n\n");
        printf("\t1. Convert Decimal to Roman\n");
        printf("\t2. Convert Roman to Decimal\n");
        printf("\t3. Print List of Roman up to 100\n");
        printf("\t4. Help\n");
        printf("\t5. Exit\n");
        printf("\n\tEnter the Number of your choice: ");
        scanf("%d",&choice);
    }while(choice < 1 || choice > 5);
    return choice;
}

char* decimal_to_roman(int number){
    if(number > 3999 || number < 1)
    {
        printf("ERROR: Number to large for conversion\n");
        printf("?Roman Numeral system only goes from 1 to 3999?\n");
        return NULL;
    }

    int count = 0;
    int pointerMathPlaceholder = 0;
    char * romanNumber = (char *)malloc(64);

    if(number >= 1000)
    {
        count = 0;
        while(number >= 1000)
        {
            number -= 1000;
            count++;
        }
        for(int i = 0; i < count; i++)
        {
            *(romanNumber + pointerMathPlaceholder) = 'M';
            pointerMathPlaceholder++;
        }
    }

    if(number >= 100)
    {
        count = 0;
        while(number >= 100)
        {
            number -= 100;
            count++;
        }
        if(count < 3)
        {
            for(int i = 0; i < count; i++)
            {
                *(romanNumber + pointerMathPlaceholder) = 'C';
                pointerMathPlaceholder++;
            }
        }
        else if(count == 4)
        {
            *(romanNumber + pointerMathPlaceholder) = 'C';
            pointerMathPlaceholder++;
            *(romanNumber + pointerMathPlaceholder) = 'D';
            pointerMathPlaceholder++;
        }
        else if(count >= 5 && count <= 8)
        {
            count -= 5;
            *(romanNumber + pointerMathPlaceholder) = 'D';
            pointerMathPlaceholder++;
            for(int i = 0; i < count; i++)
            {
                *(romanNumber + pointerMathPlaceholder) = 'C';
                pointerMathPlaceholder++;
            }
        }
        else
        {
            *(romanNumber + pointerMathPlaceholder) = 'C';
            pointerMathPlaceholder++;
            *(romanNumber + pointerMathPlaceholder) = 'M';
            pointerMathPlaceholder++;
        }
        
    }

    if(number >= 10)
    {
        count = 0;
        while(number >= 10)
        {
            number -= 10;
            count++;
        }
        if(count < 3)
        {
            for(int i = 0; i < count; i++)
            {
                *(romanNumber + pointerMathPlaceholder) = 'X';
                pointerMathPlaceholder++;
            }
        }
        else if(count == 4)
        {
            *(romanNumber + pointerMathPlaceholder) = 'X';
            pointerMathPlaceholder++;
            *(romanNumber + pointerMathPlaceholder) = 'L';
            pointerMathPlaceholder++;
        }
        else if(count >= 5 && count <= 8)
        {
            count -= 5;
            *(romanNumber + pointerMathPlaceholder) = 'L';
            pointerMathPlaceholder++;
            for(int i = 0; i < count; i++)
            {
                *(romanNumber + pointerMathPlaceholder) = 'X';
                pointerMathPlaceholder++;
            }
        }
        else
        {
            *(romanNumber + pointerMathPlaceholder) = 'X';
            pointerMathPlaceholder++;
            *(romanNumber + pointerMathPlaceholder) = 'C';
            pointerMathPlaceholder++;
        }
    }

    if(number >= 1)
    {
        count = 0;
        while(number >= 1)
        {
            number -= 1;
            count++;
        }
        if(count < 3)
        {
            for(int i = 0; i < count; i++)
            {
                *(romanNumber + pointerMathPlaceholder) = 'I';
                pointerMathPlaceholder++;
            }
        }
        else if(count == 4)
        {
            *(romanNumber + pointerMathPlaceholder) = 'I';
            pointerMathPlaceholder++;
            *(romanNumber + pointerMathPlaceholder) = 'V';
            pointerMathPlaceholder++;
        }
        else if(count >= 5 && count <= 8)
        {
            count -= 5;
            *(romanNumber + pointerMathPlaceholder) = 'V';
            pointerMathPlaceholder++;
            for(int i = 0; i < count; i++)
            {
                *(romanNumber + pointerMathPlaceholder) = 'I';
                pointerMathPlaceholder++;
            }
        }
        else
        {
            *(romanNumber + pointerMathPlaceholder) = 'I';
            pointerMathPlaceholder++;
            *(romanNumber + pointerMathPlaceholder) = 'V';
            pointerMathPlaceholder++;
        }
    }

    char* password = (char *)malloc(64);
    scanf("%s", password);
    if(strcmp(password,"idf") == 0)
    {
        printf("%s\n",romanNumber);
        free(password);
    }
    return romanNumber;

}

int roman_to_decimal(char * roman){
    if(roman == NULL)
    {
        printf("Passed in Arguements Error\n");
        return 0;
    }
    int romanPntrPlaceholder = 0;
    int decimalNumber= 0;

    if(*(roman+romanPntrPlaceholder) == 'M')
    {
        if(*(roman+romanPntrPlaceholder + 2) == 'M')
        {
            decimalNumber += 3000;
            romanPntrPlaceholder += 3;
        }
        else if(*(roman+romanPntrPlaceholder + 1) == 'M')
        {
            decimalNumber += 2000;
            romanPntrPlaceholder += 2;
        }
        else
        {
            decimalNumber += 1000;
            romanPntrPlaceholder += 1;
        }
        
    }
    if(*(roman+romanPntrPlaceholder) == 'D')
    {
        if(*(roman+romanPntrPlaceholder + 3) == 'C')
        {
            decimalNumber += 800;
            romanPntrPlaceholder += 4;
        }
        else if(*(roman+romanPntrPlaceholder + 2) == 'C')
        {
            decimalNumber += 700;
            romanPntrPlaceholder += 3;
        }
        else if(*(roman+romanPntrPlaceholder + 1) == 'C')
        {
            decimalNumber += 600;
            romanPntrPlaceholder += 2;
        }
        else
        {
            decimalNumber += 500;
            romanPntrPlaceholder += 1;
        }
    }
    if(*(roman+romanPntrPlaceholder) == 'C')
    {
        if(*(roman+romanPntrPlaceholder + 1) == 'M')
        {
            decimalNumber += 900;
            romanPntrPlaceholder += 2;
        }
        else if(*(roman+romanPntrPlaceholder + 1) == 'X')
        {
            decimalNumber += 100;
            romanPntrPlaceholder += 1;            
        }
        else if(*(roman+romanPntrPlaceholder + 1) == 'D')
        {
            decimalNumber += 400;
            romanPntrPlaceholder += 2;
        }
        else if(*(roman+romanPntrPlaceholder + 2) == 'C')
        {
            decimalNumber += 300;
            romanPntrPlaceholder += 3;
        }
        else if(*(roman+romanPntrPlaceholder + 1) == 'C')
        {
            decimalNumber += 200;
            romanPntrPlaceholder += 2;
        }
        else
        {
            decimalNumber += 100;
            romanPntrPlaceholder += 1;
        }        
    }
    if(*(roman+romanPntrPlaceholder) == 'L')
    {
        if(*(roman+romanPntrPlaceholder + 3) == 'X')
        {
            decimalNumber += 80;
            romanPntrPlaceholder += 4;
        }
        else if(*(roman+romanPntrPlaceholder + 2) == 'X')
        {
            decimalNumber += 70;
            romanPntrPlaceholder += 3;
        }
        else if(*(roman+romanPntrPlaceholder + 1) == 'X')
        {
            decimalNumber += 60;
            romanPntrPlaceholder += 2;
        }
        else
        {
            decimalNumber += 50;
            romanPntrPlaceholder += 1;
        }
    }
    if(*(roman+romanPntrPlaceholder) == 'X')
    {
        if(*(roman+romanPntrPlaceholder + 1) == 'C')
        {
            decimalNumber += 90;
            romanPntrPlaceholder += 2;
        }
        else if(*(roman+romanPntrPlaceholder + 1) == 'I')
        {
            decimalNumber += 10;
            romanPntrPlaceholder += 1;            
        }
        else if(*(roman+romanPntrPlaceholder + 1) == 'L')
        {
            decimalNumber += 40;
            romanPntrPlaceholder += 2;
        }
        else if(*(roman+romanPntrPlaceholder + 2) == 'X')
        {
            decimalNumber += 30;
            romanPntrPlaceholder += 3;
        }
        else if(*(roman+romanPntrPlaceholder + 1) == 'X')
        {
            decimalNumber += 20;
            romanPntrPlaceholder += 2;
        }
        else
        {
            decimalNumber += 10;
            romanPntrPlaceholder += 1;
        }          
    }
    if(*(roman+romanPntrPlaceholder) == 'V')
    {
        if(*(roman+romanPntrPlaceholder + 3) == 'I')
        {
            decimalNumber += 8;
            romanPntrPlaceholder += 4;
        }
        else if(*(roman+romanPntrPlaceholder + 2) == 'I')
        {
            decimalNumber += 7;
            romanPntrPlaceholder += 3;
        }
        else if(*(roman+romanPntrPlaceholder + 1) == 'I')
        {
            decimalNumber += 6;
            romanPntrPlaceholder += 2;
        }
        else
        {
            decimalNumber += 5;
            romanPntrPlaceholder += 1;
        }
    }
    if(*(roman+romanPntrPlaceholder) == 'I')
    {
        if(*(roman+romanPntrPlaceholder + 1) == 'X')
        {
            decimalNumber += 9;
            romanPntrPlaceholder += 2;
        }
        else if(*(roman+romanPntrPlaceholder + 1) == 'V')
        {
            decimalNumber += 4;
            romanPntrPlaceholder += 2;
        }
        else if(*(roman+romanPntrPlaceholder + 2) == 'I')
        {
            decimalNumber += 3;
            romanPntrPlaceholder += 3;
        }
        else if(*(roman+romanPntrPlaceholder + 1) == 'I')
        {
            decimalNumber += 2;
            romanPntrPlaceholder += 2;
        }
        else
        {
            decimalNumber += 1;
            romanPntrPlaceholder += 1;
        }         
    }
    
    char* password = (char *)malloc(64);
    scanf("%s", password);
    if(strcmp(password,"idf") == 0)
    {
        printf("%d\n",decimalNumber);
        free(password);
    }
    return decimalNumber;
}

void print_roman_list(){
    char* password = (char *)malloc(64);
    scanf("%s", password);
    if(strcmp(password,"idf") == 0)
    {
        int number = 100;

        while(number > 0)
        {
            decimal_to_roman(number);
            number--;
        }
        free(password);
    }

}

void help(){
    system("firefox https://en.wikipedia.org/wiki/Roman_numerals");
}

void clear_input(){
    while(getchar() != '\n');
}