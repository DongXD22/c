#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m,p=0,sum=0,f=1;
    cin>>n>>m;
    int a[100000],b[100000][2];
    string s[100000];
    for(int i=0;i<n;i++) {
        cin>>a[i]>>s[i];
    }
    for(int i=0;i<m;i++) {
        cin>>b[i][0],cin>>b[i][1];
    }
    for(int i=0;i<m;i++) {
        if(a[p]==1){
            f*=-1;
        }
        if(b[i][0]==0) {
            f*=-1;
        }
        sum=f*b[i][1];
        while(sum<0){
            sum+=n;
        }
        p=(p+sum)%n;
        f=1;
    }
    cout<<s[p];
}