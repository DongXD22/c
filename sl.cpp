#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    string a[100];
    int b[100][100]={0};
    
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]=='*'){
                b[i][j]=-1;
            }
            if(a[i][j]=='?'){
                b[i][j]=0;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(b[i][j]!=-1){
                for(int k=-1;k<=1;k++){
                    for(int l=-1;l<=1;l++){
                        if(i+k>=0 && i+k<n && j+l>=0 && j+l<m && b[i+k][j+l]==-1){
                            b[i][j]++;
                        }
                    }
                }
            }
        }
    }
    string c[100][100];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(b[i][j]==-1){
                c[i][j]="*";
            }else{
                c[i][j]=to_string(b[i][j]);
            }
        }  
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<c[i][j];
        }
        cout<<endl;
    }
}