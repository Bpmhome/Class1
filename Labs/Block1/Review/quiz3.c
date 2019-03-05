#include <stdio.h>
#include <ctype.h>

int main()
{
    char phrase[250] = {0};
    FILE *fp;


    int index,alpha,blank,punct,upper,lower;

    alpha = blank = punct = upper = lower = index = 0;

    fp = fopen("/home/student/Class/Class1/Labs/Block1/Review/lorem_ipsum.txt","r");
    if(fp == NULL)
    {
        return 1;
    }
    // gather data
    while(!feof(fp))
    {
        fgets(phrase,249,fp);
        while(phrase[index])
        {
            if(isalpha(phrase[index]))
            {
                alpha++;

                if(isupper(phrase[index]))
                {
                    upper++;
                }
                else
                {
                    lower++;
                }
            }
            if(isblank(phrase[index]))
            {
                blank++;
            }
            if(ispunct(phrase[index]))
            {
                punct++;
            }
            index++;
        }
        index = 0;
    }

    // print results
    printf("\"%s\"\n",phrase);
    puts("Statistics:");
    printf("%d alphabetic characters\n",alpha);
    printf("\t%d upper case\n",upper);
    printf("\t%d lower case\n",lower);
    printf("%d blanks\n",blank);
    printf("%d punctuation symbols\n",punct);

    return(0);
}
