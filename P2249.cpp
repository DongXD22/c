#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    int n, m,num[1000005]={0},que;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&num[i]);
    }
    for(int i=1;i<=m;i++){
        scanf("%d",&que);
        int now=1,l=n;
        bool flag=true;
        while(flag){
            int mid=(l-now+1)/2+now;
            if(num[mid]==que){
                for(int i=mid;i>=1;i--){
                    if(num[i]>num[i-1]){
                        printf("%d ",i);
                        flag=false;
                        break;
                    }
                }
                break;
            }
            if(now==mid){
                printf("%d ",-1);
                flag=false;
                break;
            }
            if(num[mid]>que&&flag){
                l=mid-1;
                continue;
            }
            else if(flag){                  
                now=mid+1;
                continue;
            }
        }
    }
    cout<<endl;
    return 0;
}