/*
Name: Atharva Keny
Roll No: 2204210
Date: 30/08/2023
Purpose: To check if a string is a palindrome using pointers
*/
#include <stdio.h>
#include <stdlib.h>

int length(char *ptr) // Function to find length of string
{
    int i = 0;
    while (*(ptr + i) != '\0' && *(ptr + i) != '\n' && *(ptr + i) != '\t') // Terminates the length counting if any of these characters occur
    {
        i++;
    }
    return i;
}
char *strReverse(char *ptr) // Function to return pointer to the reverse string
{
    int n = length(ptr), i;
    char *ptrrev = (char *)malloc((n + 1) * sizeof(char)); // allocates memory to pointer of reverse string
    for (i = 0; i < n; i++)
    {
        *(ptrrev + i) = *(ptr + n - i - 1); // assigns characters from reverse of the original string to the reverse string
    }
    *(ptrrev + n) = '\0';
    return ptrrev;
}
bool isPalindrome(char *ptr) // Function to check if string is palindrome or not
{
    int n = length(ptr), i;
    char *ptrrev = strReverse(ptr);
    for (i = 0; i < n; i++) // Function to check each character of string one by one
    {
        if (*(ptrrev + i) != *(ptr + i)) // If any character is unequal it returns 0
            return 0;
    }
    return 1;
}
int main()
{
    char **strarr = (char **)malloc(4 * sizeof(char *)); // 2D pointer array to store 4 strings and check if they are palindrome one by one
    if (strarr == NULL)
    {
        printf("Memory cannot be allocated\n");
        exit(0);
    }
    printf("Enter 4 strings:\n\n");
    int i;
    for (i = 0; i < 4; i++)
    {
        char *arr = (char *)malloc(100 * sizeof(char));
        if (arr == NULL)
        {
            printf("Memory cannot be allocated\n");
            exit(0);
        }
        *(strarr + i) = fgets(arr, 100, stdin);                                      // inputs strings one by one
        printf("The reverse string is as follows: %s\n", strReverse(*(strarr + i))); // prints reverse string
        if (isPalindrome(*(strarr + i)))                                             // prints if string is palindrome or not
            printf("The string is a Palindrome\n\n");
        else
            printf("The string is not a Palindrome\n\n");
        free(arr);
        arr = NULL;
    }
    free(strarr);
    strarr = NULL;
    return 0;
}