/*
Name: Atharva Keny
Roll No: 2204210
Date: 18/08/2023
Purpose: To take two character arrays and sort one using bubble sort and another using insertion sort. 
Also to find the union of these two sorted arrays and store it in another array which in turn should be sorted.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 11
void printarray(char arr[], int size) //Function prints the elements of an array in a single line
{
    int i;
    printf("Elements of the array:\n");
    for (i = 0; i < size; i++)//loop to traverse through elements of the array
    {
        putchar(arr[i]);
        printf(" ");
    }
    printf("\n");
}
void swap(char arr[], int i, int j)//Function to interchange the elements at the index i and j
{
    char temp;//temporary variable to store the value of one of the elements so that it doesn't get lost
    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
void bubble_sort(char arr[], int size)//Function to sort the array using bubble sort
{
    printf("\nBUBBLE SORT\n");
    int i, j;
    for (i = size - 1; i > 0; i--)//Outer loop signifies the number of times the array traversal will take place for swapping adjacent elements
    {
        for (j = 0; j < i; j++)//Inner loop swaps adjacent elements if the first element is greater than the second element
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr, j, j + 1);
            }
        }
        printarray(arr, size);
    }
}
void insertion_sort(char arr[], int size)//Function to sort the array using insertion sort
{
    printf("\nINSERTION SORT\n");
    int i, j;
    for (i = 1; i < size; i++)//Outer Loop runs size-1 times to created those many sorted subarrays till the whole array is not sorted
    {
        for (j = i - 1; j >= 0; j--)//Inner loop brings the current element to its correct position in the sorted subarray
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr, j, j + 1);
            }
            else
            {
                break;
            }
        }
        printarray(arr, size);
    }
}
void Union(char arr1[], char arr2[], char arr3[], int size1, int size2)
{
    //the first if else condition is to add one element to the third array
    int i = 0, j = 0, k = 0;
    if (arr1[i] < arr2[j])
    {
        arr3[k] = arr1[i];
        i++;
        k++;
    }
    else if (arr1[i] > arr2[j])
    {
        arr3[k] = arr2[j];
        j++;
        k++;
    }
    else
    {
        arr3[k] = arr1[i];
        i++;
        j++;
        k++;
    }
    while (i < size1 && j < size2)//the loop will go on till one of the array exhausts all its elements
    {
        //these if conditions are so that the union of the array gives a sorted array as an output
        if (arr1[i] < arr2[j])
        {
            if (arr3[k - 1] != arr1[i])//if element does not exist in arr3 it adds it to the array
            {
                arr3[k] = arr1[i];
                i++;
                k++;
            }
            else//if element already exists in the arr3
            {
                i++;
            }
        }
        else if (arr1[i] > arr2[j])
        {
            if (arr3[k - 1] != arr2[j])//if element does not exist in arr3 it adds it to the array
            {
                arr3[k] = arr2[j];
                j++;
                k++;
            }
            else//if element already exists in the arr3
            {
                j++;
            }
        }
        else
        {
            if (arr3[k - 1] != arr1[i])//if element does not exist in arr3 it adds it to the array
            {
                arr3[k] = arr1[i];
                i++;
                j++;
                k++;
            }
            else//if element already exists in the arr3
            {
                i++;
                j++;
            }
        }
    }
    //these two while conditions are to add the remaining elements of the unexhausted array to arr3
    while (i < size1)
    {
        if (arr3[k - 1] != arr1[i])//if element does not exist in arr3 it adds it to the array
        {
            arr3[k] = arr1[i];
            i++;
            k++;
        }
        else//if element already exists in the arr3
        {
            i++;
        }
    }
    while (j < size2)
    {
        if (arr3[k - 1] != arr2[j])//if element does not exist in arr3 it adds it to the array
        {
            arr3[k] = arr2[j];
            j++;
            k++;
        }
        else//if element already exists in the arr3
        {
            j++;
        }
    }
    printf("Union of the two sorted arrays:\n");
    printarray(arr3, k);
}
int main()
{
    printf("Enter array 1 size: \n");
    int size1, size2, i;
    char arr1[MAX_SIZE], arr2[MAX_SIZE], arr3[MAX_SIZE * 2];
    scanf("%d", &size1);//takes in size of first array as an input
    printf("Enter %d characters: ", size1);
    for (i = 0; i < size1; i++)//inputs the elements of the array
    {
        arr1[i] = getchar();
        if (arr1[i] == ' ' || arr1[i] == '\n')
        {
            i--;
        }
    }
    printarray(arr1, size1);
    bubble_sort(arr1, size1);//calls function to sort the array
    printf("Enter array 2 size: \n");
    scanf("%d", &size2);//takes in size of second array as an input
    printf("Enter %d characters: ", size2);
    for (i = 0; i < size2; i++)//inputs the elements of the array
    {
        arr2[i] = getchar();
        if (arr2[i] == ' ' || arr2[i] == '\n')
        {
            i--;
        }
    }
    printarray(arr2, size2);
    insertion_sort(arr2, size2);//calls function to sort the array
    Union(arr1, arr2, arr3, size1, size2);
}