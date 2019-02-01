#include <stdio.h>

int main(void)
{
	int integer = 1;
	float singlePrecision = 2.2;
	double doublePrecision = 3.3;
	char singleChar = '$';
	char singleChar2 = 33;
	
	printf("Your integer is %d \n", integer);
	printf("Your float is %f \n", singlePrecision);
	printf("Your double is %lf \n", doublePrecision);
	printf("Your first char is %c \n", singleChar);
	printf("Your second char is %c \n", singleChar2);  

	return 0;
}