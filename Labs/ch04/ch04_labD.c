/*
    Programmer: Grant Ogden
    Date: 2/1/2018
    Filename: ch04_labD.c
    Reason: To understand scanf() and printf()
*/
#include <stdio.h>

int main()
{
    //Three char arrays 50 elements long created to hold individual names (first,middle,last)
    char firstName[50] = {0};
    char middleName[50] = {0};
    char lastName[50] = {0};

    //Two integer variables used to hold the two values given to us by the user
    int userNum1 = 0;
    int userNum2 = 0;

    //A char value that holds the users input to decide what part they want to do
    char userChoice = {0};

    //Must run once and repeats if the user inputs an incorrect choice
    do
    {
        //Notify the user to select a part and pull their value
        printf("Choose Part 1 or Part 2 by entering the number of the part:\n");
        userChoice = getchar();

        //If the user chose part one then do it
        if(userChoice == '1')
        {
            //Ask the user for their name and take the input and output it back to them
            printf("Please enter your full name with each name\nseperated by a tab:\n");
            scanf("%49s\t%49s\t%49s",firstName,middleName,lastName);
            printf("Your name is:\n\t%s\n\t%s\n\t%s\n",firstName,middleName,lastName);
        }
        //Else if the user chooses part two then do it
        else if(userChoice == '2')
        {
            //Ask the user for their two numbers for input and give them back to them and the numbers multiplied together
            printf("Please enter two integers to be multiplied\nthat are sepereated by an asterick(*):\n");
            scanf("%d*%d", &userNum1,&userNum2);
            printf("The result of %d multiplied by %d is %d.\n",userNum1,userNum2,(userNum1*userNum2));
        }
        //while the user hasn't correctly chosen a part ask them again
    }while(userChoice != '1' && userChoice != '2');

    return 0;
}