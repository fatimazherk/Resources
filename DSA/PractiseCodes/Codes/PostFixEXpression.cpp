#include<iostream>
#include<stack>
using namespace std;

void postfix(string expression){
	stack<int> data;
	for(int i=0; i<expression.size(); i++){
		if (isdigit(expression[i]))
			data.push(expression[i]-'0');
		else{
			int op2 = data.top();
			data.pop();
			int op1 = data.top() ;
			data.pop();
			switch(expression[i]){
				case '+':
					data.push(op1+op2);
					break;
				case '-':
					data.push(op1-op2);
					break;
				case '*':
					data.push(op1*op2);
					break;
				case '/':
					data.push(op1/op2);
					break;
				default:
					cout<<"invalid operator"<<endl;
			} 
		}
	}
	int res = data.top();
	data.pop();
	if (data.empty())
		cout<<"The result for the given expression " << expression<< " is : "<<res<<endl;
	else
		cout<<expression<<" is an invalid expression!"<<endl;
		return;
		
}
int main(){
	string exp="53+82-";
	postfix(exp);
}