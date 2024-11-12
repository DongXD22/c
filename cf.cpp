#include <iostream>
using namespace std;
void turn(int*dir){
    (*dir)=((*dir)+1)%4;
}
void move(int arr[12][12],int*dir,int*x,int*y){
    if(*dir==0) {
        if(arr[*x-1][*y]==0) {
            (*x)--;
        }else turn(dir);
    }else if(*dir==1) {
        if(arr[*x][*y+1]==0) {
            (*y)++;
        }else turn(dir);
    }else if(*dir==2) {
        if(arr[*x+1][*y]==0) {
            (*x)++;
        }else turn(dir);
    }else if(*dir==3) {
        if(arr[*x][*y-1]==0) {
            (*y)--;
        }else turn(dir);
    }
}
int main() {
    int map_c[12][12],map_f[12][12],dir_c=0,dir_f=0,t=0,x_c=0,y_c=0,x_f=0,y_f=0;
    string tem;
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
                map_c[i][j] = 1;
                map_f[i][j] = 1;
        }
    }
    for(int i=1;i<11;i++) {
        cin>>tem;
        for(int j=1;j<11;j++) {
        if(tem[j-1]=='.') map_c[i][j]=0,map_f[i][j]=0;
        else if(tem[j-1]=='F') map_c[i][j]=0,map_f[i][j]=0,x_f=i,y_f=j;
        else if(tem[j-1]=='C') map_c[i][j]=0,map_f[i][j]=0,x_c=i,y_c=j;
        }
    }
    while(1) {
        if(x_c==x_f && y_c==y_f){
            cout<<t<<endl;
            break;
        }
        if(t>=1000){
            cout<<0<<endl;
            break;
        }
        move(map_c,&dir_c,&x_c,&y_c);
        move(map_f,&dir_f,&x_f,&y_f);
        t++;
    } 
    return 0; 
}   