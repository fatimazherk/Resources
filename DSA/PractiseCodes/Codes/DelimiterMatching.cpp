#include<iostream>
#include<stack>
using namespace std;

bool Matching(string exp){
	stack<char> data;
	for(int i=0; i<exp.size(); i++){
		if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
			data.push(exp[i]);
		else if (exp[i]==')' || exp[i]=='}' || exp[i]==']'){
			if (data.empty())
				return 0;
			else if((data.top()=='(' && exp[i]==')') || (data.top()=='[' && exp[i]==']') || (data.top()=='{' && exp[i]=='}'))
				data.pop();
			else
				return 0;
				}
	}
	return data.empty();
}
int main(){
	string in="(a{+b)*}c";
	if(Matching(in))
		cout<<"Delimiter matching successful!"<<endl;
	else
		cout<<"Delimeter matching unsuccessful!"<<endl;
}