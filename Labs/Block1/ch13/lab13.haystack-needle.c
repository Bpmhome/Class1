/*
Haystack Needle Lab
Purpose: Remove the needle from the haystack
AKA: Move the substring from the string using memory operators and functions
*/

/*
    Programmer: Grant Ogden
    Date: 2/26/2019
    Filename: lab13.haystack-needle.c
    Reason: to better understand dynamic memory allocation
*/

// TODO: Include any needed headers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int haystack_needle(char *haystack, char *needle, char *buffer);

int main()
{
    char string[] = "This is my brand new sentence";
    char substring[] = " brand new";

    // TODO: Create a char buffer named *buffer using malloc
    //ensure it is large enough to hold string[] + a nul-terminator
    char *buffer = NULL;
    buffer = malloc(strlen(string) + 1);

    // TODO: Ensure buffer was created
    if(buffer == NULL)
    {
      printf("MALLOC ERROR");
      return -1;
    }

    haystack_needle(string, substring, buffer);

    // TODO: Give back the memory from buffer
    free(buffer);
    buffer = NULL;

    // TODO: Print out the modified string
    printf("%s\n",string);

    return 0;

}

/*
Arguments:      -haystack --- pointer to string to search
                -needle   --- pointer to substring to search inside of haystack
                -buffer   --- pointer to a buffer

PURPOSE:        haystack_needle takes the arguments above and searches the haystack
                for the needle. Once it finds the needle... it removes it from the haystack.

Return:         return 0 on success
                return -1 on error .... only needed if userinput is enabled.
*/
int haystack_needle(char *haystack, char *needle, char *buffer)
{
    int needleLength = strlen(needle);

    // TODO: Using strstr() find the needle in the haystack (substring in string)\
    the pointer that is returned is pointing to the substring within the string \
    Set that pointer to a new char pointer called *mark_position
    char *mark_position = strstr(haystack,needle);

    // TODO: Using strcpy(), store the end of the needle into the buffer... \
    you are not authorized to use the variable needle.
    strcpy(buffer,mark_position + needleLength);


    // TODO: Using memmove, overwrite the haystack (string)... effectivly removing the needle \
    // HINT: start at the mark_position... that is after all where we need to start replacing.
    memmove((void*)mark_position,(void*)(buffer),strlen(buffer) + 1);

    return 0;
}