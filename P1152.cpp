#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int n,m[1005];
    cin >> n;
    int s[1005]={100000005};
    for(int i=0;i<n;i++){
        cin >> m[i];
    }
    for(int i=1;i<n;i++){
        s[i-1]=(abs(m[i]-m[i-1]));
    }
    sort(s,s+n-1);
    for(int i=0;i<n-1;i++){
        if(s[i]!=i+1){
            cout<<"Not jolly"<<endl;
            return 0;
        }
    }
    cout<<"Jolly"<<endl;
    return 0;
}
