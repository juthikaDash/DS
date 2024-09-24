#include<iostream>
#include<vector>

using namespace std;

template<typename T>
class Stack{
    private:
        vector<T> elements;
    public: 
        void push(T const& element){
            elements.push_back(element);
        }
        void pop(){
            if(!elements.empty()){
                elements.pop_back();
            }
        }
        T top() const{
            if(!elements.empty()){
                return elements.back();
            }
            else{
                throw std::out_of_range("Stack is empty");
            }
        }
        bool isEmpty() const {
            return elements.empty();
        }

        size_t size() const{
            return elements.size();
        }
};

int main(){
    //interger stack
    Stack<int> intStack;
    intStack.push(5);
    intStack.push(15);
    intStack.push(25);
    intStack.push(35);

    cout<< "Integer stack"<<endl;
    cout<<"Size:"<< intStack.size()<<endl;
    cout<<"Top element: "<< intStack.top()<<endl;


    //sting stack
    Stack<string> strStack;
    strStack.push("hello");
    strStack.push("world");
    cout<<"String stack"<<endl;
    cout<<"Size:"<< strStack.size()<<endl;
    cout<<"Top element:"<< strStack.top()<<endl;

    return 0;

}