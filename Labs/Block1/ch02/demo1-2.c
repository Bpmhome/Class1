#include <stdio.h>

int main(void)
{
	int integer = 1;
	float singlePrecision = 2.2;
	double doublePrecision = 3.3;
	char singleChar = '$';
	char singleChar2 = 33;
	
	printf("Size of int is %d \n", sizeof(integer));
	printf("Size of float is %d \n", sizeof(singlePrecision));
	printf("Size of double is %d \n", sizeof(doublePrecision));
	printf("Size of char 1 is %d \n", sizeof(singleChar));
	printf("Size of char 2 is %d \n", sizeof(singleChar2));
	
	return 0;
}