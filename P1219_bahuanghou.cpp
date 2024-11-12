#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> ans;
int num_ans=0,loc[15];
int att[15]={0};
int n;
void solve(int th,int now,int loc[]) {
    int att[15]={0};
    fill(att,att+15,0);

    if(th==0){
        return;
    }
    if(th>n){
    if(num_ans<3)ans.push_back(vector<int>(loc, loc + 15));
        num_ans++;
        return;
    }

    for(int i=1;i<th;i++){
        att[loc[i]]=1;
        if(th-i+loc[i]>=1&&th-i+loc[i]<=n) att[th-i+loc[i]]=1;
        if(-1*(th-i)+loc[i]>=1&&-1*(th-i)+loc[i]<=n) att[i-th+loc[i]]=1;
    }

    for(int i=1;i<=n;i++){    
        if(att[i]==1) continue;
        else{
            loc[th]=i;
            solve(th+1,1,loc);
        }
    }
}
int main() {
    cin >> n;
    solve(1,1,loc);
    for(int i=0;i<min(num_ans,3);i++){
        for(int j=1;j<=n;j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    cout << num_ans << endl;

    
}