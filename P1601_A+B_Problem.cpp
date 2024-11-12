#include <bits/stdc++.h>
using namespace std;
void input(string a, int num[600]){
    for(int i=0;i<a.length();i++){
        num[i]=a[a.length()-1-i]-'0';
    }
}
int main() {
    string a, b;
    cin >> a >> b;
    int temp = 0,l=max(a.length(),b.length()),
    num1[600]={0},num2[600]={0},res[600]={0};
    input(a,num1);
    input(b,num2);
    for(int i=0;i<l;i++){
        temp=num1[i]+num2[i]+temp;
        if(i<l-1){
            res[i]=temp%10;
            temp/=10;
        }
        else res[i]=temp;
    }
    for(int i=l-1;i>=0;i--){
        cout<<res[i];
    }
    return 0;
}