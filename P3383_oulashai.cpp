#include <bits/stdc++.h>
using namespace std;   
bool num[100000003];
int main(){
    std::ios::sync_with_stdio(0);
    vector<int> p;
    fill(num, num + 100000003, true); 
    int n,m,x;
    cin>>n>>m;
    for(int i=2;i<=n;i++){
        if(num[i]){
            p.push_back(i);
        }
        for(int j=0;j<p.size();j++){
            if(i*p[j]>100000000) break;
            num[i*p[j]]=false;
            if (i%p[j]==0) break;
        }
    }
    for(int i=0;i<m;i++){
        cin>>x;
        cout<<p[x-1]<<endl;
    }
    return 0;
}