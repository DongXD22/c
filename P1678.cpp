#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
int main(){
    ll m,n,ans=0;
    set<ll> lin;
    cin>>m>>n;
    for(ll i=0;i<m;i++){
        ll x;
        cin>>x;
        lin.insert(x);
    }
    for(ll i=0;i<n;i++){
        ll x;
        cin>>x;
        auto lb=lin.lower_bound(x);
        if(lb==lin.end()){
            ans+=abs(x-*(--lb));
        }
        else{
            auto next=lb;
            lb--;
            if(abs(*lb-x)>abs(*next-x)){
                ans+=abs(x-*next);
            }
            else{
                ans+=abs(x-*lb);
            }
        }
    }
    cout<<ans<<endl;
}