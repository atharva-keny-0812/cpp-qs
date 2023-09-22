#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    char t;
    for (int i=0; i<n; i++) {
        cin >> s;
        t = s[0];
        if (t == '1') {
            cout << "13" << endl;
        } else if (t == '2') {
            cout << "23" << endl;;
        } else if (t == '3') {
            cout << "31" << endl;;
        } else if (t == '4') {
            cout << "43" << endl;;
        } else if (t == '5') {
            cout << "53" << endl;;
        } else if (t == '6') {
            cout << "67" << endl;;
        } else if (t == '7') {
            cout << "71" << endl;;
        } else if (t == '8') {
            cout << "83" << endl;;
        } else if (t == '9') {
            cout << "97" << endl;;
        } 
    }
}