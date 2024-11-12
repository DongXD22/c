#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    bool hors[25][25];
    memset(hors,true,sizeof(hors));
    ll int tab[25][25]={0},xh,yh,xb,yb,mov1[]={-1,1},mov2[]={-2,2};
    cin>>xb>>yb>>xh>>yh;
    hors[xh][yh]=false;
    tab[0][0]=1;
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            if(xh+mov1[i]>=0&&yh+mov2[j]>=0) hors[xh+mov1[i]][yh+mov2[j]]=false;
            if(xh+mov2[i]>=0&&yh+mov1[j]>=0) hors[xh+mov2[i]][yh+mov1[j]]=false;
        }
    }
    for(int i=1;i<=yb;i++){
        if(hors[0][i]) tab[0][i]=tab[0][i-1];
    }
    for(int i=1;i<=xb;i++){
        if(hors[i][0]) tab[i][0]=tab[i-1][0];
    }
    for(int i=1;i<=xb;i++){
        for(int j=1;j<=yb;j++){
            if(hors[i][j]) tab[i][j]=tab[i-1][j]+tab[i][j-1];
        }
    }
    cout<<tab[xb][yb];
    return 0;
}