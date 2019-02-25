#include<stdio.h>

int main()
{
    FILE *pFile;
    char input[81];

    pFile = fopen("/home/student/Class/Class1/Labs/Block1/ch12/Jabberwocky.txt","r");

    if(pFile != NULL)
    {
        //process files
        while(!feof(pFile))
        {
            fgets(input, 81, pFile);
            printf("%s",input);
        }


        fclose(pFile);
    }
    else
    {
        //IO ERROR
        printf("IO ERROR: Problem with file");
    }
    
    printf("\n");
    return 0;
}