#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> a;
    for(int i=0;i<pow(2,n);i++){
        int x;
        cin>>x;
        a.push_back(make_pair(x,i+1));
    }
    while(a.size()!=2){
        vector<pair<int,int>> b;
        for(int i=0;i<a.size();i+=2){
            b.push_back(a[i].first>a[i+1].first?a[i]:a[i+1]);
        }
        a=b;
    }
    if (a[0].first < a[1].first) {
        cout << a[0].second << endl;
    } 
    else {
        cout << a[1].second << endl;
    }
    return 0;
}