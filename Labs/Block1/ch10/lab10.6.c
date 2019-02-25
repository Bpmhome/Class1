/*
    Programmer: Grant Ogden
    Date: 2-19-2018
    Filename: lab10.6.c
    Reason: to better understand preprocessor
*/
#include <stdio.h>
#define STRINGIFY(x) #x
#define MERGE(x,y) QUOTE(x##y)
#define QUOTE(x) "\""STRINGIFY(x)"\""
#define BUFF 64

int main()
{
    char string[BUFF] = {MERGE(Ro,bot)};


    puts(MERGE(userInput1,userInput2));
    puts(string);
    return 0;
}