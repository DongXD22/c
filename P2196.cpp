#include <bits/stdc++.h>
using namespace std;
#define ll long long
int num[25]={0},conn[25][25]={0},fin=0,n;
vector<int> fin_way;
void dig(int now,int& ans,vector<int>& way){
    bool flag=true;
    for(int i=1;i<=n-now;i++){
        if(conn[now][i]==1){
            way.push_back(i+now);
            ans+=num[i+now];
            dig(i+now,ans,way);
            way.pop_back();
            ans-=num[i+now];
            flag=false;
        }   
    }
    if(flag&&ans>fin){
        fin=ans;
        fin_way=way;
    }
}
int main(){
    int ans=0;
    vector<int> way;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>num[i];
    }
    for(int i=1;i<=n-1;i++){
        for(int j=1;j<=n-i;j++){
            cin>>conn[i][j];
        } 
    }
    for(int i=1;i<=n;i++){
        way.clear();
        ans=0;
        way.push_back(i);
        ans+=num[i];
        dig(i,ans,way);
    }
    for(int i=0;i<fin_way.size();i++){
        cout<<fin_way[i]<<" ";
    }
    cout<<endl;    
    cout<<fin<<endl;
    return 0;
}