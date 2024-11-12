#include <bits/stdc++.h>
using namespace std;
#define ll long long
void base(int n,int r) {
    if(n==0) return;
    int m=n%r;
    if(m<0){
        m-=r;
        n+=r;
    }
    if(m>=10){
        m=m-10+'A';
    }
    else m+='0';
    base(n/r,r);
    printf("%c",m);
}    
int main(){
    int n,r;
    cin>>n>>r;
    printf("%d=",n);
    base(n,r);
    printf("(base%d)",r);
    return 0;
}