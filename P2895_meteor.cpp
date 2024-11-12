#include <bits/stdc++.h>
using namespace std;
#define ll long long
int mov_x[4]= {-1,1,0,0};
int mov_y[4]= {0,0,-1,1};
vector<pair<int,int>> path,path_temp;
bool flag=true,flag1=false;
void met(int x,int y,int t,int farm[310][310]){
    farm[x][y]=min(farm[x][y],t);
    for(int i=0;i<4;i++){
        if(x+mov_x[i]>=0 && x+mov_x[i]<310 && y+mov_y[i]>=0 && y+mov_y[i]<310){
            farm[x+mov_x[i]][y+mov_y[i]]=min(farm[x+mov_x[i]][y+mov_y[i]],t);
        }
    }
}
void mov(int x,int y,int t,int farm[310][310]){
    for(int i=0;i<4;i++){
        if(x+mov_x[i]>=0 && x+mov_x[i]<310 && y+mov_y[i]>=0 && y+mov_y[i]<310){
            if(farm[x+mov_x[i]][y+mov_y[i]]==1010){
                flag1=true;
                return;
            }
            if(farm[x+mov_x[i]][y+mov_y[i]]>t+1){
                farm[x+mov_x[i]][y+mov_y[i]]=0;
                path_temp.push_back({x+mov_x[i],y+mov_y[i]});
                flag=true;
            }
        }
    }
}
int main(){
    int m,farm[310][310],x,y,t=-1;
    fill(&farm[0][0],&farm[0][0]+310*310,1010);
    path.push_back({0,0});
    farm[0][0]=0;
    cin >> m;
    for(int i=0;i<m;i++){
        cin >> x >> y >> t;
        met(x,y,t,farm);
    }
    t=-1;
    while(flag){
        t++;
        flag=false;
        for(int i=0;i<path.size();i++){
            x=path[i].first;
            y=path[i].second;
            mov(x,y,t,farm);
            if(flag1){
                flag=false;
                t++;
                break;
            }
        }
        path.clear();
        copy(path_temp.begin(),path_temp.end(),path.insert(path.end(),path_temp.begin(),path_temp.end()));
        path_temp.clear();       
    }
    if(flag1) cout<<t<<endl;
    else cout<<-1<<endl;
    return 0;
}