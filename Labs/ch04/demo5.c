#include <stdio.h>

int main()
{
    char buffer[200] = {0};

    printf("Please input your string: ");
    //scanf("%64[^e\n]s", buffer);     // Stops reading at first e or newline
    scanf("%199[^[A-Z\n]]s",buffer);
    printf("Your string is:\n");
    printf("%s\n",buffer);

    return 0;
}