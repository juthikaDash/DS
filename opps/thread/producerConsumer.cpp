
#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <condition_variable>
#include <queue>

using namespace std;

class Buffer{
  int capacity;
  std::queue<int> myq;
  std::mutex mtx;
  std::condition_variable cv;

  public:
  Buffer(int size){
    this->capacity = size;
  }

  Buffer(): Buffer(0){}

  void add_data(int num){
    std::lock_guard<std::mutex> lock(mtx);
    if((int)myq.size() < capacity){
      myq.push(num);
      cv.notify_one();
    }
  }

  int get_data(){
    std::unique_lock<std::mutex> lock(mtx);
    if(myq.size() <= 0){
      cv.wait(lock, [&]{return (myq.size() > 0);});
    }

    cout << "After conditional wait" << endl;
    auto ret_data = myq.front();
    myq.pop();
    return ret_data;
  }

};

void producer(Buffer &buffer){
  // putting a sleep to show that consumer is getting schedules first
  std::this_thread::sleep_for(std::chrono::seconds(1));

  cout << "\nProducer.." << endl;
  
  // Running the loop for 10 times only
  int cnt = 10;
  while(cnt >0){
    int num = rand();
    buffer.add_data(num);
    std::this_thread::sleep_for(std::chrono::seconds(5));
    --cnt;
  }

  // This will indicate the consumer to STOP
  buffer.add_data(10);
}

void consumer(Buffer &buffer){
  cout << "\nConsumer.." << endl;
  while(1){
    cout << "Consumer waiing..." << endl;
    int data = buffer.get_data();
    cout << "Received Data: " << data << endl;
    if (data == 10){break;}
  }

}

int main(){
  
    Buffer buffer(10);

    std::thread thread_producer(producer, std::ref(buffer));
    std::thread thread_consumer(consumer, std::ref(buffer));

    thread_producer.join();
    thread_consumer.join();

    std::cout << "Program complete" << std::endl;
    return 0;
}
