//https://leetcode.com/problems/find-median-from-data-stream/description/
/*
    As we need search the median value in data stream. it will be best way to solve
    using a heap or priority queue technice.

    By Default all the priority queue are maxHeap, We can do minHeap by extra arguments.
    std::priority_queue<int, std::vector<int>, std::greater<int>>

    If both the heaps are empty or the number is less than the top of maxHeapofSmallNUm then
    we will push to maxHeapForSmallNum [which is tracking the left half the midpoint]. else
    it will be pushed to minHeapForLargeNum(which is tracking the right half from the mid-point).

    First Half size can be same or +1 to 2nd half of the stream of data, if any discrpenceies
    then we will adjust the heap sizes.

    For the median if both has similar number of element then take the average both top values.
    Otherwise read the top value from 1st of heap
*/
#include<iostream>
#include<queue>
using namespace std;

class MedianFinder {
public:
    priority_queue<int> maxHeapForSmallNum;
    priority_queue<int, vector<int>, greater<int> > minHeapForLargeNum;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
       // if the number is first entry or less than the top of maxheap then push to maxheap else push to minheap
       if(maxHeapForSmallNum.empty() || maxHeapForSmallNum.top()>= num){
         maxHeapForSmallNum.push(num);
       }
       else{
        minHeapForLargeNum.push(num);
       }

       //Not balance both the heap
       if(maxHeapForSmallNum.size() > minHeapForLargeNum.size()+1 ){
        minHeapForLargeNum.push(maxHeapForSmallNum.top());
        maxHeapForSmallNum.pop();
       }
       else if(maxHeapForSmallNum.size() < minHeapForLargeNum.size()){
        maxHeapForSmallNum.push(minHeapForLargeNum.top());
        minHeapForLargeNum.pop();
       }
        
    }
    
    double findMedian() {
        // we have even number of elements, take the average of middle two elements
        // we divide both numbers by 2.0 to ensure we add two floating point numbers        
        if(maxHeapForSmallNum.size() == minHeapForLargeNum.size() ){
            return( (maxHeapForSmallNum.top()+ minHeapForLargeNum.top() )/2.0);
        }
        // because maxHeapForSmallNum will have one more element than the minHeapForLargeNum
        return maxHeapForSmallNum.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
