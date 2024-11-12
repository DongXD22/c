#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int n,m,now=0;
    cin>>n>>m;
    vector<int> a(n);
    for(int i=0;i<n;i++) a[i]=i+1;
    while(n>0){
        if(n==1) {cout<<a[0]<<endl;return 0;}
        cout<<a[abs((now+m-1)%n)]<<" ";
        a.erase(a.begin()+abs((now+m-1)%n));
        now=abs((now+m-1)%n);
        n--;
    }
}