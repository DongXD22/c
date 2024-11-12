#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int n,x,y,m,neg_n=0,t;
    bool flag[100005];
    memset(flag,false,sizeof(flag));
    int head[100005],next[100005];
    memset(head,0,sizeof(head));
    memset(next,0,sizeof(next));
    head[0]=1;
    next[0]=1;
    head[1]=1;
    next[1]=1;
    cin>>n;
    for(int i=2;i<=n;i++){
        cin>>x>>y;
        if(y){
            next[i]=next[x];
            head[i]=x;
            next[x]=i;
            head[next[i]]=i;
            if(x==next[0]){
                next[0]=i;
            }
        }
        else{
            head[i]=head[x];
            next[i]=x;
            head[x]=i;
            next[head[i]]=i;
            if(x==head[0]){
                head[0]=i;
            }
        }
    }
    cin>>m;
    for(int i=1;i<=m;i++){
        cin>>x;
        if(flag[x]) continue;
        if(x==head[0]){
            head[0]=next[x];
        }
        if(x==next[0]){
            next[0]=head[x];
        }
        neg_n++;
        flag[x]=true;
        next[head[x]]=next[x];
        head[next[x]]=head[x];
        head[x]=0;
        next[x]=0;
    }
    t=head[0];
    for(int i=0;i<n-neg_n;i++){
        cout<<t<<" ";
        t=next[t];
    }
    return 0;
}
    