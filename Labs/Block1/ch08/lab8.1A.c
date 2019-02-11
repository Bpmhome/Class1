/*
    Programmer: Grant Ogden
    Date: 2/11/2018
    Filename: lab8A.c
    Reason: To better understand the utilization of functions
*/
#include <stdio.h>
#include <string.h>
#define ERR_NULL_POINTER -1		                // Error:  Pointer passed was NULL
#define ERR_NONE_FOUND 0		                // Error:  Character not found
#define ERR_FIND_EQUALS_REPLACE -2              // Error:  To replace and replace are equal to each other
#define ERR_NON_PRINTABLE_CHARACTER -3          // Error:  One of the characters is not printable


// Create your prototypes here
int replace_character(char * string, const char findThisChar,const char replaceItWithThis);
int clearInput();    // I included an awesome function used to clear your input buffer

int main(void)
{
	/* FUNCTION INPUT ARRAYS 
    ---These are included because we have not learned about pointers yet
    */
	char beforeString1[] = { "If debugging is the process of removing software bugs, then programming must be the process of putting them in.  -Edsger Dijkstra" }; // No newlines
	char * beforeStringArray[] = { beforeString1 };

    // TODO: Create your main variables


    // TODO: Create your program output, user instructions, user input etc


    // TODO: Implement replace_char function call here


    // TODO: Check for error return, handle it
    


	return 0;
}

/*
 * FUNCTION:   int replace_char(char * buffer, char findChar, char replaceChar)
 *
 * ARGUMENTS:  -buffer is a pointer to a null-terminated string
 *              The string is passed by reference and modified in place
 *              -findChar is a char to be found in the string
 *              -replaceChar is the char to replace the findChar
 *
 * RETURNS:	   Number of characers replaced
 *             ERR_NULL_POINTER if buffer == NULL
 *             ERR_NONE_FOUND if no newlines are found
 *             ERR_FIND_EQUALS_REPLACE -2              // Error:  To replace and replace are equal to each other
 *             ERR_NON_PRINTABLE_CHARACTER -3          // Error:  One of the characters is not printable
 *
 * NOTES:      This function replaces instances of a userinputted character with another user inputted char
 */
// TODO: Create your function here
int replace_character(char * string, const char findThisChar,const char replaceItWithThis)
{
    int counter = 0;
    if(string == NULL)
    {
        return ERR_NULL_POINTER;
    }
    else if(findThisChar == replaceItWithThis)
    {
        return ERR_FIND_EQUALS_REPLACE;
    }
    else if(
        
    )
    while(string[counter] != '\0')
    {
        if(string[counter] == findThisChar)
        {
            string[counter] = replaceItWithThis;
        }
        counter++;
    }
}



// This is an awesome function and useful if you need to clear the input buffer
int clearInput()
{
    while ( getchar() != '\n' );
}