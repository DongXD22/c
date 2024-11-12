#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct node{
    int id,next[2]={0,0},pa,llev=0;
    bool vis;
};
int len=0,wid=0;
void dfs(int now,node p[],int lev){
    bool flag=true;
    for(int i=0;i<=1;i++){
        if(p[now].next[i]==0) continue;
        else{
            dfs(p[now].next[i],p,lev+1);
            flag=false;
        }
    }
    if(flag) len=max(lev,len);
}
void bfs(node p[]){ 
    vector<int> q,temp;
    int step=0;
    q.push_back(1);
    while(!q.empty()){    
        step++;        
        wid=max(wid,static_cast<int>(q.size()));
        for(int i=0;i<q.size();i++){
            p[q[i]].llev=step;
            if(p[q[i]].next[0]!=0) temp.push_back(p[q[i]].next[0]);
            if(p[q[i]].next[1]!=0) temp.push_back(p[q[i]].next[1]);
        }
        q=temp;
        temp.clear(); 
    }
}
int dis(node p[],int x,int y){
    int lx=0,ly=0;
    while(p[x].id!=p[y].id){
        if(p[x].llev>p[y].llev){
            x=p[x].pa;
            lx++;
        }
        else{
            y=p[y].pa;
            ly++;
        }
    }
    return 2*lx+ly;
}
int main(){
    int n,u,v,x,y;
    node p[105];
    cin>>n;
    for(int i=1;i<=n;i++){
        p[i].id=i;
    }
    for(int i=1;i<n;i++){
        cin>>u>>v;
        if(p[u].next[0]==0){
            p[u].next[0]=v;
            p[v].pa=u;
        }
        else{
            p[u].next[1]=v;
            p[v].pa=u;
        }
    }
    dfs(1,p,1);
    bfs(p);
    cin>>x>>y;
    cout<<len<<endl<<wid<<endl;   
    cout<<dis(p,x,y)<<endl;
    return 0;
}