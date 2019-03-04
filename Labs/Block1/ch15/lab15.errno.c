/*
    Programmer: Grant Ogden
    Date: 3/4/2019
    Filename: lab15.errno.c
    Reason: To better understand the errno header file and its use
*/
#include<stdio.h>
#include<errno.h>
#include<string.h>
#include<math.h>

int main()
{
    FILE *fp;

    fp = fopen("/home/student/Class/Class1/Labs/Block1/ch12/Jabberwockky.txt","r");

    //feof(fp);
    if(errno)
    {
        int currentErrno = errno;
        perror("ERROR");

        fp = fopen("/home/student/solution.jpg","w");
    }
    if(errno)
    {
        int currentErrno = errno;
        printf("ERRNO: %d\nERROR: %s\n",currentErrno,strerror(currentErrno));
    }
    sqrt(-1);
    if(errno)
    {
        int currentErrno = errno;
        perror("ERROR");
    }

    return errno;
}