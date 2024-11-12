#include <bits/stdc++.h>
using namespace std;
#define ll long long
int ans=0;
void solve(int now,int l[],int r[],int step){
    step++;
    if(l[now]!=0){
        solve(l[now],l,r,step);
    }
    else{
        ans=max(ans,step);
    }
    if(r[now]!=0){
        solve(r[now],l,r,step);
    }
    else{
        ans=max(ans,step);
    }
}
int main(){
    int step=0;
    int n,l[1000005],r[1000005];
    cin>>n;
    for(int i=1;i<=n;i++) cin>>l[i]>>r[i];
    solve(1,l,r,step);
    cout<<ans<<endl;
}