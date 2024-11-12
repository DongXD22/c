#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int n;
    double ans=0,qz[1005]={0};
    cin>>n;
    vector<vector<int>> p(n,vector<int>(2));
    for(int i=0;i<n;i++){
        cin>>p[i][0];
        p[i][1]=i+1;
    }
    sort(p.begin(),p.end(),[](vector<int>& a,vector<int>& b){
        return a[0]<b[0];
    });
    qz[0]=p[0][0];
    for(int i=1;i<n;i++){
        qz[i]=qz[i-1]+p[i][0];
    }
    for(int i=0;i<n;i++){
        cout<<p[i][1]<<" ";
    }
    for(int i=0;i<n-1;i++){
        ans+=qz[i];
    }
    cout<<endl;
    printf("%.2lf",ans/n);
    return 0;
}