#include <iostream>
#include <thread>
#include <vector>
#include <mutex>



using namespace std;
mutex gLock; //mutex or binary semaphore

static int shared_value = 0;

void shared_value_increament(){
    lock_guard<mutex> lockGuard(gLock); 
    shared_value = shared_value +1;  // |This section here is called critical section
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