#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct node{
    int id,root;
};
int findd(node &i,node pt[]){
    if(i.root==i.id) return i.id;
    else{
        i.root=findd(pt[i.root],pt);
        return i.root;
    }
}
void uni(node &u,node &v,node pt[]){
    int up=findd(u,pt);
    int vp=findd(v,pt);
    pt[up].root=pt[vp].root;
}
int main(){
    int m,n,p,u,v;
    node pt[5005];
    cin>>n>>m>>p;
    for(int i=1;i<=n;i++){
        pt[i].id=i;
        pt[i].root=i;
    }
    for(int i=0;i<m;i++){
        cin>>u>>v;
        uni(pt[u],pt[v],pt);
    }
    for(int i=0;i<p;i++){
        cin>>u>>v;
        if(findd(pt[u],pt)==findd(pt[v],pt)){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}