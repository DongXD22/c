#include <bits/stdc++.h>
using namespace std;
#define ll long long     
int main(){
    unsigned int n,ans,temp1,temp2;
    cin>>n;
    temp1=n<<16;
    temp2=n>>16;
    ans=temp1+temp2;
    cout<<ans<<endl;
    return 0;
}