// Given an m x n grid of characters board and a string word, 
// return true if word exists in the grid. The word can be 
// constructed from letters of sequentially adjacent cells, where adjacent
// cells are horizontally or vertically neighboring.
// The same letter cell may not be used more than once.

#include<iostream>
#include<vector>
#include<string>
using namespace std;


bool isSafe(vector<vector<char>>& board, string& word, int x, int y, int index){
    if(index == word.length()){
        return true;
    }
    if(x<0 || x>=board.size() || y<0 || y>=board[0].size() || board[x][y] != word[index]){return false;}
    char temp = board[x][y];
    board[x][y] = '*';


    bool found = isSafe(board, word, x+1, y, index+1)||
                 isSafe(board, word, x-1, y, index+1)||
                 isSafe(board, word, x, y+1, index+1)||
                 isSafe(board, word, x, y-1, index+1);
    
    board[x][y] = temp;
    return found;
}
bool ifExists(vector<vector<char>>& board, string word){
    for(int i = 0; i<board.size(); i++){
        for(int j = 0; j<board[0].size(); j++){
           if (isSafe(board, word, i, j, 0)){
            return true;
           }
        }
    }
    return false;
}
int main(){
    vector<vector<char>> board = {
    {'A','B','C','E'},
    {'S','F','C','S'},
    {'A','D','E','E'}
    };
    
    string w1 = "ABCCED", w2 = "ABCB";
    
    cout<<"Word "<<w1<<" is "<<(ifExists(board, w1)? "Found" : "not Found")<<endl;
    cout<<"Word "<<w1<<" is "<<(ifExists(board, w2)? "Found" : "not Found")<<endl;


    return 0;
}
