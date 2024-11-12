#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int n,step=0; 
    cin>>n;
    vector<vector<int>> a(n,vector<int>(2));
    for(int i=0;i<n;i++){
        cin>>a[i][0]>>a[i][1];
    }
    sort(a.begin(),a.end(),[](vector<int>& a,vector<int>& b){
        return a[1]<b[1];
    });
    int t=0;
    for(int i=0;i<n;i++){
        if(a[i][0]>=t){
            t=a[i][1];
            step++;
        }
    }
    cout<<step<<endl;
}