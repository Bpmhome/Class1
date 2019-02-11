#include <stdio.h>

int main(void)
{

    FILE *fp;
    fp = fopen("demo3.txt","w");
	char buff[4];
	printf("Enter a string:      ");
	fgets(buff, sizeof(buff), stdin);
	printf("Your string was:  ");
	puts(buff);
    fputs(buff,fp);
    fclose(fp);
    
	return 0;
}