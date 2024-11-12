#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    vector<int> p;
    int n,t=0;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        p.push_back(x);
    }
    sort(p.begin(),p.end());
    for(int i=n;i>=1;i=i-2){
        if(i>=4){
            t+=p[0]+p[1]+p[i-1]+p[1];
        }
        if(i==3){
            t+=p[0]+p[1]+p[2];
        }
        if(i==2){
            t+=p[1];
        }
        }
    cout<<t<<endl;
    
    return 0;
}

