#include <stdio.h>
#include <string.h>

void reverseString(char str[])
{
    int length = strlen(str);
    for (int i = length - 1; i >= 0; i--)
        printf("%c", str[i]);
}

int main()
{
    char input[100];
    printf("Enter String: ");
    scanf("%s",input);

    printf("Reverse String : ");
    reverseString(input);

    return 0;
}
