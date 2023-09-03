#include <stdio.h>
#include <string.h>

int Palindrome(char s[])
{
    int length = strlen(s);
    int i,j;

    for (i=0,j=length-1;i<j;i++,j--)
        if (s[i] != s[j])
            return 0;
    return 1;
}

int main()
{
    char s[100];

    printf("Enter String : ");
    scanf("%s", s);

    if (Palindrome(s))
        printf("The String is a Palindrome");
    else
        printf("The String is Not a Palindrome");
    return 0;
}