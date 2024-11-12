#include <bits/stdc++.h>
using namespace std;
#define ll long long     

struct node{
    int id,root;
}p[10004];
int findd(node &i){
    if(i.root==i.id) return i.id;
    else{
        return i.root=findd(p[i.root]);
    }
}
void uni(node &u,node &v){
    int up=findd(u);
    int vp=findd(v);
    if(up==vp) return;
    p[up].root=vp;
}
int main(){
    std::ios::sync_with_stdio(false);
    int n,m;
    int z,x,y;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        p[i].id=i;
        p[i].root=i;
    }
    for(int i=0;i<m;i++){
        cin>>z>>x>>y;
        if(z==1){
            uni(p[x],p[y]);
        } 
        else{
            if(findd(p[x])==findd(p[y])) cout<<"Y"<<endl;
            else cout<<"N"<<endl;
        }
    }
}