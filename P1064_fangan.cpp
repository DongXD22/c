#include <bits/stdc++.h>
using namespace std;
vector<int> fla[65][3300];
int main() {
    int T,M,was[65],val[65],fu[65],temp;
    int res[65][3300]={0};
    vector<int> fla[65][3300];
    cin >> temp >> M;
    T=temp/10;
    for(int i=1;i<=M;i++) {
        cin >> temp >> val[i]>>fu[i];
        was[i]=temp/10;
    }
    for(int i=1;i<=M;i++){
        for(int j=1;j<=T;j++){
            if(j>=was[i]) {
                if(fu[i]==0){
                    auto it = find(fla[i-1][j-was[i]].begin(), fla[i-1][j-was[i]].end(), i);
                    if (it != fla[i-1][j-was[i]].end()) res[i][j]=res[i-1][j-was[i]];
                    else res[i][j]=max(res[i-1][j],res[i-1][j-was[i]]+val[i]*was[i]); 
                }
                else if((fu[i]!=0)){
                    auto it = find(fla[i-1][j-was[i]].begin(), fla[i-1][j-was[i]].end(), fu[i]);
                    if (it != fla[i-1][j-was[i]].end()) res[i][j]=max(res[i-1][j],res[i-1][j-was[i]]+val[i]*was[i]);
                    else if(j>=was[i]+was[fu[i]]) res[i][j]=max(res[i-1][j],res[i-1][j-was[i]-was[fu[i]]]+val[i]*was[i]+val[fu[i]]*was[fu[i]]);
                    else res[i][j]=res[i-1][j];
                }
                else res[i][j]=res[i-1][j];
            }
            else res[i][j]=res[i-1][j];
            if(j>=was[i]){
                if(res[i][j]==res[i-1][j-was[i]]+val[i]*was[i]){
                    fla[i][j].insert(fla[i][j].end(),fla[i-1][j-was[i]].begin(),fla[i-1][j-was[i]].end());
                    fla[i][j].push_back(i);
                }
                else if(res[i][j]==res[i-1][j-was[i]-was[fu[i]]]+val[i]*was[i]+val[fu[i]]*was[fu[i]]){
                    fla[i][j].insert(fla[i][j].end(),fla[i-1][j-was[i]-was[fu[i]]].begin(),fla[i-1][j-was[i]-was[fu[i]]].end());
                    fla[i][j].push_back(i);
                    fla[i][j].push_back(fu[i]);
                }
                else fla[i][j].insert(fla[i][j].end(),fla[i-1][j].begin(),fla[i-1][j].end());
            }
            else fla[i][j].insert(fla[i][j].end(),fla[i-1][j].begin(),fla[i-1][j].end());
        }
    }
    cout<<res[M][T]*10<<endl;
    return 0;
}