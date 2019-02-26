/*
    Programmer: Grant Ogden
    Date: 2/25/2019
    Filename: lab12.might_morphin.c
    Reason: To better understand File IO
*/
#include<stdio.h>

int main()
{
    FILE *read_ptr;                                     //File pointer for opening a read file
    char input;                                         //char variable for holding the char to write into the file
    

    //opening the file
    read_ptr = fopen("/home/student/Class/Class1/Labs/Block1/ch12/MightyMorphin.txt", "r");

    if(read_ptr != NULL)                                //If the read file opened
    {
        while(!feof(read_ptr))                          //While we are not at the end of field on the read file
        {
            input = fgetc(read_ptr);                    //Pull the char from the read file
            if(input >= 8)                              //If the char is a writeable character
            {
                fputc(input,stdout);                    //Write it
            }
        }  
    }
    else
    {
        printf("ERROR READING FILE");                   //Print read file ERROR
    }
    
    return 0;
}