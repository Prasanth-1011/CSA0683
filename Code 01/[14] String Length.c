#include <stdio.h>

int stringLength(const char* str)
{
    int length = 0;
    while (str[length] != '\0')
        length++;
    return length;
}

int main()
{
    const char* myString = "Barcelona";
    int length = stringLength(myString);
    printf("String : %s \nLength : %d\n",myString,length);
    return 0;
}