#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
   ll int T,n,k;
   cin>>T;
   for(int i=1;i<=T;i++){
        cin>>n>>k;
        if(n==1)cout<<1<<endl;
        else{
            ll int a=n/(k+1)+1;
            ll int b=n/k;
            cout<<b-a+1<<endl;
        }
   }
   return 0;
}