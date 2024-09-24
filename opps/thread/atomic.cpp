#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include<atomic>



using namespace std;
mutex gLock; //mutex or binary semaphore
static atomic<int> shared_value = 0;

//static int shared_value = 0;

void shared_value_increament(){
    shared_value++;  // |This section here is called critical section
}
int main(){
    vector<thread> threads;
    for(int i =0; i<10;i++){
        threads.push_back(thread(shared_value_increament));
    }

    for(int i = 0; i<10;i++){
        threads[i].join();
    }

    cout<<"Shared value : "<< shared_value<<endl;
    return 0;
}