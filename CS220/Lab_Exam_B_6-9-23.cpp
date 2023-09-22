#include <stdio.h>
#include <stdlib.h>
#define MAX_WORDS 50
#define MAX_LENGTH 100

int strLen(char *str)
{
    int i = 0;
    while (*(str + i) != '\n'&&*(str + i) != '\0')
    {
        i++;
    }
    return i;
}

void strCopy(char *strOriginal, char **strDuplicate)
{
    int length = strLen(strOriginal);
    char *duplicate = (char *)malloc(MAX_LENGTH * sizeof(char));
    for (int i = 0; i < length; i++)
    {
        *(duplicate + i) = *(strOriginal + i);
    }
    *strDuplicate = duplicate;
}

int breakIntoWords(char *original, char ***broken)
{
    int length = strLen(original);
    int j = 0, k = 0;
    for (int i = 0; i < length; i++)
    {
        char*word=(char*)malloc(MAX_LENGTH*sizeof(char));
        //char word[MAX_LENGTH];
        char **duplicate = (char **)malloc(1 * sizeof(char *));
        if ((*(original + i) == ' ' || *(original + i) == '\n' || *(original + i) == '\t' || *(original + i) == '\0') && (j != 0))
        {
            realloc(word,j*sizeof(char));
            strCopy(word, duplicate);
            j = 0;
            *(broken + k) = duplicate;
            k++;
            continue;
        }
        if (*(original + i) != ' ' && *(original + i) != '\n' && *(original + i) != '\t' && *(original + i) != '\0')
        {
            *(word + j) = *(original + i);
            j++;
        }
    }
    return ++k;
}

int main()
{
    char original[MAX_LENGTH*MAX_WORDS];
    fgets(original,MAX_LENGTH*MAX_WORDS,stdin);
    char ***broken = (char ***)malloc(MAX_WORDS * sizeof(char **));
    int no_of_words = breakIntoWords(original, broken);
    char **duplicate = (char **)malloc(1 * sizeof(char *));
    printf("%d", no_of_words);
    printf("\n");
    for(int i=0;i<no_of_words;i++)
    {
        // int len=strLen(**(broken+i));
        // printf("%d\n",len);
        // for(int j=0;j<len;j++)
        printf("%c",*(**broken+i));
        printf("\n");
    }
}