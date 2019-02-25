/*
    Programmer: Grant Ogden
    Date: 2/20/2019
    Filename: lab10.7.c
    Reason: To better understand conditional compilation
*/
#include<stdio.h>

#undef EOF
#define EOF 66
#define STRINGIFY(x) #x
#define _INC_STDIO 666
#define MACRO(x) (x*x)

#ifdef _INC_STDIO
int main()
{
    #ifdef MACRO
    printf("%s: %d\n",STRINGIFY(MACRO(1)),MACRO(1));
    #endif

    #if FOPEN_MAX == 16
    printf("%s: %d\n",STRINGIFY(FOPEN_MAX),FOPEN_MAX);
    #else
    printf("Error")
    #endif

    #if EOF == -1
    printf("%s: %d\n",STRINGIFY(EOF),EOF);
    #else
    printf("EOF VALUE CHANGED");
    #endif


    printf("%s: %d\n",STRINGIFY(FILENAME_MAX),FILENAME_MAX);
    printf("%s: %d\n",STRINGIFY(_INC_STDIO),_INC_STDIO);
    return 0;

}
#endif