#include <bits/stdc++.h>
using namespace std;
#define ll long long
int mov_x[4]={0,1,0,-1};
int mov_y[4]={1,0,-1,0};
ll ans,k;
bool flag=false,mark[1005][1005];
ll path_temp;
vector<ll> path;
void mov(int x,int y,int d,int map[1005][1005]){
    int fla=0;
    path_temp=d+x*10+y*1e7;
    auto it=find(path.begin(),path.end(),path_temp);
    if(it!=path.end()||k<=0){
        return;
    }
    path.push_back(path_temp);
    if(mark[x][y]) ans++;
    else mark[x][y]=true;
    k--;
    while(map[x+mov_x[d]][y+mov_y[d]]==1&&fla<4){
        d=(d+1)%4;
        k--;
        fla++;
    }
    if(fla==4) return;
    mov(x+mov_x[d],y+mov_y[d],d,map);
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int m,n,x0,y0,d0,map[1005][1005];
        memset(mark,false,sizeof(mark));
        char temp;
        cin>>m>>n>>k>>x0>>y0>>d0;
        k++;       
        for(int j=0;j<=m+1;j++){           
            for(int l=0;l<=n+1;l++){
                if(j==0 || j==m+1 || l==0 || l==n+1){
                    map[j][l]=1;
                    continue;
                }
                cin>>temp;
                if(temp=='.') map[j][l]=0;
                else map[j][l]=1;
            }            
        }
        path.clear();
        ans=0;
        mov(x0,y0,d0,map);
        cout<<path.size()-ans<<endl;
    }
}