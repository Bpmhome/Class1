#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//create my own boolean variable
#define bool unsigned int
#define true 1
#define false 0

char * convert_to_letters(char* num);
char * print_number(char num);
char * print_number_tens_place(char number1,char number2);
void encrypt(char * number);



int main(){

    //Users number and pointer to
    char userNum[10] = {0};
    char * userNum_ptr = userNum;  
    char* result = NULL;

    //get the user's number
    printf("Please enter your number to be turned to words!\nYour number can be from 0 to 9999.999\n\tEnter Here: ");
    scanf("%12s",userNum);

    //convert the user's number
    result = convert_to_letters(userNum_ptr);
    if(result == NULL)
    {
        printf("Error in Conversion.");
        return 1;
    }
    encrypt(result);
    printf("Encrypted Results: %s",result);
    printf("\n");



}

char * convert_to_letters(char* num)
{
    int length = strlen(num);
    int placesAfterDecimal = 0;
    char * decimal_ptr;
    bool afterDecimal = false;
    char * result = (char *)malloc(256);
    char * temp = (char *)malloc(256);

    for(int i = 0; i < length; i++)
    {
        if(*(num + i) == '.')
        {
            decimal_ptr = (num + i);
            break;
        }
    }

    for(int i = 0; i < length; i++)
    {
        if(((num + i) - decimal_ptr) == 0)
        {
            afterDecimal = true;
            printf(" and ");
            strcpy(&result[strlen(result)]," and ");
        }
        else
        {
            if(afterDecimal == false)
            {

                if(((num + i) - decimal_ptr) == -4 && *(num + i) != '0')
                {
                    printf("%s thousand ",print_number(*(num + i)));
                    temp = print_number(*(num + i));
                    //temp = strcat(temp," thousand ");
                    strcpy(&result[strlen(result)],temp);

                }
                else if(((num + i) - decimal_ptr) == -3 && *(num + i) != '0')
                {
                    printf("%s hundred ", print_number(*(num + i)));
                    temp = print_number(*(num + i));
                    //temp = strncat(temp," hundred ",9);
                    strcpy(&result[strlen(result)],temp);
                }
                else if(((num + i) -  decimal_ptr) == -2 && *(num + i) != '0')
                {
                    printf("%s",print_number_tens_place(*(num + i),*(num + i + 1)));
                    strcpy(&result[strlen(result)],print_number_tens_place(*(num + i),*(num + i + 1)));
                }
                else if(((num + i) - decimal_ptr) == -1 && *(num + i) != '0')
                {
                    if(*(num + i - 1) != 1)
                    {
                        printf("-%s",print_number(*(num + i)));
                        strcpy(&result[strlen(result)],print_number(*(num + i)));

                    }
                }
            }
            else
            {
                printf("%c",*(num + i));
                result[strlen(result)] = *(num + i);
                placesAfterDecimal++;
            }   
        }
    }
    switch(placesAfterDecimal)
    {
        case 0:
            printf("0/1\n");
            strcpy(&result[strlen(result)],"0/1");
            break;
        case 1:
            printf("/10.\n");
            strcpy(&result[strlen(result)],"0/10");
            break;
        case 2:
            printf("/100.\n");
            strcpy(&result[strlen(result)],"0/100");
            break;
        case 3:
            printf("/1000.\n");
            strcpy(&result[strlen(result)],"0/1000");
            break;
    }

    return result;
}

char * print_number(char number)
{
    char * returnValue = (char *)malloc(6);
    switch (number)
    {
        case '1':
            returnValue = "one";
            break;
        case '2':
            returnValue = "two";
            break;
        case '3':
            returnValue = "three";
            break;
        case '4':
            returnValue = "four";
            break;
        case '5':
            returnValue = "five";
            break;
        case '6':
            returnValue = "six";
            break;
        case '7':
            returnValue = "seven";
            break;
        case '8':
            returnValue = "eight";
            break;
        case '9':
            returnValue = "nine";
            break;

        default:
            returnValue = "ERROR";
            break;
    }
    return returnValue;
}

char * print_number_tens_place(char number1,char number2)
{
    char * returnValue = (char *)malloc(10);
    switch (number1)
    {
        case '1':
            switch(number2)
            {
                case '0':
                    returnValue = "ten";
                    break;
                case '1':
                    returnValue = "eleven";
                    break;
                case '2':
                    returnValue = "twelve";
                    break;
                case '3':
                    returnValue = "thirteen";
                    break;
                case '4':
                    returnValue = "fourteen";
                    break;
                case '5':
                    returnValue = "fifteen";
                    break;
                case '6':
                    returnValue = "sixteen";
                    break;
                case '7':
                    returnValue = "seventeen";
                    break;
                case '8':
                    returnValue = "eighteen";
                    break;
                case '9':
                    returnValue = "nineteen";
                    break;
            }

            break;
        case '2':
            returnValue = "twenty";
            break;
        case '3':
            returnValue = "thirty";
            break;
        case '4':
            returnValue = "fourty";
            break;
        case '5':
            returnValue = "fifty";
            break;
        case '6':
            returnValue = "sixty";
            break;
        case '7':
            returnValue = "seventy";
            break;
        case '8':
            returnValue = "eighty";
            break;
        case '9':
            returnValue = "ninety";
            break;

        default:
            returnValue = "ERROR";
            break;
    }
    return returnValue;
}

void encrypt(char * number)
{
    for(size_t i = 0; i < strlen(number); i++)
    {
        *(number + i) = (((*(number + i) + 'I') - 'D') * 'F');
    }
}