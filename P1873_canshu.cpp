#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define ll unsigned long long
ll cut(ll wood[],ll n,ll h){
    ll ans=0;
    for(int i=0;i<n;i++){
        if(wood[i]>h){
            ans+=wood[i]-h;
        }
    }
    return ans;
}
int main(){
    ll n,m,wood[1000005],min,max;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>wood[i];
    }
    sort(wood,wood+n);
    min=wood[0];
    max=wood[n-1];
    ll h=(min+max)/2+1;
    while(max-min>3){
        if(cut(wood,n,h)>m){
            min=h;
            h=(min+max)/2+1;
        }
        else{
            max=h;
            h=(min+max)/2+1;
        }
    }
    h=max;
    while(cut(wood,n,h)<m) h--;
    cout<<h<<endl;
    return 0;
}