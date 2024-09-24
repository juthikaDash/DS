#include<iostream>
using namespace std;
int add(int x, int y){
    return x+y;
}
int main(){
    int (*fun)(int,int) = add; 
    int c = (*fun)(1,2);
    cout<<"c:"<<c<<endl;
    return 0;
}
