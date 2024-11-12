#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll ans=0;
vector<ll> v;
set<ll> s;
void solve(ll res,ll mx){
    if(res==0){
        int ans=0;
        for(ll i=0;i<v.size();i++){
            for(int j=i+1;j<v.size();j++){
                ans+=v[i]*v[j];
            }
        }
        s.insert(ans);
        return;
    }
    for(ll i=mx;i>=1;i--){
        v.push_back(i);
        solve(res-i,min(i,res-i));
        v.pop_back();
    }
}
int main(){
    ll n;
    cin>>n;
    solve(n,n);
    cout<<s.size()<<endl;
    return 0;
}