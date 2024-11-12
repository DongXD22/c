#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    string s[20];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    sort(s,s+n,[](string a,string b){
        return a+b>b+a;
    });
    for (int i = 0; i < n; i++) {
        cout << s[i];
    }
    cout << endl;
    return 0;
}