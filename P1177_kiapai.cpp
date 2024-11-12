#include <bits/stdc++.h>
using namespace std;
void paixv(int n,int suo,vector<long long>& a,vector<long long>& res,int k){
        if(suo<=k&&suo+n-1>=k) {
            vector<long long> B,C,D;
            int b=0,c=0,d=0;
            long long x=a[n/2];
            for(int i=0;i<n;i++){
                if(a[i]>x){
                    D.push_back(a[i]);
                    d++;
                }
                else if(a[i]<x){
                    B.push_back(a[i]);
                    b++;
                }
                else{
                    C.push_back(a[i]);
                    c++;
                }
            }    
            if(b==1) {
                if(suo==k){
                    cout<<B[0]<<endl;
                    return;
                }
                res[suo]=B[0];
            }
            if(d==1){
                if(suo+n-1==k){
                    cout<<D[0]<<endl;
                    return;
                }
                res[suo+b+c]=D[0];
            }
            int j=0;
            if(suo+b<=k&&suo+b+c>=k){
                cout<<x<<endl;
                return;
            }
            for(int i=b+suo;i<c+b+suo;i++){
                res[i]=C[j];
                j++;
            }
            if(b>1) paixv(b,suo,B,res,k);
            if(d>1) paixv(d,b+c+suo,D,res,k);
        }
    }
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,k;
    long long temp;
    vector<long long> a;
    cin >>n>>k;
    for(int i=0;i<n;i++){
        cin>>temp;
        a.push_back(temp);
    }
    paixv(n,0,a,a,k);
    return 0;
}