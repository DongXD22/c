#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n;
double t=0,ans=1e9,dis[20][20];
struct point{
    int id;
    double x,y;
    bool vis;
}p[20];    
double f[20][66000];
void solve(point pt,int att,int mark,double s,point p[20]){
    if(att==n){
        ans=min(ans,s);
        return;
    }
    for(int i=1;i<=n;i++){
        if(p[i].vis) continue;
        int temp=mark+(1<<i);
        if(f[i][temp]==0||f[i][temp]>s+dis[pt.id][i]){
            f[i][temp]=s+dis[pt.id][i];
            p[i].vis=true;
            solve(p[i],att+1,temp,f[i][temp],p);
            p[i].vis=false;
        }
    }
}
main(){
    double x,y;
    memset(f,0,sizeof(f));
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x>>y;
        p[i].id=i;
        p[i].x=x;
        p[i].y=y;
        p[i].vis=0;
    }
    p[0]={0,0,0,1};
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(i==j) dis[i][j]=1e9;
            dis[i][j]=sqrt((p[i].x-p[j].x)*(p[i].x-p[j].x)+(p[i].y-p[j].y)*(p[i].y-p[j].y));
        }
    }
    solve(p[0],0,1,0,p);
    printf("%.2lf\n",ans);
    return 0;
}