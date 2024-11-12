#include <bits/stdc++.h>
using namespace std;   
int main(){
    int n;
    string s;
    cin>>n>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]=='n'&&s[i+1]=='o'&&s[i+2]=='t'){
        s.erase(i,3);
        i=0; 
        }
    }
    cout<<s<<endl;
    return 0;

}
    