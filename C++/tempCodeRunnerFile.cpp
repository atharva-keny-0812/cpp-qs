#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n,x=0,max=0;
    cin>>n;
    int a[n],b[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n-1;i++)
    {
        if(a[i]>a[i+1]) max=i;
    }
    if(a[max]==1) x=2;
    else x=1;
    for(int i=0;i<n;i++)
    {
        b[i]=a[i];
    }
    b[max]=x;
    sort(b,b+n);
    for(int i=0;i<n;i++)
    {
        if(a[i]<=b[i])
        cout<<a[i]<<" ";
        else cout<<b[i]<<" ";
    }
    cout<<endl;
    return 0;
}
