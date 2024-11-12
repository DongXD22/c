#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int n;
    string ans,temp;
    cin>>n;
    cin>>ans;
    for(int i=1;i<n;i++){
        cin>>temp;
        int len;
        if()
        for(int i=1;i<=min(temp.length(),ans.length());i++){
            if(ans.substr(ans.length()-1-i,i)==temp.substr(0,i)){
                len++;
            }
            else break;
        }
        ans+=temp;
    }
    return 0;
}