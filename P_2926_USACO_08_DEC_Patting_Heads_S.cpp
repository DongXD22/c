#include <bits/stdc++.h>
using namespace std;
#define ll long long
int num[1000006]={0},pat[1000006]={0};
int main(){
    int n,x;
    set<int> cow;
    vector<int> id;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x;
        id.push_back(x);
        cow.insert(x);
        num[x]++;
    }
    for(auto it=cow.begin();it!=cow.end();it++){
        for(int i=1;i*(*it)<=1000004;i++){
            if(num[i*(*it)]>0){
                pat[i*(*it)]+=num[(*it)];
            }
        }
    }
    for(int i=0;i<id.size();i++){
        cout<<pat[id[i]]-1<<endl;
    }
    return 0;
}