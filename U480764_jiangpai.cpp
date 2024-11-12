#include <bits/stdc++.h>
using namespace std;
int n;
void inpu(int m[200000][3],int n[],int ty,int l){
    for(int i=0;i<l;i++){
        n[i]=m[i][ty];
    }
}
int findd(int m[],int th){
    for (int i = 0; i < n; i++) {
        if (m[i] == m[th]) return i;
    }
}

int main() {
    std::ios::sync_with_stdio(0);
    int p[200000][3]={0},g[200000]={0},s[200000]={0},c[200000]={0};
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            cin >> p[i][j];
        }
    }
    inpu(p,g,0,n);
    inpu(p,s,1,n);
    inpu(p,c,2,n);
    sort(g,g+n);
    sort(s,s+n);
    sort(c,c+n);
    
    for(int i=0;i<n;i++){
        cout<<min(findd(g,i),min(findd(s,i),findd(c,i)))+1<<endl;
    }
    return 0;
}