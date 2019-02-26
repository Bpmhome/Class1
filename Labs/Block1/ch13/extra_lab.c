/*
(Dynamic Array Allocation) Write a program that dynamically allocates an array of integers.
The size of the array should be input from the keyboard. The elements of the array should be
assigned values input from the keyboard. Print the values of the array. Next, reallocate the memory
for the array to 1/2 of the current number of elements. Print the values remaining in the array to
confirm that they match the first half of the values in the original array.

*/
#include <stdio.h>
#include <stdlib.h>

int main( void )
{ 
    unsigned int numberOfElements;  // number of elements in array
    unsigned int count; // loop counter
    int *int_ptr = NULL;  // pointer to the array
   
    // prompt user and read integer size of array
    printf( "This program dynamically allocates an array of integers.\nEnter the number of elements in the array: " );
    scanf("%u", &numberOfElements); // missing info in scanf
   
    // dynamically allocate memory
    int_ptr = calloc(numberOfElements,sizeof(int));
   
    // initialize elements of array with user-entered data
    for (int i = 0; i < numberOfElements; i++) 
    { 
        printf("Enter an integer: ");
        scanf("%d", (int_ptr + i));
    } // end for

    puts( "\nThe elements of the array are:" );
    
    // display the original array
    for (int i = 0; i < numberOfElements; i++) {
       printf("%d ",*(int_ptr + i));
    } // end for

    // reallocate to half the original size
    int_ptr = realloc(int_ptr,(numberOfElements / 2));

    puts( "\n\nThe elements of the array after reallocation are:" );
    
    // display array after cut in half
    for (int i = 0; i < (numberOfElements / 2); i++) {
       printf("%d ", *(int_ptr + i));
    } // end for

    puts( "" );

    free(int_ptr);
} // end main

/* OUTPUT
This program dynamically allocates an array of integers.
Enter the number of elements in the array: 10
Enter an integer: 1
Enter an integer: 2
Enter an integer: 3
Enter an integer: 4
Enter an integer: 5
Enter an integer: 6
Enter an integer: 7
Enter an integer: 8
Enter an integer: 9
Enter an integer: 10

The elements of the array are:
1 2 3 4 5 6 7 8 9 10

The elements of the array after reallocation are:
1 2 3 4 5


*/