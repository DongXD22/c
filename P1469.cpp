#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main(){
    int n,ans,x;

    cin >> n;
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        ans^=x;
    }
    cout << ans << endl;    
    return 0;
}