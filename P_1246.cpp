#include <bits/stdc++.h>
using namespace std;
#define ll long long
int con(int n,int m){
    int an=1;
    for(int i=m;i>=m-n+1;i--){
        an*=i;
    }
    for(int i=1;i<=n;i++){
        an/=i;
    }
    return an;
}
int ans=0;
void solve(string s,int l,char pre){
    char ch=pre+1;
    if(l==1){
        ans+=s[0]-ch;
        return;
    }
    while(ch<s[0]){
        ans+=con(l-1,26-(ch-'a'+1));
        ch++;
    }
    string t=s.substr(1,l-1);
    solve(t,l-1,s[0]);
}
int main(){
    string s;
    char pre='z';
    cin >> s;
    int n = s.length();
    int step=0;
    for(int i=n-1;i>=0;i--){
        if(pre<=s[i]){
            cout<<0<<endl;
            return 0;
        }
        pre=s[i];
    }
    for(int i=1;i<=n-1;i++){
        ans+=con(n-i,26);
    }
    solve(s,n,'a'-1);
    cout<<ans+1<<endl;
}