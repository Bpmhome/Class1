#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define bool unsigned int
#define true 1
#define false 0

char * convert_to_letters(char* num);
char * print_number(char num);
char * print_number_tens_place(char number1,char number2);

int main(){
    char userNum[10] = {0};
    char * userNum_ptr =userNum;  

    printf("Please enter your number to be turned to words!\nYour number can be from 0 to 9999.999\n\tEnter Here: ");
    scanf("%12s",userNum);
    //printf("Input recieved");
    printf("%s\n",userNum);
    convert_to_letters(userNum_ptr);
}

char * convert_to_letters(char* num)
{
    //printf("Did we even get here?");
    int length = strlen(num);
    int placesAfterDecimal = 0;
    char * decimal_ptr;
    bool afterDecimal = false;
    //printf("Did we get here?");
    for(int i = 0; i < length; i++)
    {
        if(*(num + i) == '.')
        {
            decimal_ptr = (num + i);
            //printf("Decimal found");
            break;
        }
    }

    for(int i = 0; i < length; i++)
    {
        if(((num + i) - decimal_ptr) == 0)
        {
            afterDecimal = true;
            //i++;
            printf(" and ");
        }
        else
        {
            if(afterDecimal == false)
            {

                if(((num + i) - decimal_ptr) == -4 && *(num + i) != '0')
                {
                    printf("%s thousand ",print_number(*(num + i)));
                }
                else if(((num + i) - decimal_ptr) == -3 && *(num + i) != '0')
                {
                    printf("%s hundred ", print_number(*(num + i)));
                }
                else if(((num + i) -  decimal_ptr) == -2 && *(num + i) != '0')
                {
                    printf("%s",print_number_tens_place(*(num + i),*(num + i + 1)));
                }
                else if(((num + i) - decimal_ptr) == -1 && *(num + i) != '0')
                {
                    if(*(num + i - 1) != 1)
                    {
                        printf("-%s",print_number(*(num + i)));
                    }
                }
            }
            else
            {
                printf("%c",*(num + i));
                placesAfterDecimal++;
            }   
        }
    }
    switch(placesAfterDecimal)
    {
        case 0:
            printf("0/1\n");
            break;
        case 1:
            printf("/10.\n");
            break;
        case 2:
            printf("/100.\n");
            break;
        case 3:
            printf("/1000.\n");
            break;
    }

    return NULL;
}

char * print_number(char number)
{
    char * returnValue = (char *)malloc(5);
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
    char * returnValue = (char *)malloc(5);
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