/*
    Programmer: Grant Ogden
    Date: 2/14/2019
    Filename: lab8C.c
    Reason: To better understand the usage of recursive functions
*/
#include <stdio.h>
#define MAXIMUM_SEQ_NUM (2300)
#define ERROR_VALUE (105)

#define MANUAL_TEST
//#define AUTO_TEST


//Prototype of our shadow sequence number generator
unsigned long shadow_sequence_number(int placeNumber);

int main()
{
    //Decleration of Stadard Variables
    int userInput = 0;                  //The Variable used to hold the user's input
    unsigned long shadowNumber = 0;	    //The variable used to hold the return from shadow_sequence_number
    int tempValue = 0;

    //the original individual testing for shadow_sequence_number
    /*
    printf("Please enter a positive number for that value in the Shadow Sequence: ");
    fscanf(stdin,"%d",&userInput);

    shadowNumber = shadow_sequence_number(userInput);
    printf("Your Shadow Number is: %d\n", shadowNumber);
    */

    //The given Manual Tester
    #ifdef MANUAL_TEST
	int howManyToCalculate = 0;
	tempValue = 0;

	printf("How many numbers would you like to calculate?\n");

	scanf("%d", &userInput);
	putchar(10);

	for (int i = 1; i <= userInput; i++)
	{
		shadowNumber = shadow_sequence_number(i);
		printf("%d:\t%lu \n", i, shadowNumber);
	}
    #endif

    //The given auto tester
    #ifdef AUTO_TEST

    #define BUFF_SIZE 24
    tempValue = 0;
	int numberOfTestsRun = 0;
	int numberOfTestsPassed = 0;
	int placeNumbers[BUFF_SIZE] = { -31337, ((MAXIMUM_SEQ_NUM + 1) * -1), (MAXIMUM_SEQ_NUM * -1), -1337, -100, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 100, 1337, MAXIMUM_SEQ_NUM, (MAXIMUM_SEQ_NUM + 1), 31337 };
	unsigned long returnValues[BUFF_SIZE] = { ERROR_VALUE, ERROR_VALUE, ERROR_VALUE, ERROR_VALUE, ERROR_VALUE, ERROR_VALUE, 9, 0, 9, 25, 50, 86, 135, 199, 280, 380, 501, 645, 814, 338345, 797553920, 4058312045, ERROR_VALUE, ERROR_VALUE };

	for (int i = 0; i < BUFF_SIZE; i++)
	{
		shadowNumber = shadow_sequence_number(placeNumbers[i]);
        printf("%u\n",shadowNumber);
		numberOfTestsRun++;
		if (tempValue == returnValues[i])
		{
			numberOfTestsPassed++;
		}
	}

	printf("\n\nNumber of tests run:\t%d\n", numberOfTestsRun);
	printf("Number of tests passed:\t%d\n", numberOfTestsPassed);
    #endif
    
    return 0;
}

/*
 * FUNCTION:   unsigned long shadow_sequence_number(int placeNumber)
 *
 * ARGUMENTS:  placeNumber represents the individual "Shadow Sequence" position number to calculate
 *
 * RETURNS:	   The value of of the "Shadow Sequence" number at position "placeNumber" [see: S(placeNumber)].
 *			   The "Shadow Sequence" is calculated utlizing the following algorithm:
 *                 S(n) = S(n-1) + (n * n) where "n" represents a given position and S(n) represents the value at
 *                     position "n".  S(1) is always equal to 9.  S(2) is always equal to 0.  The algorithm begins
 *                     calculating at S(3).  (see NOTES: for details)  
 *             ERROR_VALUE (105) if placeNumber is unrealistic or dangerous
 *
 * NOTES:      This function should only be returning a single sequence number from the "Shadow Sequence".
 *             This function should *not* be calculating multiple sequence numbers during a single function call.
 *             Nor should this function be printing any sequence numbers.
 *             However, this function will need to call itself recursively to calculate all of the previous sequence
 *                 numbers in order to calculate the sequence number at position "placeNumber".
 *             Any requirements to calcualte or print multiple numbers in the "Shadow Sequence" should be
 *                 accomplished by the calling function [e.g., main()]
 *             The data type of long was chosen as the return value to increase the available output.
 *             The keyword unsigned was chosen to further maximize the available output since this algorithm
 *                 should not be producing any negative numbers.
 *			   The "Shadow Sequence" is calculated utlizing the following algorithm:
 *                 S(n) = S(n-1) + (n * n) where "n" represents a given position and S(n) represents the value at
 *                     position "n".  S(1) is always equal to 9.  S(2) is always equal to 0.  The algorithm begins
 *                     calculating at S(3).  For example, here are some sample calculations of S(n)
 *                     S(1) = 9.
 *                     S(2) = 0.
 *                     S(3) = S(2) + (3 * 3) ---> S(3) = (0)  + (9) ---> S(3) = 9.
 *                     S(4) = S(3) + (4 * 4) ---> S(4) = (9)  + (16) --> S(4) = 25.
 *                     S(5) = S(4) + (5 * 5) ---> S(5) = (25) + (25) --> S(5) = 50.
 *
 *             The first few "Shadow Sequence" numbers are as follows:
 *                 S(1)		S(2)	S(3)	S(4)	S(5)	S(6)	S(7)	S(8)	S(9)	S(10)
 *                 9		0		9		25		50		86		135		199		280		380
 */
unsigned long shadow_sequence_number(int placeNumber)
{
    if(placeNumber > 2300 || placeNumber <= 0)  //if placeNumber is not within valid range then return error number
    {
        return 105;
    }
    else if(placeNumber == 1)                   //if placeNumber is equal to 1 return given value 9
    {
        return 9;
    }
    else if(placeNumber == 2)                   //if placeNumber is equal to 2 return given value 0
    {
        return 0;
    }
    else                                        //else return the call of shadow_sequence_number(placeNumber - 1) + placeNumber ^ 2
    {
        return (shadow_sequence_number(placeNumber - 1) + (placeNumber * placeNumber));
    }
}