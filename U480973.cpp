#include <bits/stdc++.h>
using namespace std;
int solve(int x,string s,int* suo){
    for(int i=*suo;i<s.size();i++){
        if(s[i]=='?'){
            int suo=i;
            if(isdigit(s[suo+1])){
                string temp="s[suo+1]";
                int n=1;
                while(isdigit(s[suo+n+1])){
                    temp+=s[suo+n+1];
                    n++;
                }
                int p=stoi(temp);
            }
            if(s[suo]=='x') int p=solve(x,s,&suo);
        }
        suo++;
        for(int i=*suo;i<s.size();suo++){
            bool flag=true;
            if(s[i]=='?'){
                int suo=i;
                if(isdigit(s[suo+1])){
                    string temp="s[suo+1]";
                    int n=1;
                    while(isdigit(s[suo+n+1])){
                        temp+=s[suo+n+1];
                        n++;
                    }
                int q=stoi(temp);        
                }
                if(s[suo]=='x') int q=solve(x,s,&suo);
                flag=false;
                break;
            }
            else{
                reverse(s.begin(),s.end());
                string temp="s[0]";
                int h=1;
                while(isdigit(s[h])){
                    temp+=s[h];
                    h++;
                }
                reverse(temp.begin(),temp.end());
                int q=stoi(temp);
                break;
            }
        break;
        }
    break;
    }
    for(int i=*suo;i<s.size();i--)
    if(s[*suo-1]=='>') return x>
}
int main() {
    int m,q,x[100000];
    string s;
    cin >> m >> q;
    cin >> s;
    for(int i=0;i<q;i++){
        cin >> x[i];
    }

}