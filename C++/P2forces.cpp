#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        string s;
        cin >> s;
        int so = -1;
        int n = 0, a = 0;
        int flag = 0;
        int f = 0;
        int x = 0;
        int m = 0,p=0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '+')
              {p++;  n++;}
            if (s[i] == '-')
            {
                n--;
                m++;
            }
            if (s[i] == '1')
            {
                if (n == 0)
                    flag = 1;
                if (f == 0 && a == n && so == 0)
                    flag = 1;
                a = n;
                so = 1;
                f = 0;
                x = i;
            }
            if (s[i] == '0')
            {
                if (n == 0)
                    flag = 1;
                if (f == 0 && a == n && so == 1)
                    flag = 1;
                if (so == 1 && ((i - x-1) == m)&&p==0)
                    flag = 1;
                if(n==1) flag=1;
                a = n;
                so = 0;
                f = 0;
                m = 0;
                p=0;
            }
            if (a > n)
            {
                f = 1;
            }
            if (flag == 1)
                break;
        }
        if (flag == 1)
            cout << "NO" << endl;
        if (flag == 0)
            cout << "YES" << endl;
    }
}