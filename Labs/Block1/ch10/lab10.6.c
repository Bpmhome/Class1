/*
    Programmer: Grant Ogden
    Date: 2-19-2018
    Filename: lab10.6.c
    Reason: to better understand preprocessor
*/
#include <stdio.h>
#define STRINGIFY(x) #x
#define MERGE(x,y) STRINGIFY(x##y)
#define QUOTE(x,y) "\""MERGE(x,y)"\""

int main()
{
    puts(MERGE(Grant,Ogden));
    puts(QUOTE(Grant,Ogden));

    return 0;
}