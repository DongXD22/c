#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll con(ll n,ll m){
    ll ans=1;
    for(int i=m;i>m-n;i--){
        ans*=i;
    }
    for(int i=2;i<=n;i++){
        ans/=i;
    }
    return ans;
}
int main(){
    vector<ll> p;
    ll x,y;
    bool isp[320];
    fill(isp,isp+319,true);
    for(ll i=2;i<320;i++){
        if(isp[i]) p.push_back(i);
        for(ll j=0;j<p.size()&&p[j]*i<320;j++){
            isp[p[j]*i]=false;
            if(i%p[j]==0) break;
        }
    }
    cin>>x>>y;
    ll n=y/x,cnt=0;
    double n1=(double)y/x;
    if(n==0||n!=n1){
        cout<<0<<endl;
        return 0;
    }
    else if(n==1){
        cout<<1<<endl;
        return 0;
    }
    for(ll i=0;i<p.size()&&n>=p[i];i++){
        if(n%p[i]==0){
            cnt++;
        }
    }
    int ans=0;
    for(int i=1;i<cnt;i++){
        ans+=con(i,cnt);
    }
    cout<<ans+2<<endl;
    return 0;
}