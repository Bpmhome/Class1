/*
    Programmer: Grant Ogden
    Date: 2/25/2019
    Filename: lab12.content_copy_char.c
    Reason: To better understand File IO
*/
#include<stdio.h>

int main()
{
    FILE *read_ptr;
    FILE *write_ptr;
    char input;
    
    read_ptr = fopen("/home/student/Class/Class1/Labs/Block1/ch12/Jabberwocky.txt", "r");
    write_ptr = fopen("/home/student/Class/Class1/Labs/Block1/ch12/testtext.txt", "w");

    if(read_ptr != NULL)
    {
        if(write_ptr != NULL)
        {
            while(!feof(read_ptr))
            {
                input = fgetc(read_ptr);
                if(input >= 8)
                {
                    fputc(input,write_ptr);
                }
            }
        }
        else
        {
            printf("ERROR WRITING TO FILE");
        }    
    }
    else
    {
        printf("ERROR READING FILE");
    }
    
    return 0;
}