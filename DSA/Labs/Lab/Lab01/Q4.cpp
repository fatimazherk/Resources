// Given an array of integers nums which is sorted in ascending order, and an
// integer
// target, write a function to search target in nums. If target exists, then return its
// index. Otherwise, return -1. You must write an algorithm with O(log n) runtime
// complexity.
// Example 1: Input: nums = [-1,0,3,5,9,12], target = 9, Output: 4
// Explanation: 9 exists in nums and its index is 4
// Example 2: Input: nums = [-1,0,3,5,9,12], target = 2, Output: -1
// Explanation: 2 does not exist in nums so return -1
// Constraints:
// 1 &lt;= nums.length &lt;= 104
// -104 &lt; nums[i], target &lt; 104
// All the integers in nums are unique.

#include<iostream>
using namespace std;

int binarySearch(int array[], int left, int right, int targetNum){
    while(left <= right){
        int mid = left + (right - left) / 2;
        
        // Check if targetNum is present at mid
        if(array[mid] == targetNum){
            return mid;
        }
        
        // If targetNum is greater, ignore the left half
        if(array[mid] < targetNum){
            left = mid + 1;
        }
        // If targetNum is smaller, ignore the right half
        else{
            right = mid - 1;
        }
    }
    
    // Target not found
    return -1;  
}

int main(){
    int array[] = {-1, 0, 3, 5, 9, 12};
    int x = 9;
    int n = sizeof(array) / sizeof(array[0]);
    int result = binarySearch(array, 0, n - 1, x);
    
    if(result == -1)
        cout << "Element is not present" << endl;
    else
        cout << "Element is present at index: " << result << endl;

    return 0;
}
