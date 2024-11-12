#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n,ans=1;
    cin>>n;
    vector<ll> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++){
        ans=((a[i]-i)*ans)%(int)(1e9+7);
    }
    cout<<ans<<endl;
    return 0;
}