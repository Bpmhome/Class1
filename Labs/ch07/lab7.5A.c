/*
    Programmer: Grant Ogden
    Date: 2/10/2019
    Filename: lab7.5A.c
    Reason: To better understand Nested Control flow.
*/
#include <stdio.h>
#include <ctype.h>

int main()
{
    //variable for character input
    char userInput = 0;

    //repeat until we get the users input
    do
    {
        //flush the stream
        fflush(stdin);

        //get the users input
        printf("Please enter whether you want odds or evens by typing it: \n");
        userInput = getc(stdin);
        //if it is a letter then set it to upper else continue the loop
        if((userInput >= 65 && userInput <= 90) || (userInput >= 97 && userInput <= 122))
        {
            userInput = toupper(userInput);
        }
        else
        {
            continue;
        }
    } while (userInput != 69 && userInput != 79);

    //if the userinput is an E than evens else odd
    if(userInput == 'E')
    {
        //for every number between zero to 100, increment by two
        for(int i = 0; i <= 100; i+= 2)
        {
            //if the number is odd then add 1
            if(i & 1)
            {
                i++;
            }
            //print it
            printf("%d ",i);
        }    
        printf("\n");
    }
    else
    {
        //counter variable for while loop
        int counter = 0;
        //repeat while counter is less than and equal to 100
        while(counter <= 100)
        {
            //if it is even add 1
            if((counter & 1) == 0)
            {
                counter++;
            }
            //print it and increment by two
            printf("%d ",counter);
            counter += 2;
        }
        printf("\n");
    }
    
    return 0;
}