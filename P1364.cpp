#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct node{
    int id,wet,pa=0,next[2]={0,0},lev;
};
vector<vector<int>> bfs_node(node p[],int r,int frt){
    vector<int> q,temp;
    vector<vector<int>> dl;
    q.push_back(r);
    while(!q.empty()){
        for(int i=0;i<q.size();i++){
            node u=p[q[i]];
            if(u.next[0]!=0&&u.next[0]!=frt) temp.push_back(u.next[0]);
            if(u.next[1]!=0&&u.next[1]!=frt) temp.push_back(u.next[1]);
        }      
        dl.push_back(q);
        q=temp;
        temp.clear();
    }
    return dl;
}
int solve(node p[],int now){
    int sum=0,step=0;
    vector<vector<int>> dl=bfs_node(p,now,now);
    for(int i=0;i<dl.size();i++){
        sum+=(i)*accumulate(dl[i].begin(),dl[i].end(),0,
        [&](int acc,const int& x){return acc+p[x].wet;});
    }
    dl.clear();
    while(p[now].pa!=0){
        step++;
        int frt=now;
        now=p[now].pa;
        dl=bfs_node(p,now,frt);
        for(int i=0;i<dl.size();i++){
            sum+=(i+step)*accumulate(dl[i].begin(),dl[i].end(),0,
            [&](int acc,const int& x){return acc+p[x].wet;});
        }
        dl.clear();
    }
    return sum;
}
int main(){
    int n,w,u,v,ans=1e9;
    node p[105];
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>w>>u>>v;
        p[i].id=i;
        p[i].wet=w;
        p[i].next[0]=u;
        p[i].next[1]=v;
        p[u].pa=i;
        p[v].pa=i;
    }
    for(int i=1;i<=n;i++){
        ans=min(ans,solve(p,i));
    }
    cout<<ans<<endl;
    return 0;
}