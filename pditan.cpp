#include <iostream>
#include <vector>
using namespace std;

int main(){
   int n;
   cin>>n;
   vector<vector<int>> A(4,vector<int>(n));
   for(int i=0;i<n;i++){
       int c,d;
       cin>>A[0][i]>>A[1][i]>>c>>d;
       int a=A[0][i]+c,b=A[1][i]+d;
       A[2][i]=a;
       A[3][i]=b;
       
   }
   int x,y,m=-1;
   cin>>x>>y;
   for(int i=0;i<n;i++){
      bool a=A[0][i]<=x&&A[1][i]<=y;
      bool b=A[2][i]>=x&&A[3][i]>=y;
      if(a&&b){
          m=i+1;
   }
   }
   cout<<m<<endl;
   return 0;
}