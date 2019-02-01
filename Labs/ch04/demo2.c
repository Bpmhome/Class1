#include <stdio.h>

int main(void)
{

    FILE *fp;
    fp = fopen("demo2.txt","a");
	int userInput = 0;
	printf("Enter a character:  ");
	userInput = getc(stdin);
	printf("Your character was:  ");
	putc(userInput,stdout);
    putc(userInput, fp);
    printf("\n");

    fclose(fp);
	return 0;
}