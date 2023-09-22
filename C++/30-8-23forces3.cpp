#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int n;
        cin>>n;
        int arr[n],c=0;
        unordered_map<int,int> m;
        for(int j=0;j<n;j++)
        {
            cin>>arr[j];
            m[arr[j]]=j;
        }
        for(int j=1;j<n;j++)
        {
            if(m[j]>m[j+1])
            {
                c++;
            }
        }
        cout<<c<<endl;
    }
}