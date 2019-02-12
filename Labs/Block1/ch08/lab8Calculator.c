/*
    Programmer: Grant Ogden
    Date: 2/12/2019
    Filename: lab8Calculator.c
    Reason: Lets do math!
*/
#include <stdio.h>

double add(double a,double b);
double subtract(double a,double b);
double multiply(double a,double b);
double divide(double a,double b);
void input_clear();

int main()
{
    double userNum1 = 0;
    double userNum2 = 0;
    char operator = 0;
    char userChoice = 0;

    do
    {
        if(userChoice == 0)
        {
            fprintf(stdout,"Input Two Numbers Seperated by The Math Operator (/,*,-,+):\n");
            fscanf(stdin,"%lf%[/*-+]c%lf",&userNum1,&operator,&userNum2);
        }
        else
        {
            //TODO: Enter a way for them to continuesly perform math
        }

        switch(operator)
        {
            case '/':
                if(userNum2 == 0)
                {
                    printf("Divide by 0 Error");
                    continue;
                }
                userNum1 = divide(userNum1,userNum2);
                break;
            case '*':
                userNum1 = multiply(userNum1,userNum2);
                break;
            case '-':
                userNum1 = subtract(userNum1,userNum2);
                break;
            case '+':
                userNum1 = add(userNum1,userNum2);
                break;
            default
                break;
        }
        
    } while (userChoice == 'y');
    

    return 0;
}

double add(double a, double b)
{
    return a + b;
}

double subtract(double a,double b)
{
    return a - b;
}

double multiply(double a,double b)
{
    return a * b;
}





void input_clear()
{
    while(getchar != '\n');
}