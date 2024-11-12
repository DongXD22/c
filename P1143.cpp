#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int n,m,ori=0;
    string num,ans;
    cin>>n>>num>>m;
    int l=num.length();
    for(int i=l-1;i>=0;i--){
        if(num[i]<='9'&&num[i]>='0'){
            ori+=(num[i]-'0')*(int)pow(n,l-1-i);
        }
        else{
            ori+=(num[i]-'A'+10)*(int)pow(n,l-1-i);
        }
    }
    int ans_l=log(ori)/log(m);
    for(int i=ans_l;i>=0;i--){
        char temp=ori/pow(m,i)+'0';
        if(temp>'9'){
            temp='A'+temp-'0'-10;
        }
        ans+=temp;
        ori=ori%(int)pow(m,i);
    }
    cout<<ans<<endl;
    return 0;
}