/*
    Programmer: Grant Ogden
    Date: 1/29/2019
    FileName: ch02_labB.c
    Reason: For a deeper understanding of type casting and example
*/
#include<stdio.h>

int main()
{
    int robert = 125;
    float bob = 1.23;
    double bobert = 3.654516546156;
    char charBear = 'R';

    printf("The int is: %d. The float cast is: %f.\n", robert, (float)robert);
    printf("The int is: %d. The char cast is: %c.\n", robert, (char)robert);
    printf("The float is: %f. The double cast is: %lf.\n", bob, (double)bob);
    printf("The double is: %lf. The float cast is: %f.\n", bobert, (float)bobert);
    printf("The char is: %c. The int cast is: %d.\n", charBear, (int)charBear);
    printf("33 cast as a char is: %c.\n",(char)33);

    return 0;
}