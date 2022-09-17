#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void revstr(char *str1)
{
    // declare variable
    int i, len, temp;
    len = strlen(str1); // use strlen() to get the length of str string

    // use for loop to iterate the string
    for (i = 0; i < len / 2; i++)
    {
        // temp variable use to temporary hold the string
        temp = str1[i];
        str1[i] = str1[len - i - 1];
        str1[len - i - 1] = temp;
    }
}
char *print_any_base(unsigned long num, unsigned int base)
{
    char *returnStr = (char *)malloc(sizeof(char) * 15);

    int i = 0;

    while (num > 0)
    {
        char c;

        int remainder = num % base;

        if (remainder > 9)
        {
            c = (65 + (remainder - 10)) + '0';
        }
        else
        {
            c = '0' + remainder;
        }

        returnStr[i] = (char)c;
        i++;
        num = num / base;
    }
    revstr(returnStr);
    return returnStr;
}

int main()
{
    unsigned long test = 1234;
    unsigned int base = 16;
    char *result = print_any_base(test, base);

    printf("result is %s\n", result);
}
