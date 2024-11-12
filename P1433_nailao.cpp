#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int n,m=1,att=1,x_p,y_p;
    double t=0,ans=1e9;    
    vector<vector<int>> path(1000000,vector<int>());
    vector<double> was(1000000,0.0);
    double x,y,pos[20][2],dis[20][20];
    cin>>n;
    pos[0][0]=0;
    pos[0][1]=0;
    path[0].push_back(0);
    for(int i=1;i<=n;i++){
        cin>>x>>y;
        pos[i][0]=x;
        pos[i][1]=y;
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            dis[i][j]=sqrt((pos[i][0]-pos[j][0])*(pos[i][0]-pos[j][0])+(pos[i][1]-pos[j][1])*(pos[i][1]-pos[j][1]));
        }
    }
    while(att!=n+1){
        double mi=1e9;
        for(int i=0;i<m;i++){
            for(int j=0;j<=n;j++){
                auto it=find(path[i].begin(),path[i].end(),j);
                if(it==path[i].end()&&dis[path[i].back()][j]-was[i]>0){
                    if(dis[path[i].back()][j]-was[i]<mi){
                        mi=dis[path[i].back()][j]-was[i];
                        x_p=i;
                        y_p=j;               
                    }
                }
            }
        }
        cout<<x_p<<" "<<y_p<<" "<<mi<<endl;
        t+=mi;      
        m++;
        for(int i=0;i<m;i++){
            if(i!=x_p){
                was[i]+=mi;
            }
            else was[i]=0.0;
        }
        copy(path[x_p].begin(),path[x_p].end(),back_inserter(path[m-1]));
        path[x_p].push_back(y_p);
        att=max(att,static_cast<int>(path[x_p].size()));
    }
    printf("%.2lf\n",t);
    return 0;
}