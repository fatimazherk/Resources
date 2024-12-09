// Given an array nums of distinct integers, 
// return all the possible permutations. 
// You can return the answer in any order.

#include <iostream>
using namespace std;
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}


void printPermutation(int nums[], int size) {
    for (int i = 0; i < size; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
}


void permute(int nums[], int start, int size) {
    if (start == size) {
        printPermutation(nums, size);
        return;
    }
    for (int i = start; i < size; i++) {
        swap(nums[start], nums[i]);   // Manually swap the elements
        permute(nums, start + 1, size); // Recurse for the next element
        swap(nums[start], nums[i]);   // Backtrack (undo the swap)
    }
}


int main() {
    int nums[] = {1, 2, 3};
    int size = sizeof(nums) / sizeof(nums[0]);


    permute(nums, 0, size);


    return 0;
}
