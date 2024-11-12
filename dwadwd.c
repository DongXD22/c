#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define ll long long
int main() {
    int n,m,tri[30][30];
    scanf("%d%d",&n,&m);
    if(n>m){
        int temp=n;
        n=m;
        m=temp;
    }
    if(n==0||m==0){
        printf("0");
        return 0;
    }
    for(int i=1;i<=25;i++){
        for(int j=1;j<=i;j++){
            if(j==1 || j==i) tri[i][j]=1;
            else tri[i][j]=(tri[i-1][j-1]+tri[i-1][j])%10;
        }
    }
    for(int i=n;i<=m;i++){
        for(int j=i;j<m;j++){
            printf(" ");
        }
        for(int j=1;j<=i;j++){
            if(j==i) printf("%d\n",tri[i][j]);
            else printf("%d ",tri[i][j]);         
        }
    }
    return 0;
}
    