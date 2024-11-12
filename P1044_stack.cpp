#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ll int inp,ans[23][23]={0};
    cin>>inp;
    for(int i=1;i<=22;i++){
        ans[i][1]=i;
    }
    for(int i=2;i<=inp;i++){
        for(int j=2;j<=i;j++){
            ans[i][j]=ans[i-1][j]+ans[i][j-1];
        }
    }
    cout<<ans[inp][inp]<<endl;
    return 0;
}