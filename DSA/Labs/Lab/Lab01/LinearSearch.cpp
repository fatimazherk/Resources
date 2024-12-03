#include<iostream>
using namespace std;

int linearSearch(int arr[], int n, int target) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == target) {
            cout << "Target number found at index: " << i << endl;
            return i;
        }
    }
    cout << "Target not found" << endl;
    return -1;
}

int main() {
    int arr[] = {2, 4, 5, 8, 9, 10, 20, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    linearSearch(arr, n, 20);
}
