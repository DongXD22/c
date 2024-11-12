#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ll int n,c,num[200005],a,b1,b2,ans=0;
    cin>>n>>c;
    for(int i=0;i<n;i++) cin>>num[i];
    sort(num,num+n);
    for(int i=0;i<n;i++){
        a=num[i]+c;
        b1=lower_bound(num+i,num+n,a)-num;
        if(num[b1]==a){
            ans+=upper_bound(num+i,num+n,a)-num-b1;
        }
    }
    cout<<ans<<endl;
    return 0;
}