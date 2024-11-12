#include <bits/stdc++.h>
using namespace std;
int a,b,n,ans=1e9,step=0;
vector<int> ans_move;
void filla(int ab[]){ab[0]=a;}
void fillb(int ab[]){ab[1]=b;}
void emptya(int ab[]){ab[0]=0;}
void emptyb(int ab[]){ab[1]=0;}
void pourba(int ab[]){
    if(a-ab[0]>=ab[1]){
        ab[0]+=ab[1];
        ab[1]=0;
    }
    else{
        ab[1]-=a-ab[0];
        ab[0]=a;
    }
}
void pourab(int ab[]){
    if(b-ab[1]>=ab[0]){
        ab[1]+=ab[0];
        ab[0]=0;
    }
    else{
        ab[0]-=b-ab[1];
        ab[1]=b;
    }
}
void solve(int ab[],vector<int> &mov,vector<int> &situ,int& step){
    int prev_ab[2] = { ab[0], ab[1] };
    if (ab[1] == n) {
        if (step < ans) {
            ans = step;
            ans_move = mov;
        }
        return;
    }
    
    for(int i=1;i<=6;i++){
            
        bool flag=false;
        if(i==1&&ab[0]!=a) filla(ab);
        else if(i==2&&ab[1]!=b) fillb(ab);
        else if(i==3&&ab[0]!=0) emptya(ab);
        else if(i==4&&ab[1]!=0) emptyb(ab);
        else if(i==5&&ab[1]!=0&&ab[0]!=a) pourba(ab);
        else if(i==6&&ab[0]!=0&&ab[1]!=b) pourab(ab);
        else continue;   
        auto it = find(situ.begin(),situ.end(),ab[0]*1000+ab[1]);
        if(it!=situ.end()){
            ab[0] = prev_ab[0];
            ab[1] = prev_ab[1];
            continue;
        }
        
        mov(step)(i);
        situ(step)=ab[0]*1000+ab[1];
        step++;
        solve(ab,mov,situ,step);

        step--;
        mov.pop_back();
        situ.pop_back();
        ab[0] = prev_ab[0];
        ab[1] = prev_ab[1];
    }
}
int main() {
    
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int mov,situ;
        cin>>a>>b>>n;
        int ab[2]={0,0};
        ans=1e9;
        step=0;
        mov.clear();
        situ.clear();
        ans_move.clear();
        solve(ab,mov,situ,step);
        cout<<ans<<" ";
        for(int j=0;j<ans_move.size();j++) cout<<ans_move[j]<<" ";
        cout<<"\n";
    }
    return 0;
}