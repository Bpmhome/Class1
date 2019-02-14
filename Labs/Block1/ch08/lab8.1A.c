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
int clear_input();    // I included an awesome function used to clear your input buffer

int main(void)
{
	//Variable Declerations
	char beforeString1[300] = {0};                  // Array to hold user input
	char * beforeStringArray[] = { beforeString1 }; // Pointer Array to hold array addresses
    int errorCatcher = 1;                           // Integer to catch the output from the replace_character function to check for errors
    char oldChar = 0;                               // Char var to hold what the user wants changed
    char newChar = 0;                               // Char var to hold what the user wants changed to

    //Get the user's string
    printf("Please input the string you want to modify:\n");
    fscanf(stdin,"%299[^\n]c",beforeString1);
    //Clear the stdin Buffer
    clear_input();
    //Get the value that the user wants changed and what to change it to
    printf("Please input the character you want replaced then the new character seperated by a comma (t,e):");
    fscanf(stdin,"%c,%c",&oldChar,&newChar);

    //Pass to the replace_character function and catch the return
    errorCatcher = replace_character( *beforeStringArray,oldChar,newChar);

    //Check the return to see if there was an error
    switch (errorCatcher)
    {
        case 0:
            printf("Error: None Found\n");
            break;
        case -1:
            printf("Error: Null Pointer\n");
            break;
        case -2:
            printf("Error: Find Equals Replace\n");
            break;
        case -3:
            printf("Error: Non-Printable Char\n");
    
        default:
            break;
    }
    //print the new string to the user
    printf("%s", beforeString1);
    printf("\n");
    
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
 *             ERR_NONE_FOUND if no finds are found
 *             ERR_FIND_EQUALS_REPLACE -2              // Error:  To replace and replace are equal to each other
 *             ERR_NON_PRINTABLE_CHARACTER -3          // Error:  One of the characters is not printable
 *
 * NOTES:      This function replaces instances of a userinputted character with another user inputted char
 */
// TODO: Create your function here
int replace_character(char * string, const char findThisChar,const char replaceItWithThis)
{
    int counter = 0;            //counts the positions through the string
    int numberOfChanges = 0;    //counts the number of changes

    //checking for errors
    if(string == NULL)                              //If the string pointer is null
    {
        return ERR_NULL_POINTER;
    }
    else if(findThisChar == replaceItWithThis)      //If the find and replace variables are the same
    {
        return ERR_FIND_EQUALS_REPLACE;
    }
    else if(!((findThisChar >= 32 && findThisChar <= 126) || (replaceItWithThis >= 32 && replaceItWithThis <= 126)))    //if either are nonprintable characters
    {
        return ERR_NON_PRINTABLE_CHARACTER;
    }

    while(string[counter] != '\0')              //while the char isn't null
    {
        if(string[counter] == findThisChar)     //if the char is the one were are looking for
        {
            string[counter] = replaceItWithThis;//put the new char into that position
            numberOfChanges++;                  //count that change!!
        }
        counter++;                              //next char please
    }
    if(numberOfChanges == 0)                    //if we didn't change anything then what the hell
    {
        return ERR_NONE_FOUND;
    }
    return numberOfChanges;
}



// This is an awesome function and useful if you need to clear the input buffer
int clear_input()
{
    while ( getchar() != '\n' );
}