#include <bits/stdc++.h>
using namespace std;
#define ll long long
int mov1[4]={1,-1};
int mov2[4]={2,-2};
int n,m,step=0;
bool flag=true;
vector<int> path_x,path_y,path_xtemp,path_ytemp;
void solve(int x,int y,bool mark[405][405],int tab[405][405]){
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                if(x+mov1[i]>=1&&x+mov1[i]<=n&&y+mov2[j]>=1&&y+mov2[j]<=m&&mark[x+mov1[i]][y+mov2[j]]){
                    tab[x+mov1[i]][y+mov2[j]]=step;
                    mark[x+mov1[i]][y+mov2[j]]=false;
                    path_xtemp.push_back(x+mov1[i]);
                    path_ytemp.push_back(y+mov2[j]);
                    flag=true;
                }
                if(x+mov2[j]>=1&&x+mov2[j]<=n&&y+mov1[i]>=1&&y+mov1[i]<=m&&mark[x+mov2[j]][y+mov1[i]]){
                    tab[x+mov2[j]][y+mov1[i]]=step;
                    mark[x+mov2[j]][y+mov1[i]]=false;
                    path_xtemp.push_back(x+mov2[j]);
                    path_ytemp.push_back(y+mov1[i]);
                    flag=true;
                }
            }
        }
}
int main(){
    int x,y,tab[405][405];
    bool mark[405][405];
    memset(tab,-1,sizeof(tab));
    memset(mark,true,sizeof(mark));
    cin>>n>>m>>x>>y;
    tab[x][y]=0;
    mark[x][y]=false;
    path_x.push_back(x);
    path_y.push_back(y);
    while(flag){
        step++;
        flag=false;
        for(int i=0;i<path_x.size();i++){
            x=path_x[i];
            y=path_y[i];
            solve(x,y,mark,tab);
        }
        path_x=path_xtemp;
        path_y=path_ytemp;
        path_xtemp.clear();
        path_ytemp.clear();
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<tab[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}