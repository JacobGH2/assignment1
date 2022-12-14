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
    if (base > 36)
    {
        printf("Illegal base\n");
        return NULL;
    }
    if (num == 0)
    {
        returnStr[0] = '0';
        return returnStr;
    }
    int i = 0;

    while (num > 0)
    {
        char c;

        int remainder = num % base;

        if (remainder > 9)
        {
            c = (65 + (remainder - 10)) + '\0';
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

unsigned int count_vowels(char *str)
{

    int numVowels = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == 'a' || str[i] == 'e' ||
            str[i] == 'i' || str[i] == 'o' ||
            str[i] == 'u' || str[i] == 'A' ||
            str[i] == 'E' || str[i] == 'I' ||
            str[i] == 'O' || str[i] == 'U')
        {
            numVowels++;
        }
    }
    return numVowels;
}

char *reverse_words(char *str)
{
    if (str[0] == '\0')
        return "";
    char **wordList;
    int i = 0;
    int wordListIndex = 0;
    while (str[i] != '\0')
    {
        int k = 0;
        char *currentStr;
        while (str[i] != ' ' || str[i] != '\0')
        {
            currentStr[k] = str[i];
            k++;
            i++;
        }
        i++;
        wordList[wordListIndex] = currentStr;
        wordListIndex++;
    }
    char *returnStr;
    int size = sizeof(wordList) / sizeof(wordList[0]);
    returnStr = wordList[0];
    for (int m = 1; m < size; m++)
    {
        char *space = " ";
        strncat(returnStr, space, 1);
        strncat(returnStr, wordList[1], 100);
    }
    return returnStr;
}

int main()
{
    /*
    // problem 1
    unsigned long test = 1234;
    unsigned int base = 37; // come back for free
    char *result = print_any_base(test, base);

    printf("result is %s\n", result);
    free(result);
    */
    /*
    // problem 2
    char *p2str = "aeiouAEIOU";
    unsigned int p2result = count_vowels(p2str);
    printf("%i\n", p2result);
    */

    // problem 3
    char *p3str = "Hello World";
    char *p3result = reverse_words(p3str);
    printf("%s\n", p3result);
}
