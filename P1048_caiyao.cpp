#include <bits/stdc++.h>
using namespace std;
int main() {
    int T,M,was[1005],val[105],res[105][1005]={0};
    cin >> T >> M;
    for(int i=1;i<=M;i++) {
        cin >> was[i] >> val[i];
    }
    for(int i=1;i<=M;i++){
        for(int j=1;j<=T;j++){
            if(j>=was[i]) res[i][j]=max(res[i-1][j],res[i-1][j-was[i]]+val[i]*was[i]);
            else res[i][j]=res[i-1][j];
        }
    }
    cout<<res[M][T]<<endl;
    return 0;
}