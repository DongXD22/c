#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int n,ans=0;
    cin>>n;
    vector<vector<int>> game(n,vector<int>(2));
    for(int i=0;i<n;i++){
        cin>>game[i][0];
    }
    for(int i=0;i<n;i++){
        cin>>game[i][1];
    }
    sort(game.begin(),game.end()),[](vector<int>& a,vector<int>& b){
        return a[0]<b[0];
    };
    for(int i=n;i>=1;i--){
        int ma=0;
        bool flag=false;
        int suo=0;
        for(int j=0;j<n;j++){
            if(game[j][0]>=i&&game[j][1]>=ma){
                ma=game[j][1];
                flag=true;
                suo=j;
            }            
        }
        if(flag){
            ans+=ma;
            game[suo][0]=0;
        }
    }
    cout<<ans<<endl;
}