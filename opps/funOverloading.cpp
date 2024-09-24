#include<iostream>

using namespace std;
void show(int i){
    cout<< "showing int : "<<i<<endl;
}
void show(double i){
    cout<< "showing double : "<<i<<endl;
}
void show(string i){
    cout<< "showing string : "<<i<<endl;
}
int main(){
    show(1);
    show("hello");
    show(3.4);

    return 0;
}
