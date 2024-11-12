#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    string s,ans[250];
    int k,suo=0,mi=10;
    cin >> s>>k;
    int n = s.length(),kt=k;
    for(int i=0;i<n-kt;i++){
        for(int j=suo;j<=k;j++){
            if(mi>s[j]-'0'){
                mi=s[j]-'0';
                ans[i]=s[j];
                suo=j+1;
            }
        }
        k++;
        mi=10;
    }
    bool flag=false;
    for(int i=0;i<n-kt;i++){
       if(ans[i]!="0"||flag){
           cout<<ans[i];
           flag=true;
       }
    }
    if(!flag) cout<<"0";
    return 0;
}