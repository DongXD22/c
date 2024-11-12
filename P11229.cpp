#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int stick[10]={6,2,5,6,4,5,6,3,7,6},n,m;
    vector<int> ans;
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>n;
    if(n<=1){
        cout<<-1<<endl;
        continue;
    }
    bool flag2=false,flag=true;
    while(n>0){
        if(n<=7){
            if(n==6){
                if(ans.size()==0){
                    ans.push_back(6);
                    n-=6;
                }
                else{
                    ans.push_back(0);
                    n-=6;
                }
            }
            else if(n==5){
                ans.push_back(2);
                n-=5;
            }
            else if(n==4){
                ans.push_back(4);
                n-=4;
            }
            else if(n==3){
                ans.push_back(7);
                n-=3;
            }
            else if(n==2){
                ans.push_back(1);
                n-=2;
            }
            else{
                ans.push_back(8);
                n-=7;
            }
        }
        else{
            if(ans.size()==0&&n>=38){
                int temp=n-36;
                if(temp%7==0){
                    ans.push_back(8);
                    n-=7;
                }
                else if(temp%7==6){
                    ans.push_back(6);
                    n-=6;
                }
                else if(temp%7==5||temp%7==4||temp%7==3){
                    ans.push_back(2);
                    n-=5;
                }
                else{
                    ans.push_back(1);
                    n-=2;
                }
            }
            else if(ans.size()==0){
                if(n%7==0){
                    while(n!=0){
                        ans.push_back(8);
                        n-=7;
                    }
                }
                else if(n%6==0){
                    ans.push_back(2);
                    n-=6;
                }
                else if(n%6==5||n%6==4||n%6==3){
                    ans.push_back(2);
                    n-=5;
                }
                else if(n%6==2){
                    ans.push_back(1);
                    n-=2;
                }
                else if(n%6==1){
                    ans.push_back(8);
                    n-=7;
                }
            }
            else if(n%7==0){
                while(n!=0){
                    ans.push_back(8);
                    n-=7;
                }
            }
            else{
                if(n>=38&&flag){
                    ans.push_back(0);
                    ans.push_back(0);
                    ans.push_back(0);
                    ans.push_back(0);
                    ans.push_back(0);
                    ans.push_back(0);
                    n-=36;
                    flag=false;
                    flag2=true;
                }
                else if(flag2){
                    ans.push_back(8);
                    n-=7;
                }
                else{
                    ans.push_back(0);
                    n-=6;
                }
            }
        }
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i];
    }
    cout<<endl;
    ans.clear();
    }
}