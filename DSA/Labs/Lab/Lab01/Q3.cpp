// The median is the middle value in an ordered integer list. If the size of the list is
// even, there
// is no middle value, and the median is the mean of the two middle values.
// For example, for arr = [2,3,4], the median is 3.
// For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
// Implement the MedianFinder class:
// - MedianFinder() initializes the MedianFinder object.
// - void addNum(int num) adds the integer num from the data stream to the data
// structure.
// - double findMedian() returns the median of all elements so far. Answers within
// 10-5 of
// the actual answer will be accepted.

#include<iostream>
#include<vector>
using namespace std;

class MedianFinder{
    vector<double> arr;
    int count;
    public:
    MedianFinder(int c=0):count(c){}
    void addNum(int num){
        arr.push_back(num);
        count++;
    }
    double findMedian(){
        if(count%2==1){
            return arr.at(count/2);
        }
        else{
            return(arr.at(count/2)+arr.at(count/2-1))/2.0;
        }
    }
};
int main(){
    MedianFinder medianFinder;
    medianFinder.addNum(1);
    medianFinder.addNum(2);
    cout<<medianFinder.findMedian()<<endl;
    medianFinder.addNum(3);
    cout<<medianFinder.findMedian()<<endl;
    return 0;
}