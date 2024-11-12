#include <bits/stdc++.h>
using namespace std;
#define ll unsigned __int128
inline unsigned __int128 read() {
    __int128 x = 0, f = 1; char ch = getchar();
    while (ch > '9' || ch < '0') { if (ch == '-')f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
    return x * f;
}
inline void write(unsigned __int128 x) {
    if (x < 0) { putchar('-'); x = -x; }
    if (x > 9)write(x / 10);
    putchar(x % 10 + '0');
}
ll ans=0,now=0;
ll dp[55][55][55]={0};
void solve(ll lv,ll a,ll b){
    ll s=0;
    if(dp[lv][a][b]!=0){
        ans+=dp[lv][a][b];
        now+=dp[lv][a][b];
        return;
    }
    if(lv==0){
        ans++;
        now++;
        return;
    }
    for(ll i=0;i<=a;i++){
        for(ll j=0;j<=b;j++){
            now=0;
            solve(lv-1,a-i,b-j);
            s+=now;
        }
    }
    dp[lv][a][b]=s;
}
int main(){
    ll n,a,b;
    n=read();
    a=read();
    b=read();
    solve(n,a,b);
    write(ans);
    return 0;
}