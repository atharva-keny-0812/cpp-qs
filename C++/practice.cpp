#include <bits/stdc++.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
    // your code goes here
    int t;
    float n, x;
    cin >> t;
    while (t--)
    {
        char a = 97;
        cin >> n >> x;
        if (ceil(n / 2) < x)
        {
            cout << -1 << endl;
        }
        else
        {
            char c[(int)n];
            for (int i = 0; i < ceil(n / 2); i++)
            {
                c[i] = a;
                c[(int)n - i - 1] = a;
                if (x > 1)
                    a++;
                x--;
            }
            for (int i = 0; i < n; i++)
            {
                cout << c[i];
            }
            cout << endl;
        }
    }
    return 0;
}
