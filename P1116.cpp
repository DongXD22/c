#include <bits/stdc++.h>
using namespace std;
long long int step;
void pai(int tr[],int& l){
    if(l==1) return;
    for(int i=0;i<l-1;i++){
        if(tr[i]>tr[i+1]){
            int temp=tr[i];
            tr[i]=tr[i+1];
            tr[i+1]=temp;
            step++;
        }
    }
    l--;
    pai(tr,l);
}
int main(){
    int n,tr[10005];
    cin>>n;
    for(int i=0;i<n;i++) cin>>tr[i];
    step=0;
    pai(tr,n);
    cout<<step<<endl;
    return 0;
}