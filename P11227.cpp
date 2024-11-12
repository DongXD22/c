#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    set<string> s;
    string t;
    int n;
    cin>>n;
    for(int i;i<n;i++){
        cin>>t;
        s.insert(t);
    }
    cout<<52-s.size()<<endl;
}