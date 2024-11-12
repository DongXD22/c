#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
db a,b,c,d;
vector<db> ans;
db func(db x){
    return a*x*x*x+b*x*x+c*x+d;
}
void search(db x1,db x2){
    if(ans.size()>2) return;
    if(func(x1)==0){
        ans.push_back(x1);
        search(x1+0.1,100);
        search(-100,x1-0.1);
        return;
    }
    if(func(x2)==0){
        ans.push_back(x2);
        search(x2+0.1,100);
        search(-100,x2-0.1);
        return;
    }
    if(abs(x1-x2)<1e-4&&func(x1)*func(x2)>0){
        return;
    }
    db x3=(x1+x2)/2;
    if(func(x3)==0||(abs(x1-x2)<1e-4&&func(x1)*func(x2)<0)){
        ans.push_back(x3);
        search(x3+0.1,100);
        search(-100,x3-0.1);
        return;
    }
    if(func(x1)*func(x3)<0){
        search(x1,x3);
        return;
    }
    if(func(x2)*func(x3)<0){
        search(x3,x2);
        return;
    }
    search(x1,x3);
    search(x3,x2);
}
int main(){
    cin>>a>>b>>c>>d;
    db x1=-100,x2=100;
    search(x1,x2);
    sort(ans.begin(),ans.end());
    for(auto x:ans){
        printf("%.2lf ",x);
    }
    return 0;
}