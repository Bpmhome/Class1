// MyStringHeader.c
#include <stdio.h>
#include <ctype.h>

#define ERR_NULL_POINTER -1;        // string is null
#define ERR_INVALID_LENGTH -2;      // string length is zero or less

extern int print_the_count(char * inputString, int strLen)
{
    char tempChar = 0;      // Current char being acted on
    int table[26] = {0};    // Alpha
    int count = 0;

    if (!inputString)
    {
        return ERR_NULL_POINTER;
    }
    else if (!strLen)
    {
        return ERR_INVALID_LENGTH;
    }

    for (int i = 0; i < strLen; i++)
    {
        if (inputString[i] >= 65 && inputString[i] <= 122)
        {
            tempChar = inputString[i];
            tempChar = toupper(tempChar);
            table[tempChar - 65] += 1;
            count++;
        }
    }

    // Print the table
    for (int i = 0; i < sizeof(table)/sizeof(table[0]); i++)
    {
        printf("%c: %d\n", i + 65, table[i]);
    }
    return count;
}

extern int reverse_it(char * forwardString, int strLen)
{
    if (!forwardString)         //if the string is null then return ERR_NULL_POINTER
    {
        return ERR_NULL_POINTER;
    }
    else if (strLen <= 0)       //if the string length is zero then return ERR_INVALID_LENGTH
    {
        return ERR_INVALID_LENGTH;
    }
    char tempString[255] = {0}; //temp array dec
    int count = 0;              //count how many letters
    

    //write value into temp array
    for (int i = 0; forwardString[i] != '\0'; i++)
    {
        tempString[i] = forwardString[i];
        count++;
    }

    //write value backwards back into original string
    int x = 0;
    for(int i = (count - 1); i >= 0; i--)
    {
        forwardString[x] = tempString[i];
        x++;
    }
    return 0;
}