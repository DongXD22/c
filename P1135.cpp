#include <bits/stdc++.h>
using namespace std;
#define ll long long
int step=0,n;  
bool flag=true;  
vector<int> path,path_temp;
void solve(int now,int k[],bool mark[]){
    if(now-k[now]>=1){
        if(mark[now-k[now]]){
        path_temp.push_back(now-k[now]);
        mark[now-k[now]]=false;
        flag=true;
        }
    }
    if(now+k[now]<=n){
        if(mark[now+k[now]]){
        path_temp.push_back(now+k[now]);
        mark[now+k[now]]=false;
        flag=true;
        }
    }
}
int main(){
    int a,b,k[205]={-1};
    bool mark[205];
    memset(mark,true,sizeof(mark));
    cin>>n>>a>>b;
    for(int i=1;i<=n;i++){
        cin>>k[i];
    }
    path.push_back(a);
    if(a==b){
        cout<<0<<endl;
        return 0;
    }
    while(flag){
        step++;
        flag=false;
        for(int i=0;i<path.size();i++){
            solve(path[i],k,mark);
        }
        auto it=find(path_temp.begin(),path_temp.end(),b);
        if(it!=path_temp.end()){
            cout<<step<<endl;
            return 0;
        }
        path=path_temp;
        path_temp.clear();
    }
    cout<<"-1"<<endl;
    return 0;
}