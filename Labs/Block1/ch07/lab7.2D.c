/*
    Programmer: Grant Ogden
    Date: 2/7/2019
    Filename: labD7.2.c
    Reason: To better understand switch case statements and how to use them
*/
#include<stdio.h>

int main()
{
    //Variables to take the user's inputs
    int userInput1 = 0;
    int userInput2 = 0;
    char operator = 0;

    //Gotta get that sweet input
    printf("Please enter two numbers seperated by an operator (+,-,*,/): ");
    scanf("%d%c%d",&userInput1,&operator,&userInput2);

    //let them know the number coming out is the answer to life
    printf("Your answer is: ");
    
    //a switch case that does certain cases based off what the operator equals
    switch (operator)
    {
        //case its a cat buthole then multiply
        case '*':
            printf("%d\n",(userInput1 * userInput2));
            break;
        //case its a slash then divide
        case '/':
            //if it is a divide by zero error then stop and tell them
            if(userInput2 == 0)
            {
                printf("DIVIDE BY ZERO ERROR\n");
            }
            else
            {
                printf("%.2lf\n",((double)userInput1/userInput2));
            }           
            break;
        //if it is a cross then we add
        case '+':
            printf("%d\n",(userInput1 + userInput2));
            break;
        //if it is a dash then we minus
        case '-':
            printf("%d\n",(userInput1 - userInput2));
            break;

        //if we end up here then the stupid user didn't obey instructions
        //so don't give them the satisfaction of breaking the our program
        //just tell them error and let them wallow in their own filth 
        default:
            printf("ERROR\n");
            break;
    }
}