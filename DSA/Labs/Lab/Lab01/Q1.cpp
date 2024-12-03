// Write a C++ program to copy data of a 2D array in a 1D array using Column
// Major Order.

#include<iostream>

using namespace std;

void TwoDimensionalToOneDimensional(int** array, int row, int column, int* oneDimArray){
    int index=0;
    for(int j=0; j < column; j++){
        for(int i=0; i < row; i++){
            oneDimArray[index++]= array[i][j];
        }
    }
}

int main(){
    int row=4;
    int column=4;
    int** array=new int*[row];
    for(int i=0; i<row; i++){
       array[i]=new int[column];
    }
    int value=1;
    for(int i=0; i<row; i++){
        for(int j=0;j<column;j++){
            array[i][j]=value++;
        }
    }
    int* oneDimArray=new int[row*column];
    TwoDimensionalToOneDimensional(array,row,column,oneDimArray);
    cout<<"1D Array In Column Major Order: "<<endl;
    for(int i=0; i<row*column; i++){
        cout<<oneDimArray[i]<<" ";
    }
    cout<<endl;
    for(int i=0; i<row;i++){
        delete[] array[i];
    }
    delete[] array;
    delete[] oneDimArray;
    return 0;
}