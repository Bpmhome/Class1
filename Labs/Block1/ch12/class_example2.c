#include<stdio.h>

int main()
{
    int num;
    FILE *fptr;
    fptr = fopen("/home/student/Class/Class1/Labs/Block1/ch12/Jabberwocky.txt","r");
    num = fgetc(fptr);

    while(num != EOF){
        putchar(num);
        num = fgetc(fptr);
    }
    fclose(fptr);
    return 0;
}