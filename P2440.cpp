#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
vector<int> ans,dis;
int l,n,m,pre=0,x;
void solve(int maxx,int minn,vector<int>& dis){
    int goal=(maxx+minn)/2;
    ans.clear();
    ans.push_back(0);
    for(int i=0;i<=n;i++){
        if(dis[i]<goal){
            ans[ans.size()-1]+=dis[i];
        }
        else if(dis[i]>=goal&&ans[ans.size()-1]>=goal){
            ans.push_back(dis[i]);
        }
        else if(dis[i]>=goal&&ans[ans.size()-1]<goal){
            ans[ans.size()-1]+=dis[i];
        }
    }
    if(ans.size()==n-m+1){
        auto it=min_element(ans.begin(),ans.end());
        cout<<*it<<endl;
        return;
    }
    else if(ans.size()>n-m+1){
        solve(maxx,goal+1,dis);
    }
    else{
        solve(goal-1,minn,dis);
    }
}
int main(){
    cin>>l>>n>>m;
    for(int i=0;i<n;i++){
        cin>>x;
        dis.push_back(x-pre);
        pre=x;
    }
    dis.push_back(l-pre);
    solve(l/(n-m+1),1,dis);
}