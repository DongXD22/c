#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
int main(){
    int k,n,x;
    int b[55];
    for(int i=0;i<55;i++){
        b[i]=10000;
    }
    scanf("%d%d",&k,&n);
    k--;
    int l=n;
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        b[i]=x;
    }
    while(l>0){
        for(int i=0;i<l-1;i++){
            if(b[i]>b[i+1]){
                int temp=b[i];
                b[i]=b[i+1];
                b[i+1]=temp;
            }
        }
        l--;
    }
    int i=0;
    while(k>=b[i]){
        k-=b[i];
        i++;
    }
    printf("%d",i);
    return 0;
}