#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,k,r,c,ans=0,nr=0,nc=0;
    cin>>n>>k; 
    vector<ll> r_num,c_num,rf,cf;
    bool fr,fc;
    for(int i=0;i<k;i++){
        cin>>r>>c;      
        r_num.push_back(r);
        c_num.push_back(c);
    }
    sort(r_num.begin(),r_num.end());
    sort(c_num.begin(),c_num.end());
    rf.push_back(r_num[0]);
    cf.push_back(c_num[0]);
    for(int i=1;i<r_num.size();i++){
        if(r_num[i]!=r_num[i-1]){
            rf.push_back(r_num[i]);
        }
    }
    for(int i=1;i<c_num.size();i++){
        if(c_num[i]!=c_num[i-1]){
            cf.push_back(c_num[i]);
        }
    }
    ans=n*(cf.size()+rf.size())-rf.size()*cf.size();
    cout<<ans<<endl;
    return 0;
}