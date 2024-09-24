#include<iostream>
#include<future>

using namespace std;
int square(int x){
    return x*x;
}
int main(){

    future<int> asyncFunction = async(&square,12);
    //we can do some work here
    for(int i = 0; i<10;i++){
        cout<<"square of ["<<i<<"]"<<square(i)<<endl;
    }

    //we are blocked at get operation until our result has computed
    int result = asyncFunction.get();
    cout<<"Result : "<<result<<endl;
    return 0;
}