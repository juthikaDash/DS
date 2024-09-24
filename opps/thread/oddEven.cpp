#include <iostream>
#include <thread>
#include <mutex>

const int MAX_NUMBER = 100;
std::mutex mtx;
int currentNumber = 1;

void PrintOdd() {
    while (true) {
        std::unique_lock<std::mutex> lock(mtx);
        if (currentNumber > MAX_NUMBER) {
            break; // Stop when all numbers are printed
        }
        if (currentNumber % 2 == 1) {
            std::cout << "Odd: " << currentNumber << std::endl;
            currentNumber++;
        }

        // Edit - Not really needed as unique_lock will take care.
        //lock.unlock();
        //std::this_thread::yield(); // Yield the CPU to the other thread
    }
}

void PrintEven() {
    while (true) {
        std::unique_lock<std::mutex> lock(mtx);
        if (currentNumber > MAX_NUMBER) {
            break; // Stop when all numbers are printed
        }
        if (currentNumber % 2 == 0) {
            std::cout << "Even: " << currentNumber << std::endl;
            currentNumber++;
        }
        // Edit - Not really needed as unique_lock will take care.
        //lock.unlock(); // Release the lock
        //std::this_thread::yield(); // Yield the CPU to the other thread
    }
}

int main() {
    std::thread thread1(PrintOdd);
    std::thread thread2(PrintEven);

    thread1.join();
    thread2.join();

    return 0;
}