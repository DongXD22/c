#include <bits/stdc++.h>
using namespace std;
int main() {
    int T,M,was[35],res[35][20005]={0};
    cin >> T >> M;
    for(int i=1;i<=M;i++) {
        cin >> was[i];
    }
    for(int i=0;i<=T;i++) res[0][i]=i;
    for(int i=1;i<=M;i++){
        for(int j=1;j<=T;j++){
            if(j>=was[i]&&res[i-1][j-was[i]]>=0) res[i][j]=min(res[i-1][j],res[i-1][j-was[i]]);
            else res[i][j]=res[i-1][j];
        }
    }
    cout<<res[M][T]<<endl;
    return 0;
}