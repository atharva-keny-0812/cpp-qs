/*
Name: Atharva Keny and Dhriti Gupta
Roll No: 2204210 and 2206312
Date: 30/08/2023
Purpose: To perform various functions on given strings
*/
#include <stdio.h>
#include <stdbool.h>
int length(char str[])//Function to get length of character array
{
    int i = 0;
    while (str[i] != '\0')//terminates if string character is null
    {
        i++;
    }
    return i;
}
void print(char str[])//Function to print the given character array
{
    int i = 0;
    while (str[i] != '\0')
    {
        printf("%c", str[i]);//prints each character one by one
        i++;
    }
}
bool is_same(char str1[], char str2[])//Function to check if two given strings are the same or not
{
    if (length(str1) != length(str2))//First checks if their length is same or not
    {
        return false;
    }
    for (int i = 0; i < length(str1); i++)
    {
        if (str1[i] != str2[i])// Checks each character
        {
            return false;
        }
    }
    return true;
}
bool str_copy(char source[], char dest[])//Function to copy one string from one array to another and check if the copy was successful
{
    int i;
    for (i = 0; i < length(source); i++)
    {
        dest[i] = source[i];//copies each character one by one from source to destination
    }
    dest[i] = '\0';
    if (is_same(source, dest))//Checks if source and destination are same
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool is_suffix(char str[], char suf[])//Function to check if given suffix string is suffix of the given string
{
    int i = length(str) - length(suf);
    int j = 0;
    while (suf[j] != '\0' && str[i] != '\0')
    {
        if (suf[j] != str[i])//Checks the characters one by one starting from the correct index
        {
            return false;
        }
        i++;
        j++;
    }
    if (str[i] == '\0' && suf[j] != '\0')
    {
        return false;
    }
    else
    {
        return true;
    }
}
bool is_substring(char str[], char substr[])//Function to check if given substring is substring of the given string
{
    int flag = 1;
    if (length(substr) > length(str))
    {
        return false;
    }
    for (int i = 0; i <= length(str) - length(substr); i++)//outer loop iterates through every array element
    {
        for (int j = 0; j < length(substr); ++j)//for each starting point inner loop checks if substring exists over there or not
        {
            flag = 1;
            if (str[i + j] != substr[j])
            {
                flag = 0;//to tell that substring doesnt exist
                break;
            }
        }
        if (flag == 1)//this means substring exists
        {
            return true;
        }
    }
    return false;
}
bool get_suffix(char str[], char suf[], int len)//Function to get suffix of length len from the given string
{
    if (len > length(str))
    {
        return false;
    }
    int i, j = 0;
    for (i = length(str) - len; i < length(str); i++)
    {
        suf[j] = str[i];//copies the suffix characters one by one
        j++;
    }
    suf[len] = '\0';
    j = 0;
    for (i = 0; i < len; i++)//checks if suffix is correctly copied
    {
        if (suf[i] != str[length(str) - len + j])
        {
            return false;
        }
        j++;
    }
    return true;
}
bool get_substring(char str[], char substr[], int start, int len)//Function to get substring of length len of starting index start from the given string
{
    if (start + len > length(str))
    {
        return false;
    }
    int i, j = 0;
    for (i = start; i < len + start; i++)
    {
        substr[j] = str[i];//copies the substring characters one by one
        j++;
    }
    substr[len] = '\0';
    j = 0;
    for (i = 0; i < len; i++)//checks if substring is correctly copied
    {
        if (substr[i] != str[start + j])
        {
            return false;
        }
        j++;
    }
    return true;
}
void concatenate(char str1[], char str2[], char str3[])//Function to concatenate two strings and store it in third one
{
    int i;
    for (i = 0; i < length(str1); i++)//copies elements of first string in third string
    {
        str3[i] = str1[i];
    }
    int j;
    for (j = 0; j < length(str2); j++)//copies elements of second string in third string
    {
        str3[i] = str2[j];
        i++;
    }
    str3[i] = '\0';
}
void convert_to_upper(char str[])//Function to convert all characters of string to upper case
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] >= 97 && str[i] <= 122)//only if it is a lower case alphabet will this cod block run
        {
            str[i] = str[i] - 32;//subtracts the ascii value by correct amount to get upper case value 
        }
        i++;
    }
}
void break_into_words(char str[] , char words[][1000])
{
    int i = 0,word_i=0,word_letter_i=0;//i for string, word_i for each word, word_letter for letters of each word

    for(i=0;i<length(str);i++)
    {
        if (str[i]==' ')//If character is white space we break the word
        { 
            words[word_i][word_letter_i] = '\0';     //terminate each word with null character
            word_i++;
            word_letter_i=0; //once word gets over letter index becomes 0
        }
        else
        {
            words[word_i][word_letter_i] = str[i];   //Adding characters of each word one by one
            word_letter_i++;
        }
    }

    word_i++;
    words[word_i][0]='\0';
    i = 0;
    char end[]= "\0";
    //printing the array of words
    printf("Print the list of words:\n");
    while(!is_same(words[i],end)){ 
        print(words[i]);
        printf("\n");
        i++;
    }

    return;
}
int main()
{
    //Calling function str_copy
    char source[1000];
    printf("Enter Source string: ");
    fgets(source, 1000, stdin);
    char dest[1000];
    printf("Calling str_copy on input source:   ");
    print(source);
    printf("\n");
    if (str_copy(source, dest))
    {
        printf("Destination:   ");
        print(dest);
    }
    else
    {
        printf("An error occurred");
    }
    printf("\n\n");

    //Calling function is_suffix
    char str[] = "Hello\0";
    char suf[] = "llo\0";
    printf("Calling is_suffix on input string:   ");
    print(str);
    printf("\n");
    printf("To check if it has suffix:   ");
    print(suf);
    printf("\n");
    if (is_suffix(str, suf))
    {
        print(suf);
        printf(" is a suffix of ");
        print(str);
    }
    else
    {
        print(suf);
        printf(" is not a suffix of ");
        print(str);
    }
    printf("\n\n");

    //Calling Function is_substring
    char str1[] = "Hello\0";
    char substr[] = "hi\0";
    printf("Calling is_substring on input string:   ");
    print(str1);
    printf("\n");
    printf("To check if it has substring:   ");
    print(substr);
    printf("\n");
    if (is_substring(str1, substr))
    {
        print(substr);
        printf(" is a substring of ");
        print(str1);
    }
    else
    {
        print(substr);
        printf(" is not a substring of ");
        print(str1);
    }
    printf("\n\n");

    // Calling function get_suffix
    char str2[] = "Hello\0";
    char suf1[100];
    printf("Calling get_suffix on input string:   ");
    print(str2);
    printf("\n");
    printf("To get suffix of length 3");
    if (get_suffix(str2, suf1, 3))
    {
        printf("Suffix is: ");
        print(suf1);
    }
    else
    {
        printf("Something went Wrong");
    }
    printf("\n\n");

    //Calling fucntion get_substring 
    char str3[] = "Hello\0";
    char substr2[100];
    printf("Calling get_substring on input string:   ");
    print(str3);
    printf("\n");
    printf("To get substring of length 3 from index 1\n");
    if (get_substring(str3, substr2, 1, 3))
    {
        printf("Substring is: ");
        print(substr2);
    }
    else
    {
        printf("Something went Wrong");
    }
    printf("\n\n");

    //Calling Function is_same 
    char str4[] = "Hello\0";
    char str5[] = "Hi\0";
    printf("Calling is_same to check inputs: ");
    print(str4);
    printf(" and ");
    print(str5);
    printf("\n");
    if (is_same(str4, str5))
    {
        print(str4);
    printf(" and ");
    print(str5);
    printf(" are same");
    }
    else
        printf("%s and %s are not same\n", str4, str5);

    printf("\n\n");

    // Calling Function concatenate
    char str6[] = "Hello\0";
    char str7[] = "Hi\0";
    char str8[100];
    printf("Calling concatenate to concatenate: ");
    print(str6);
    printf(" and ");
    print(str7);
    printf("\n");
    concatenate(str6, str7, str8);
    printf("Concatenated string: ");
    print(str8);
    printf("\n\n");

    // Calling Function convert_to_upper
    char str9[] = "Hi everyone\0";
    printf("Calling convert_to_upper to convert all characters of string ");
    print(str9);
    printf(" to uppercase\n");
    convert_to_upper(str9);
    printf("Uppercase String: ");
    print(str9);
    printf("\n\n");
    
    // Calling Function break_into_words 
    char str10[] = "Hello how are you";
    printf("Calling break_into_words on string: ");
    print(str10);
    printf("\n");
    printf("To break the string into its words.\n");
    char words[50][1000];
    break_into_words(str10, words);
    return 0;
}

