#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct node{
    int max_id;
    vector<int> next;
    bool vis=false;
}p[100005];
int ans=0;
void dfs(int u,node p[],int id){
    if(p[u].max_id<id)p[u].max_id=id;
    p[u].vis=true;
    for(int i=0;i<p[u].next.size();i++){
        if(!p[p[u].next[i]].vis&&p[p[u].next[i]].max_id<id){
            dfs(p[u].next[i],p,id);
            p[p[u].next[i]].vis=false;
        }
    }
}
int main(){
    int n,m,u,v;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>u>>v;
        p[v].next.push_back(u);
    }
    for(int i=n;i>=1;i--){
        ans=0;
        dfs(i,p,i);
        p[i].vis=false;
    }
    for(int i=1;i<=n;i++){
        cout<<p[i].max_id<<" ";
    }
    return 0;
}