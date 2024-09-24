#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>
#include<unistd.h>

using namespace std;
mutex gLock;
condition_variable cv;

int main(){
    int shared_res = 0;
    bool notified = false;

    //Reporter theade
    thread repoter([&]{
       unique_lock<mutex> lock(gLock);
       if(!notified){
            cv.wait(lock);
       }
       cout<<"Shared result : "<<shared_res<<endl;
       cout<<"Reporting is complete"<<endl;
 
    });

    //Worker thread
    thread worker([&]{
        unique_lock<mutex> lock(gLock);
        shared_res = 42+7+1;
        notified = true;
        sleep(5); 
        cout<< "Worker completed"<<endl;
        cv.notify_one();
         
    });
    worker.join();
    repoter.join();

    cout<<"Main is completed"<<endl;
    return 0;
}