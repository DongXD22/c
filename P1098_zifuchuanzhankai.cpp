#include <bits/stdc++.h>
using namespace std;
int main() {
    int p1,p2,p3,y=0,max=0,l[1000]={0};
    string s;
    char v[1000][1000]={0},v_temp[1000][1000]={0};
    cin >> p1 >> p2 >> p3 >> s;
    for(int i=0;i<s.length();i++){
        if(s[i]=='-'&&s[i+1]>s[i-1]+1&&((isalpha(s[i-1])&&isalpha(s[i+1]))||(isdigit(s[i-1])&&isdigit(s[i+1])))){
            int x=0;
            for(int j=int(s[i-1])+1;j<int(s[i+1]);j++){
                for(int k=0;k<p2;k++){
                v[y][x]=char(j);
                x++;
                }
            }
            l[y]=x;
            y++;
        }
    }
    if(p1==2){
        for(int i=0;i<y;i++){
            if('a'<=v[i][0]&&v[i][0]<='z'){
                for(int j=0;j<l[i];j++){
                    v[i][j]=v[i][j]-32;
                }
            }        
        }
    }
    else if(p1==3){
        for(int i=0;i<y;i++){
            for(int j=0;j<l[i];j++){
                v[i][j]='*';
            }
        }
    }
    for(int i=0;i<y;i++){
        for(int j=0;j<l[i];j++){
            v_temp[i][j]=v[i][j];
        }
    }
    if(p3==2){
        for(int i=0;i<y;i++){
            int temp=l[i];
            for(int j=0;j<temp;j++){
                v[i][j]=v_temp[i][temp-j-1];
            }
        }
    }
    int n=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='-'){
            if(s[i]=='-'&&s[i+1]>s[i-1]+1&&((isalpha(s[i-1])&&isalpha(s[i+1]))||(isdigit(s[i-1])&&isdigit(s[i+1])))){
                for(int j=0;j<l[n];j++){
                    cout<<v[n][j];
                }
                n++;
            }
            else if(s[i+1]==s[i-1]+1){
                continue;
            }
            else cout<<'-';
        }
        else cout<<s[i];
    }
    cout<<endl;
    return 0;
}