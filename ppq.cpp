#include <bits/stdc++.h>
using namespace std;
void solve(int* sc,int max,int len) {
    int w=0,l=0;
    for(int i=0;i<len;i++){
        if(sc[i]==1){
            w++;
        }else if(sc[i]==-1){
            l++;
        } 
        if ((w >= max || l >= max) && abs(w - l) >= 2){
            cout<<w<<':'<<l<<endl;
            w=0;
            l=0;
        }
        if(sc[i]==0){
            break; 
        }
    }
    cout<<w<<':'<<l<<endl;
}


int main() {
    string a,ma;
    while(getline(cin,a)){
        ma+=a;
    }
    int sc[62525]={0},l=0;
    for(int i=0;i<ma.size();i++){
        if(ma[i]=='W'){
            sc[i]=1;
            l++;
        }else if(ma[i]=='L'){
            sc[i]=-1;
            l++;
        }else if(ma[i]=='E'){
            break;
        }    
    }
    solve(sc,11,l);
    cout<<endl;
    solve(sc,21,l);
    return 0;
}