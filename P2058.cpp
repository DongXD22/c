#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int n,t,k,boat[1000005],p[1000005],head=0,x;
    set<int> nat;
    cin>>n;
    vector<vector<int>> vis(n,vector<int>());
    for(int i=0;i<n;i++){
        cin>>t>>k;
        boat[i]=t;
        for(int j=0;j<k;j++){
            cin>>x;
            vis[i].push_back(x);
            p[x]++;
            nat.insert(x);
        }
        while(boat[head]<=t-86400){
            for(int j=0;j<vis[head].size();j++){
                p[vis[head][j]]--;
                if(p[vis[head][j]]==0){
                    nat.erase(vis[head][j]);
                }
            }
            head++;
        }
        cout<<nat.size()<<endl;
    }
}