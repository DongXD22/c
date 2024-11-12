#include <bits/stdc++.h>
using namespace std;
string mult(string a,string b)
string comb(int n,int k){
    long long int res=1;
    if(k>n) return 0;
    if(k==0||k==n) return 1;
    if(n-k<k) k=n-k;
    for(int i=1;i<=k;i++){
        res*=n-i+1;
        res/=i;
    }
    return res;
}
int step = 0;
long long int solve(int l) {
    int r=0;
    long long ans=0;
    while(l>=r){
        ans+=comb(l,r);
        l--;
        r++;
    }
    return ans;
}
int main() {
    int l;
    cin >> l;
    cout << solve(l)<<endl;
    return 0;
}