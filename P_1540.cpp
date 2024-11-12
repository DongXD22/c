#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int m,n,head=0,x,ans=0;
    cin>>m>>n;
    vector<int> q;
    for(int i=0;i<n;i++){
        cin>>x;
        auto it=find(q.begin()+head,q.end(),x);
        if(it==q.end()){
            q.push_back(x);
            ans++;
            if(q.size()-head>m){
                head++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}