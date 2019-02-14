/*
    Programmer: Grant Ogden
    Date: 1/29/2019
    FileName: ch02_labB.c
    Reason: For a deeper understanding of type casting and example
*/
#include<stdio.h>

int main()
{
    //Decleration and Initialization of Variables
    int robert = 125;
    float bob = 1.23;
    double bobert = 3.654516546156;
    char charBear = 'R';

    printf("The int is: %d. The float cast is: %f.\n", robert, (float)robert);          //int:  125 float:  125.000000
    printf("The int is: %d. The char cast is: %c.\n", robert, (char)robert);            //int:  125 char:   }    
    printf("The float is: %f. The double cast is: %lf.\n", bob, (double)bob);           //float: 1.230000   double: 1.230000
    printf("The double is: %lf. The float cast is: %f.\n", bobert, (float)bobert);      //double:3.654517   float:  3.654516
    printf("The char is: %c. The int cast is: %d.\n", charBear, (int)charBear);         //char: R   int:    82
    printf("33 cast as a char is: %c.\n",(char)33);                                     //int:  33  char:   !

    return 0;
}