#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct node{
    int id,was;
    vector<int> head,tail;
    bool vis=true;
}task[10005];
struct CompareNode {
    bool operator()(const node& n1, const node& n2) {
        return n1.was > n2.was;
    }
};

int ans=0;
void bfs(node p[]){
    priority_queue<node,vector<node>,CompareNode> q,temp_q;
    int tp=0;
    q.push(p[1]);   
    while(!q.empty()){
        int u=q.top().id;
        tp=task[u].was;
        ans+=tp;
        task[u].vis=false;
        while(!q.empty()){
            int t=q.top().id;
            q.pop();
            task[t].was-=tp;
            temp_q.push(task[t]);
        }
        swap(q,temp_q);
        for(int i=0;i<task[u].tail.size();i++){
            if(task[task[u].tail[i]].vis){
                bool flag=true;
                for(int j=0;j<task[task[u].tail[i]].head.size();j++){
                    if(task[task[task[u].tail[i]].head[j]].vis){
                        flag=false;
                        break;
                    }
                }
                if(flag){
                    q.push(task[task[u].tail[i]]);
                }
            }
        }  
        q.pop();
    }
   
}
int main(){
    int n,temp;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>task[i].id>>task[i].was;
        cin>>temp;
        while(temp!=0){
            task[i].head.push_back(temp);
            task[temp].tail.push_back(i);
            cin>>temp;
        }
    }
    bfs(task);
    cout<<ans<<endl;
    return 0;
}