#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    long long b[100000]={0};
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> b[i];
    }
    for(int i=0;i<n;i++){
        int min=b[i];
        for(int j=i;j<n;j++){
            if(b[j]<min){
                min=b[j];
                b[j]=b[i];
                b[i]=min;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<b[i]<<" ";
    }
    cout<<endl;
    return 0;
}