
#include <iostream>
#include <cmath>
#include <algorithm>  
#include <iterator>
using namespace std;

int main() {
    int p[6000]={0};
    int l,n;
    cin>>l;
    cin>>n;    
    float m=static_cast<float>(l)/n;

    for(int i=0;i<n;i++) {
        int a;
        cin>>a;
        float b=abs(static_cast<float>(a)-m);
        p[i]=static_cast<int>(l-b-m+1);
    }
    int min=static_cast<int>(*max_element(begin(p),end(p)));
    cout<<min<<endl;
    return 0;
}