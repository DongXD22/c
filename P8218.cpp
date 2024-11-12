#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int n,a[100005],temp,m1,m2,m;
    cin>>n;
    a[0]=0;
    cin>>a[1];
    for(int i=2;i<n+1;i++){
        cin>>temp;
        a[i]=a[i-1]+temp;
    }
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>m1>>m2;
        cout<<a[m2]-a[m1-1]<<endl;
    }
    return 0;
}