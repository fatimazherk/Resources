// You are given an m x n integer matrix with the
// following two properties: Each row is sorted in non-decreasing order. The first
// integer of each row is greater than the last integer of the previous row. Given an
// integer target, return true if target is in matrix or false otherwise. You must write a
// solution in O(log(m * n)) time complexity.

#include<iostream>
#include<vector>
using namespace std;

bool searchMatric(vector<vector<int>>& matrix, int target){
    if(matrix.empty() || matrix[0].empty()){
        return false;
    }
    int m=matrix.size();
    int n=matrix[0].size();
    int start=0,end=m*n-1;

    while(start<=end){
        int mid=start+(end-start)/2;
        int midValue=matrix[mid/n][mid%n];

        if(midValue==target){
            return true;
        } else if(midValue<target){
            start=mid+1;
        }else{
            end=mid-1;
        }
    }
    return false;
}

int main(){
    vector<vector<int>> matrix={
        {1,3,5,7},
        {10,11,16,20},
        {23,30,34,60}
    };
    int target =34;
    if(searchMatric(matrix,target)){
        cout<<"true"<<endl;
    }else{
        cout<<"false"<<endl;
    }
    }