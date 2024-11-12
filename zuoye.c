#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#define ll long long
#define db double
int main(){
    int n,num[10]={0},x;
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%d",&x);
        if(x==0){
            num[0]++;
            continue;
        }
        while(x>0){
            num[x%10]++;
            x/=10;
        }
    }

    int maxx=0,suo,mnum[10],l;
    for(int i=0;i<10;i++){
        if(maxx<num[i]){
            maxx=num[i];
            l=0;
            mnum[l]=i;
            l++;
        }
        else if(num[i]==maxx){
            mnum[l]=i;
            l++;
        }
    }

    printf("%d:",maxx);
    for(int i=0;i<l;i++){
        printf(" %d",mnum[i]);
    }
    return 0;
}