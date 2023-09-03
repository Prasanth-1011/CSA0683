#include <stdio.h>
#include <string.h>

int main()
{
    char source[100], destination[100];
    int i;

    printf("Enter String to Copy : ");
    fgets(source, sizeof(source), stdin);

    if (source[strlen(source) - 1] == '\n')
        source[strlen(source) - 1] = '\0';

    for (i = 0; source[i] != '\0'; i++)
        destination[i] = source[i];
    destination[i] = '\0';

    printf("Copied String : %s\n", destination);
    return 0;
}
