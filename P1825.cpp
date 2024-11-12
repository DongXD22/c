#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int n,m,map[305][305],mac[25][2][2],fin,st,t=0;
    int mx[4]={0,1,0,-1},my[4]={1,0,-1,0};
    char a;
    vector<int> path,temp;
    bool flag[25][2],fla=true;
    fill(&flag[0][0], &flag[0][0] + 25 * 2, false);
    cin>>n>>m;
    for(int i=0;i<=n+1;i++){
        for(int j=0;j<=m+1;j++){
            if(j==0||j==m+1||i==0||i==n+1){
                map[i][j]=-1;
                continue;
            }
            cin>>a;
            if(a=='#') map[i][j]=-1;
            else if(a=='.') map[i][j]=1e9;
            else if(a=='='){
                map[i][j]=1e9;
                fin=i+j*1000;
            }
            else if(a=='@'){
                map[i][j]=0;
                st=i+j*1000;
            }
            else{               
                int e=a-'A';
                map[i][j]=1000000000-e;
                if (!flag[e][0]) {
                    mac[e][0][0]=i;
                    mac[e][0][1]=j;
                    flag[e][0]=true;
                }
                else{
                    mac[e][1][0]=i;
                    mac[e][1][1]=j;
                    flag[e][1]=true;
                }            
            }
        }
    }
    path.push_back(st);
    while(fla){
        t++;
        for(int i=0;i<path.size();i++){
            if(path[i]==fin){
                fla=false;
                break;
            }
            int li=path[i]%1000;
            int lj=(path[i]-li)/1000;
            for(int j=0;j<4;j++){
                    if(li+mx[j]<0||lj+my[j]<0) continue;
                    if(map[li+mx[j]][lj+my[j]]>=1000000000-30&&map[li+mx[j]][lj+my[j]]!=1000000000){
                        int macid=1000000000-map[li+mx[j]][lj+my[j]];
                        if(flag[macid][0]&&li+mx[j]==mac[macid][0][0]&&lj+my[j]==mac[macid][0][1]){
                            flag[macid][0]=false;
                            flag[macid][1]=false;
                            temp.push_back(mac[macid][1][0]+mac[macid][1][1]*1000);
                        }
                        else if(flag[macid][1]&&li+mx[j]==mac[macid][1][0]&&lj+my[j]==mac[macid][1][1]){
                            flag[macid][0]=false;
                            flag[macid][1]=false;
                            temp.push_back(mac[macid][0][0]+mac[macid][0][1]*1000);
                        }
                    }
                    else if(map[li+mx[j]][lj+my[j]]>t){
                        map[li+mx[j]][lj+my[j]]=t;
                        temp.push_back(li+mx[j]+(lj+my[j])*1000);

                    }
            }
        }
        path=temp;
        temp.clear();
    }
    cout<<t-1<<endl;
    return 0;
}