#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct edge{
    int tail,weight;
};
struct node{
    int id,dist=-1e9,path;
    vector<edge> adj;
    bool vis=false;
}p[100005];
void bfs(int s,node p[]){
    priority_queue<pair<int, int>> q;
    q.push({p[s].dist, s}); 
    p[s].dist=0;
    p[s].path=0;
    while(!q.empty()){
        auto [dist,id]=q.top();
        q.pop();
        if(p[id].vis) continue;
        p[id].vis=true;
        for(const auto&e:p[id].adj){
            int next =  e.tail;
            if(p[next].dist<dist+e.weight){         
                p[next].dist=dist+e.weight;
                p[next].path=id;
                q.push({p[next].dist, next});
            }
        }
    }
}
int main(){
    int n,m,u,v,w,s;
    cin>>n>>m;
    for(int i=1;i<=n;i++) p[i].id=i;
    for(int i=1;i<=m;i++){
        cin>>u>>v>>w;
        p[u].adj.push_back({v,w});
    }
    bfs(1,p);
    for(int i=1;i<=n;i++){
        cout<<p[i].dist<<" ";
    }
    return 0;
}