#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define max 1000000000
ll int ans=max;
int p[11]={0,2,3,5,7,11,13,17,19,23,29},r[11],n=1,r0=1;
void dfs(int now,ll int temp,int r_sum){
    if(now==11){
        if(r_sum>r0||(r_sum==r0&&temp<ans)){
            ans=temp;
            r0=r_sum;
        }
        return;
    }
    for(int i=0;i<=r[now-1];i++){
        if(temp>n) return;
        r[now]=i;
        dfs(now+1,temp,r_sum*(i+1));
        temp*=p[now];
    }
}
int main(){
    cin>>n;
    r[0]=max;
    dfs(1,1,1);
    cout<<ans<<endl;
    return 0;
}