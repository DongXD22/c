#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,temp,i=0;
    vector<int> a;
    cin>>n;
    for(int i=0;i<n+1;i++){
        cin>>temp;
        a.push_back(temp);
    }
    for(;i<n;i++){
        int m=n-i;
        if(a[i]==0) continue;
        else{
            if(a[i]==1) cout<<"x^"<<m;
            else if(a[i]==-1) cout<<"-x^"<<m;
            else cout<<a[i]<<"x^"<<m;
            i++;
            break;
        }
    } 
    if(i==n) {
        cout<<a[n]<<endl;
        return 0;
    }
    for(;i<n;i++){
        int m=n-i;
        if(a[i]==0) continue;
        if(a[i]<0) cout<<"-";
        else cout<<"+";
        if(abs(a[i])==1) cout<<"x";
        else cout<<abs(a[i])<<"x";
        if(m!=1) cout<<"^"<<m;
    }
    if(a[n]==0) return 0;
    if(a[n]<0) cout<<"-";
    else cout<<"+";
    cout<<abs(a[n])<<endl;
    return 0;
}