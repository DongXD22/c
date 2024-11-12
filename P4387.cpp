#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int l,x,y;
        bool flag=true;
        stack<int> po,temp,pu;
        cin>>l;
        for(int j=0;j<l;j++){
            cin>>x;
            pu.push(x);
        }
        for(int j=0;j<l;j++){
            cin>>y;
            po.push(y);
        }
        for(int i=0;i<2*l+1;i++){
            bool flag=true;
            if(!po.empty()){
                if(po.top()==pu.top()){
                    po.pop();
                    pu.pop();
                    flag=false;
                }
            }
            if(!temp.empty()){
                if(temp.top()==pu.top()){
                    temp.pop();
                    pu.pop();
                    flag=false;
                }
            }
            if(flag){
                if(po.empty()) break;
                temp.push(po.top());
                po.pop();
            }
        }
        if(pu.empty()){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
}