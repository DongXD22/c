#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int n,a[125][125],m[125][125],ans=0,num=0;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];   
        }
    }
    for(int i=0;i<=n;i++){
        m[i][0]=0;
        m[i][1]=a[i][0];
        for(int j=2;j<=n;j++){
            m[i][j]=m[i][j-1]+a[i][j-1];
        }
    }
    for(int yl=1;yl<=n;yl++){
        for(int xl=1;xl<=n;xl++){
            for(int y=0;y<=n-yl;y++){
                for(int x=0;x<=n-xl;x++){
                    for(int k=y;k<=y+yl-1;k++){
                        num+=m[k][x+xl]-m[k][x];
                    }
                    ans=max(ans,num);
                    num=0;
                }
            }
        }
    }
    cout<<ans<<endl;
}