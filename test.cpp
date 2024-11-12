#include <iostream>
using namespace std;

int main()
{
    int n,v[2000001]={0};
double a,t;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>t;
        for(double j=1;j<=t;++j){
            if(v[int(j*a)]==0) v[int(j*a)]=1;
            else v[int(j*a)]=0;
        }
    }
    for(int i=1;;i++){
        if(v[i]==1) {
        cout<<i;
        break;}
    }
    return 0;
}