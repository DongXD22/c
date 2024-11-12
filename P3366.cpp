#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct node{
    int id,root;
    vector<int> adj;
};
struct edge{
    int u,v,dis;
};
int findd(node &i,node p[]){
    if(i.id==i.root) return i.id;
    else{
        i.root=findd(p[i.root],p);
        return i.root;
    }
}
void uni(node &u,node &v,node p[]){
    int up=findd(u,p);
    int vp=findd(v,p);
    p[up].root=p[vp].root;
}
int main(){
    int n,m,u,v,s,ans=0,flag=0;
    node p[5005];
    vector<edge> e;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>u>>v>>s;
        edge temp={u,v,s};
        e.push_back(temp);
    }
    for(int i=1;i<=n;i++){
        p[i].id=i;
        p[i].root=i;
    }
    sort(e.begin(),e.end(),[](edge a,edge b){
        return a.dis<b.dis;
    });
    for(int i=0;i<m&&flag<=n-1;i++){
        if(findd(p[e[i].u],p)!=findd(p[e[i].v],p)){
            uni(p[e[i].u],p[e[i].v],p);
            ans+=e[i].dis;
            flag++;
        }
    }
    if(flag!=n-1){
        cout<<"orz"<<endl;
        return 0;
    }
    cout<<ans<<endl;
    return 0;
}