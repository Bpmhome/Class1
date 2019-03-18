#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define bool unsigned int
#define true 1
#define false 0

char * convert_to_letters(char* num);
char * print_number(char num);
char * print_number_tens_place(char num);

int main(){
    char * userNum = (char *)malloc(7);

    printf("Please enter your number to be turned to words!\nYour number can be from 0 to 9999.999\n\tEnter Here: ");
    scanf("%s",userNum);

    convert_to_letters(userNum);
}

char * convert_to_letters(char* num)
{
    int length = strlen(num);
    char * decimal_ptr;
    bool afterDecimal = false;

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
            //i++;
            printf(".");
        }
        else
        {
            if(afterDecimal == false)
            {
                if(((num+i) - decimal_ptr) == 3)
                {
                    printf("%s thousand ",print_number(*(num + i)));
                }
                else if(((num+i) - decimal_ptr) == 2)
                {
                    if()
                }
                else
                {
                    
                }
                
            }
            else
            {
                
            }
            
        }

    }
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

char * print_number_tens_place(char number)
{
    char * returnValue = (char *)malloc(5);
    switch (number)
    {
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