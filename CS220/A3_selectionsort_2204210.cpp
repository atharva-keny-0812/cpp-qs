/*
Name: Atharva Keny
Roll No: 2204210
Date: 18/08/2023
Purpose: To take an array of random integers from 0 to 99 and sort it using selection sort. 
Also to check how many array elements are between 10 and 90.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10
void printarray(int arr[], int size) //Function prints the elements of an array in a single line
{
    int i;
    printf("Elements of the array:\n");
    for (i = 0; i < size; i++)//loop to traverse through elements of the array
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void swap(int arr[], int i, int j)//Function to interchange the elements at the index i and j
{
    int temp;//temporary variable to store the value of one of the elements so that it doesn't get lost
    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
void selection_sort(int arr[], int size)//Function to sort the array using selection sort
{
    int i, j, min_index;
    for (i = 0; i < size - 1; i++)//Outer loop goes through the indexes one by one so that the minimum element can be swapped with the current element
    {
        min_index = i;
        for (j = i + 1; j < size; j++)//Inner loop finds the minimum element
        {
            if (arr[min_index] > arr[j])
            {
                min_index = j;
            }
        }
        swap(arr, i, min_index);
        printarray(arr, size);
    }
}
int main()
{
    srand(time(0));//generates random seed for rand function
    int i, arr[N], count = 0;
    for (i = 0; i < N; i++)
    {
        arr[i] = ((float)rand() / (float)RAND_MAX) * 99;//Generates a random number from 0 to 99 
    }
    printarray(arr, N);
    selection_sort(arr, N);
    for (i = 0; i < N; i++)//loop to check which elements of array lie between 10 and 90
    {
        if (arr[i] > 10 && arr[i] < 90)
        {
            count++;
        }
    }
    printf("Number of elements between 10 and 90: %d", count);
}