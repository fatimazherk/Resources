// Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character. Note that after backspacing an empty text, the text will
// continue empty.
// Example 1: Input: s = "ab#c", t = "ad#c", Output: true, Explanation: Both s and t become "ac".

#include <iostream>
#include <string>
#include<stack>


using namespace std;


string buildFinalString(const string & str) {
    string result;
    for (char ch : str) { 
        if (ch == '#') {
            if (!result.empty()) {
                result.pop_back(); 
            }
        } else {
            result.push_back(ch); 
        }
    }
    return result;
    }


bool backspaceCompare(const string& s, const string& t) {
    return buildFinalString(s) == buildFinalString(t);
}


int main() {
    string s = "ab#c";
    string t = "ad#c";
    cout << (backspaceCompare(s, t) ? "True" : "False") << endl; 
    
    return 0;
}
