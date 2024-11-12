#include <bits/stdc++.h>
using namespace std;
void solve(vector<vector<int>>& vec,int size,int x,int y,int r,int z) {
    vector<vector<int>> temp=vec;
    x--;
    y--;
    int dir=(z==0)?1:-1;
    for(int i=x-r;i<=x+r;i++){
        for(int j=y-r;j<=y+r;j++){
            vec[x+dir*(j-y)][y-dir*(i-x)]=temp[i][j];
        }
    }
}       
int main() {
    int n, m,o=0;
    cin >> n >> m;
    vector<vector<int>> num(n,vector<int>(n,0));
    vector<vector<int>> mag(m,vector<int>(4,0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            o++;
            num[i][j] = o;
        }
    }
    for(int i=0;i<m;i++){
        cin>>mag[i][0]>>mag[i][1]>>mag[i][2]>>mag[i][3];
    }
    for(int i=0;i<m;i++){
        solve(num,n,mag[i][0],mag[i][1],mag[i][2],mag[i][3]);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<num[i][j]<<" ";
        }
        cout<<endl;
    }
}