#include <bits/stdc++.h>
using namespace std;
int exchange(int a){
    if (a == 0) return 2;
    if (a == 1) return 0;
    if (a == 2) return 1;
    if (a == 3) return 4;
    if (a == 4) return 3;
}
void solve(int a,int b,int* asc,int* bsc){
    if(a!=b){
        if(a-b==1||a-b==3||a-b==-2||a-b==-4){
            (*asc)++;
        }else{
            (*bsc)++;
        }
    }
}
int main() {
    int n,na,nb,x=0,y=0,asc=0,bsc=0;
    cin>>n>>na>>nb;
    int a[200]={0},b[200]={0};
    for(int i=0;i<na;i++){
        cin>>a[i];
        a[i]=exchange(a[i]);
    }
    for(int i=0;i<nb;i++){
        cin>>b[i];
        b[i]=exchange(b[i]);
    }
    for(int i=0;i<n;i++){
        if(x==na){
            x=0;
        }
        if(y==nb){
            y=0;
        }
        solve(a[x],b[y],&asc,&bsc);
        x++;
        y++;
    }
    cout<<asc<<" "<<bsc<<endl;
    return 0;
}