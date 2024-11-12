#include <bits/stdc++.h>
using namespace std;
string pai(string s,string t,bool* flag){
    int l=s.length();
    for(int i=0;i<l;i++){
        if(s[i]>t[i]) {
            *flag=true;
            return s;
        }
        if(s[i]<t[i]) return t;
        else continue;
    }
    return s;
}
int main() {
    bool flag=false;
    int n,m,a=0;
    string s[20],max;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>s[i];
    m=s[0].length();
    max=s[0];
    for(int i=1;i<n;i++){
        if(s[i].length()<m) continue;
        if(s[i].length()==m){
            max=pai(s[i],max,&flag);
            if(flag) a=i;
            flag=false;
            continue;
        }
        if(s[i].length()>m){
            m=s[i].length();
            max=s[i];
            a=i;
        }
    }
    cout<<a+1<<endl<<max<<endl;
    return 0;
}