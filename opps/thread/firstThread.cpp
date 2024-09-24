#include<iostream>
#include<thread>
using namespace std;

void test(int x){
    cout<<"hello: this is test theread with x :"<<x<<endl;
}
int main(){

    thread myThread(&test,10);
    myThread.join();
    cout<< "Hello : this is main thread"<<endl;

    return 0;
}