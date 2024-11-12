#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#define ll long long
#define db double
struct vl{
    int id;
    double v;
}V[1001];
int main(){
    double n,x,id;
    scanf("%lf",&n);
    for(int i=0;i<n;i++){
        scanf("%lf",&x);
        V[i]={i,1.33*3.14*pow(x,3)};
    }
    int l=n;
    while(l>0){
        for(int i=0;i<l-1;i++){
            if(V[i].v>V[i+1].v){
                vl temp=V[i];
                V[i]=V[i+1];
                V[i+1]=temp;
            }
            else if(V[i].v==V[i+1].v&&V[i].id<V[i+1].id){
                vl temp=V[i];
                V[i]=V[i+1];
                V[i+1]=temp;
            }
        }
        l--;
    }
    for(int i=n-1;i>=0;i--){
        printf("%.2f %d\n",V[i].v,V[i].id+1);
    }
    return 0;
}