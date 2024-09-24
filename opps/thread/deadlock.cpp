#include <iostream>
#include <thread>
#include <vector>
#include <mutex>



using namespace std;
mutex gLock; //mutex or binary semaphore

static int shared_value = 0;

void shared_value_increament(){
    gLock.lock();
    shared_value = shared_value +1;  // |This section here is called critical section
    gLock.unlock(); //deadlock i.e lock is never 
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