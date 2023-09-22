#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void bubbleSort(int arr[],int s[], int n)
{
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swap(&s[j], &s[j+1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
}
int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        int k = 0;
        int d[n], s[n];
        unordered_map<int, int> map;
        for (int j = 0; j < n; j++)
        {
            cin >> d[j] >> s[j];
        }
        bubbleSort(d,s,n);
        if (s[0] % 2 == 1)
            k = d[0] + (s[0] / 2);
        else
            k = d[0] + (s[0] / 2) - 1;
        for (int j = 1; j < n; j++)
        {
            if (s[j] % 2 == 1)
            {
                if (d[j] + (s[j] / 2) < k)
                    k = d[j] + (s[j] / 2);
            }
            else
            {
                if (d[j] + (s[j] / 2) -1< k)
                    k = d[j] + (s[j] / 2) - 1;
            }
        }
        cout << k << endl;
    }
}