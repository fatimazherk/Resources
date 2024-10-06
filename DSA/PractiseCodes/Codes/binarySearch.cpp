//  INITIAL TRY WITH ERRORS !!!
// #include<iostream>
// using namespace std;

// void binarySearch(int arr[],int left, int mid, int right,int target){
//no need to initialize mid in the binary search function as you have to calculate it manually using
// mid=left+(right-left)/2
//     while(left<=right){
//         if(mid==target){
//             cout<<"Target Found at mid "<<arr[mid]<<endl;
//         }
//         else if(target<arr[mid]){
//             mid=right-1;
//it should be right=mid-1
//         }else if(target>mid){
//             mid=left+1;
//left=mid+1
//         }
//         return;
//     }
// }

// int main(){
//     int arr[1,3,5,7,4];
//     binarySearch(arr[],left,mid,right,5);

// } !!!!!!!!!!!!!!!!!!!!!!

#include<iostream>
using namespace std;

void binarySearch(int arr[], int left, int right, int target){
    while(left <= right){
        int mid = left + (right - left) / 2;  // Calculate mid point

        // Check if the target is at mid
        if(arr[mid] == target){
            cout << "Target found at index " << mid << " with value " << arr[mid] << endl;
            return;
        }
        
        // If target is smaller than mid, it must be in the left subarray
        else if(target < arr[mid]){
            right = mid - 1;
        }
        // If target is larger than mid, it must be in the right subarray
        else{
            left = mid + 1;
        }
    }
    // Target not found
    cout << "Target not found in the array." << endl;
}

int main(){
    int arr[] = {1, 3, 5, 7, 9};  // Correctly initializing the array
    int target = 5;
    
    // Initializing the left and right bounds
    int left = 0;
    int right = sizeof(arr) / sizeof(arr[0]) - 1;

    // Calling the binary search function
    binarySearch(arr, left, right, target);
    
    return 0;
}
