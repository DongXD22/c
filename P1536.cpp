#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct node{
    int id,root;
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
    int n,m,u,v;
    node p[1005];
    set<int> cit;
    bool flag=true;
    while(flag){
        cin>>n;
        if(n==0) return 0;
        cin>>m;
        for(int i=1;i<=n;i++){
            p[i].id=i;
            p[i].root=i;
        }
        for(int i=0;i<m;i++){
            cin>>u>>v;
            uni(p[u],p[v],p);
        }
        for(int i=1;i<=n;i++){
            cit.insert(findd(p[i],p));
        }
        cout<<cit.size()-1<<endl;
        cit.clear();
    }
}