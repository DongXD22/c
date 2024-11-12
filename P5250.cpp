#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    set<int> pq;
    int n,x,y;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x>>y;    
        if(x==1){
            auto it=pq.find(y);
            if(it!=pq.end()){
                cout<<"Already Exist"<<endl;
            }
            else pq.insert(y);
        }
        else{

            if(pq.size()==0) cout<<"Empty"<<endl;
            else{
                if(pq.size()==1){
                    cout<<*pq.begin()<<endl;
                    pq.erase(pq.begin());
                    continue;
                }
                for(auto it=++pq.begin();it!=pq.end();++it){
                    if(*it>=y){
                        auto temp=it;
                        --temp;
                        if(*it-y>=y-*temp){
                            cout<<*temp<<endl;
                            pq.erase(temp);
                            break;
                        }
                        else{
                            cout<<*it<<endl;
                            pq.erase(it);
                            break;
                        }
                    }
                    if(it==--pq.end()){
                        cout<<*it<<endl;
                        pq.erase(it);
                        break;
                    }
                }
            }
        }
    }
    return 0;
}