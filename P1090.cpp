#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int n,temp;
    priority_queue<int,vector<int>,greater<int>> pq;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>temp;
        pq.push(temp);
    }
    int ans=0;
    for(int i=0;i<n-1;i++){
        int a=pq.top();
        pq.pop();
        int b=pq.top();
        pq.pop();
        ans+=a+b;
        pq.push(a+b);
    }
    cout<<ans;
}