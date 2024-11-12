#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[10000][10000],ans=0,now=0;
ll n,k;
void dfs(ll y,ll x,ll res,ll lin){
    ll s=0;
    if(y!=10&&dp[res+x*100+y*1000][lin]!=0){
        ans+=dp[res+x*100+y*1000][lin];
        now+=dp[res+x*100+y*1000][lin];
        return;
    }
    if(res==0){
        ans++;
        now++;
        return;
    }    
    if(y>n){
        return;
    }  
    ll t1=(7<<(n-x))&lin;    
    ll t2=1&lin;
    ll up=1&(lin>>(n-x+1));
    if(x<n){
        if(t1||t2){      
            now=0;
            ll lin_n=(~(1<<(n-x+1)))&lin;
            lin_n=((lin_n>>1)<<1)|up;
            dfs(y,x+1,res,lin_n);
            s+=now;
        }
        else{
            now=0;
            dfs(y,x+1,res,lin);
            s+=now;
            now=0;
            ll lin_n=lin+(1<<(n-x+1));
            dfs(y,x+1,res-1,lin_n);
            s+=now;
            now=s;
        }
    }
    else{
        if(t1||t2){
            now=0;
            ll lin_n=lin>>2<<2;
            dfs(y+1,1,res,lin_n);
            s+=now;
        }
        else{
            now=0;
            dfs(y+1,1,res,lin);
            s+=now;
            now=0;
            ll lin_n=lin+2;
            dfs(y+1,1,res-1,lin_n);
            s+=now;
            now=s;
        }
    }
    dp[res+x*100+y*1000][lin]=s;
}
int main(){
    cin>>n>>k;
    memset(dp,0,sizeof(dp));
    dfs(1,1,k,0);
    cout<<ans<<endl;
    return 0;
}