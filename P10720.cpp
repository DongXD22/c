#include <bits/stdc++.h>
using namespace std;   
bool num[1000000];
int main(){
    std::ios::sync_with_stdio(0);
    vector<int> p;
    fill(num, num + 1000000, true); 
    int x;
    for(int i=2;i<=1000000;i++){
        if(num[i]){
            p.push_back(i);
        }
        for(int j=0;j<p.size();j++){
            if(i*p[j]>=1000000) break;
            num[i*p[j]]=false;
            if (i%p[j]==0) break;
        }
    }
    int n,m,step=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>m;
        for(int j=0;j<p.size();j++){
            if(p[j]>=m) break;
            if(m%p[j]==0){
                step++;
            }
            if(step>2){
                break;
            }
        }
        if(step!=2)cout<<0<<endl;
        else cout<<1<<endl;
        step=0;
    }
}