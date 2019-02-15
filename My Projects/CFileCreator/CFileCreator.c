/*
    Programmer: Grant Ogden
    Date: 2/14/2019
    Project: C File Creator
    Reason: To be lazy and have a program create my files for me
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#define ERR_NULL_POINTER (-1)
#define ERR_FILE_IO (-2)
#define ERR_FILE_PATH_LENGTH (-3)
#define MAX_FILE_PATH_LENGTH (260)
#define MAX_FILE_NAME_LENGTH (50)

char globalFilePath[310] = {0};
FILE *fp;

extern int write_c_files()
{
    time_t now = time(NULL);
    struct tm tm = *localtime(&now);
    

    fprintf(fp,"/*\n\tProgrammer: Grant Ogden\n\tDate: %d-%d-%d\n\tProject:%s\n\tReason:\n*/\n",tm.tm_mon + 1,tm.tm_mday,tm.tm_year + 1900,globalFilePath);
    fprintf(fp,"#include <stdio.h>\n\nint main()\n{\n\t\t//Variable Decleration\n\n");
    fprintf(fp,"\t\t//Functions called here\n\n\treturn 0;\n}");
    return 0;
}

extern int write_h_files(char * fileName)
{
    char nameArry[strlen(fileName)];
    for(int i = 0; i < strlen(fileName); i++)
    {
        nameArry[i] = fileName[i];
    }
    
    time_t now = time(NULL);
    struct tm tm = *localtime(&now);
    for(int i = 0; i < strlen(nameArry); i++)
    {
        if(nameArry[i] >= 97 && nameArry[i] <= 122)
        {
            nameArry[i] = toupper(nameArry[i]);
        }
        else if(nameArry[i] == ' ')
        {
            nameArry[i] = '_';
        }
        else if(nameArry[i] == '.')
        {
            for(int j = i; j < strlen(nameArry); j++)
            {
                nameArry[i] = ' ';
            }
            break;
        }
    }
    
    fprintf(fp,"/*\n\tProgrammer: Grant Ogden\n\tDate: %d-%d-%d\n\tProject:%s\n\tReason:\n*/\n",tm.tm_mon + 1,tm.tm_mday,tm.tm_year + 1900,globalFilePath);
    fprintf(fp,"#ifndef %s\n",nameArry);
    fprintf(fp,"#define %s\n\n\n",nameArry);
    fprintf(fp,"/*\n * FUNCTION:\t\n * ARGUEMENTS:\t\n * RETURN:\t\t\n * NOTES:\t\t\n */\n\n\n");
    fprintf(fp,"#endif");

    fclose(fp);
    globalFilePath[strlen(globalFilePath) - 1] = 'c';
    fp = fopen(globalFilePath,"w");
    if(fp != NULL)
    {
        fprintf(fp,"/*\n\tProgrammer: Grant Ogden\n\tDate: %d-%d-%d\n\tProject:%s\n\tReason:\n*/\n",tm.tm_mon + 1,tm.tm_mday,tm.tm_year + 1900,globalFilePath);
    }
    else
    {
        return ERR_FILE_IO;
    }
    
    return 0;
}


extern int write_files(char * fileName)
{
    char fileType = 0;
    fileType = globalFilePath[strlen(globalFilePath) - 1];
    //printf("%c\n",fileType);
    if(fileType == 'c')
    {
        write_c_files();
        fclose(fp);
        printf("MAIN FILES CREATED\n");
    }
    else if(fileType == 'h')
    {
        write_h_files(fileName);
    }
    return 0;
}

extern int open_file(char * filePath,char * fileName)
{
    if(!filePath || !fileName)
    {
        return ERR_NULL_POINTER;
    }
    else if(strlen(filePath) == 0 || strlen(filePath) >= 260)
    {
        return ERR_FILE_PATH_LENGTH;
    }

    for(int i = 0; i < strlen(filePath); i++)
    {
        globalFilePath[i] = filePath[i];
    }
    for(int i = strlen(filePath),x = 0; i < (strlen(fileName)+strlen(filePath)); i++,x++)
    {
        //printf("%c\n",fileName[x]);
        globalFilePath[i] = fileName[x];
    }
    //printf("%s\n",globalFilePath);
    fp = fopen(globalFilePath,"w");
    if(fp != NULL)
    {
        printf("FILES OPENED\n");
        if(write_files(fileName))
        {
            return -5;
        }
    }
    else
    {
        printf("ERROR\n");
        return ERR_FILE_IO;
    }
    


    return 0;
}

extern int create_project(char *filePath,char * fileName)
{
    struct stat st = {0};
    char tempArry[strlen(globalFilePath) - 2];
    for(int i = 0; i < (strlen(globalFilePath) - 2); i++)
    {
        tempArry[i] = globalFilePath[i];
        printf("%c",tempArry[i]);
    }
    tempArry[strlen(tempArry)] = '/';
    
    if(stat(tempArry,&st) == -1)
    {
        mkdir(tempArry,0700);
    }
    return 0;
}