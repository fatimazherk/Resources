#include<iostream>
using namespace std;

void LinearSearch(int arr[], int size, int target) {
    bool found = false;
    
    for(int i = 0; i < size; i++) {
        if(arr[i] == target) {
            cout << "Target found at index " << i << " with value " << arr[i] << endl;
            found = true;
            return;  // Exit once the target is found
        }
    }

    if (!found) {
        cout << "Target not found in the array." << endl;
    }
}

int main() {
    int arr[] = {1, 4, 6, 7, 8, 7};
    int size = sizeof(arr) / sizeof(arr[0]);  // Calculate the array size
    int target = 7;
    
    LinearSearch(arr, size, target);
    
    return 0;
}
