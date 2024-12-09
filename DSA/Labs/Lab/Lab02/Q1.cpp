// A palindrome is a word, phrase, number, or another sequence of
// characters that reads the same backward and forwards. Can you
// determine if a given string, s, is a palindrome? Write a Program using
// stack for checking whether a string is palindrome or not.
#include<iostream>
#include<string>
#include<stack>
using namespace std;

bool isPalindrome(const string& msg){
    stack<char> Stack;

    // Push all characters of the string onto the stack
    for(int i = 0; i < msg.length(); i++){
        Stack.push(msg[i]);  // Use msg[i] instead of s[i]
    }

    // Compare the characters of the string with those popped from the stack
    for(int i = 0; i < msg.length(); i++){
        char top = Stack.top();
        Stack.pop();

        if(msg[i] != top){
            return false;  // Return false immediately if a mismatch is found
        }
    }

    return true;  // Return true if all characters matched
}

int main(){
    string msg;
    cout << "Enter string: ";
    getline(cin, msg);

    if(isPalindrome(msg)){
        cout << "The given string is palindrome" << endl;
    }
    else{
        cout << "The given string is not palindrome" << endl;
    }
    return 0;
}
