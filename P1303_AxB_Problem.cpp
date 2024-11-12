#include <bits/stdc++.h>
using namespace std;
void input(string a, int num[]){
    for(int i=0;i<a.length();i++){
        num[i]=a[a.length()-1-i]-'0';
    }
}
void plus_(int* num1,int* num2){
    int temp=0,res[4000]={0};
    for(int i=0;i<4000;i++){
        temp=num1[i]+num2[i]+temp;
        if(i<3999){
            res[i]=temp%10;
            temp/=10;
        }else res[i]=temp;
    }
    copy(res,res+4000,num1);
}
int main() {
    string a, b;
    cin >> a >> b;
    int temp = 0,l=(a.length()+b.length()),
    num1[2000]={0},num2[2000]={0},
    temp1[4000]={0},temp2[4000]={0};
    input(a,num1);
    input(b,num2);
    if(a=="0" || b=="0"){
        cout<<0<<endl;
        return 0;
    }
    for(int i=0;i<a.length();i++){
        for(int j=0;j<b.length();j++){
            temp=num1[i]*num2[j]+temp;
            temp2[j+i]=temp%10;
            temp/=10;
            if(j==b.length()-1) temp2[j+i+1]=temp,temp=0;
        }
        plus_(temp1,temp2);
        memset(temp2, 0, sizeof(temp2));
    }
    int i=l-1;
    if(temp1[l-1]==0) i--;
    for(;i>=0;i--){
        cout<<temp1[i];
    }
    return 0;
}