#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct stu{
    string id;
    ll sc;
};
int main(){
    auto cmp= [](const stu& a, const stu& b){
        return a.id<b.id;
    };
    set<stu, decltype(cmp)> s(cmp);
    ll n,x,scr;
    string na;
    cin>>n;
    for(ll i=0;i<n;i++){
        cin>>x;
        if(x!=4) cin>>na;
        if(x==1){
            cin>>scr;
            if(!(s.insert({na,scr}).second)){
                s.erase(s.find({na,scr}));
                s.insert({na,scr});
            }
            else{
                s.insert({na,scr});
            }
            cout<<"OK"<<endl;
        }
        else if(x==2){
            auto it=s.find({na,0});
            if(it==s.end()){
                cout<<"Not Found"<<endl;
            }
            else{
                cout<<it->sc<<endl;
            }
        }
        else if(x==3){
            auto it=s.find({na,0});
            if(it==s.end()){
                cout<<"Not Found"<<endl;
            }
            else{
                s.erase(it);
                cout<<"Deleted successfully"<<endl;
            }
        }
        else{
            cout<<s.size()<<endl;
        }
    }
}