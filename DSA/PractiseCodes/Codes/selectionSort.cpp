#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        // Assume the first element of the unsorted part is the minimum
        int minIndex = i;

        // Find the index of the minimum element in the unsorted part
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j; // Update minIndex if a smaller element is found
            }
        }

        // Swap the found minimum element with the first element of the unsorted part
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {64, 25, 12, 22, 11}; // Example array
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate size of the array

    cout << "Original array: ";
    printArray(arr, n);

    selectionSort(arr, n); // Sort the array

    cout << "Sorted array: ";
    printArray(arr, n); // Print the sorted array

    return 0;
}
