#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct node{
    priority_queue<int, vector<int>, greater<int>> next;
    bool vis=true;
    int num;
};
void dfs(node u,node p[]){
    int l=u.next.size();
    p[u.num].vis=false;
    cout<<u.num<<" ";
    for(int i=0;i<l;i++){
        if(p[u.next.top()].vis){
            dfs(p[u.next.top()],p);
        }
        u.next.pop();
    }
}
void bfs(node p[]){
    queue<int> q;
    node temp;
    q.push(1);
    cout<<1<<" ";
    p[1].vis=false;
    while(!q.empty()){
        temp=p[q.front()];
        q.pop();
            while(!temp.next.empty()){
                if(p[temp.next.top()].vis){
                    q.push(temp.next.top());
                    cout<<temp.next.top()<<" ";
                    p[temp.next.top()].vis=false;
                    
                }
                temp.next.pop();
            } 
    }
}
int main(){
    int n,m,x,y;
    node p[100005];
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        p[x].next.push(y);
    }
    for(int i=1;i<=n;i++){
        p[i].num=i;
    }
    dfs(p[1],p);
    cout<<endl;
    for(int i=1;i<=n;i++){
        p[i].vis=true;
    }
    bfs(p);
    return 0;
}