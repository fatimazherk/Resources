#include<iostream>
using namespace std;
#include<vector>
void indent(int n){
	for(int i=0; i<4*n; i++)
		cout<<" ";
}

//Find all possible subset of a set
void Calsubsets(vector<int>& inp, vector<int>& current_sub, vector<vector<int> >& result, int index){
	// visualization of internal calls
	indent(index);
	cout<<"Calsubsets( current_subset = {";
	for(int i=0; i<current_sub.size(); i++)
		cout<<current_sub[i]<<", ";
	cout<< "}, i = "<< index << ")"<<endl; 
	
	result.push_back(current_sub);
	for(int i=index; i<inp.size(); i++){
		//make a choice
		current_sub.push_back(inp[i]);
		
		//explore other options after the current choice
		Calsubsets(inp, current_sub,  result, i+1);
		
		//backtrack - unchoose the last choice
		current_sub.pop_back();
	}

}
//Find all possible bit combinations for n bits
void printBinary(int n, string current=""){
	if(n==0){
		cout<<current<<endl;
		return;
	}
	printBinary(n-1, current+'0');
	printBinary(n-1, current+'1');
}

int main(){
	vector<int> inp;
	inp.push_back(1);
	inp.push_back(2);
	inp.push_back(3);
	//cout<<"size: "<<input.size()<<endl;
	vector<int> subset;
	vector<vector<int> > res;
	Calsubsets(inp, subset, res, 0);
	
	cout<<"\n======= Print all the subsets of a give set {";
	for(int i=0;i<inp.size(); i++)
		cout<<inp[i]<<", ";
	cout<<"} ========="<<endl;
	
	for(int i=0; i<res.size(); i++){
		cout<<"{";
		for(int j=0; j<res[i].size(); j++)
			cout<<res[i][j]<<", ";
		cout<<"}"<<endl;
		}
	
	int n=3;
	cout<<"======= Print all the bits combination for an n = "<<n<<" number of bits ========="<<endl;
	printBinary(n);
		
}