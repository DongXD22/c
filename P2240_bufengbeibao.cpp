#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int n;
    double t,ans=0;
    cin>>n>>t;   
    vector<pair<double,double>> gold(n);
    for(int i=0;i<n;i++){
        cin>>gold[i].first>>gold[i].second;
    }
    sort(gold.begin(),gold.end(),[](const pair<double,double>&a,const pair<double,double>&b){
        return a.second/a.first>b.second/b.first;
    });
    for(int i=0;i<n;i++){
        if(t>=gold[i].first){
            t-=gold[i].first;
            ans+=gold[i].second;
        }
        else{
            ans+=gold[i].second*t/gold[i].first;
            break;
        }
    }
    printf("%.2f",ans);
    return 0;
}