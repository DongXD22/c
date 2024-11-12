#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    vector<int> p;
    bool isp[100005],isp2[1000006];
    memset(isp2, true, sizeof(isp2));
    memset(isp, true, sizeof(isp));
    for(int i=2; i<=100000; i++){
        if(isp[i]) p.push_back(i);
        for(int j=0; j<p.size() && i*p[j]<=100000; j++){
            isp[i*p[j]] = false;
            if(i%p[j]==0) break;
        }
    }
    int l,r,ans=0;
    cin>>l>>r;
    if (l==1) l=2;
    for(int j=0;j<p.size()&&r>=p[j];j++){
        int mi=l/p[j],ma=r/p[j];
        for(int k=mi;k<=ma;k++){
            if(k*p[j]-l>=0&&k>1)
            isp2[k*p[j]-l]=false;
        }
    }
    for(int i=0;i<=r-l;i++){
        if(isp2[i]) ans++;
    }
    cout<<ans<<endl;
    return 0;
}