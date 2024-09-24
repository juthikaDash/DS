#include<iostream>
using namespace std;
class counter{
    int count;
    public:
    counter(){
        count = 0;
    }
    counter(int x){
       this->count = x;
    }
    counter& operator++(){ //prefix
        count++;
        return *this;

    }
        counter operator++(int ){ //prefix
        counter temp = *this;
        count++;
        return temp;
    }
    void print(){
        cout<<"Counter : "<<count<<endl;
    }
};

int main(){
    counter a(5);
    a++;
    a.print();
    counter b = a++;
    b.print();    
    return 0;
}