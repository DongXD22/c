#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int n,m,temp;
    cin>>n>>m;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        cin>>temp;
        cout<<a[temp]<<endl; 
    }
}