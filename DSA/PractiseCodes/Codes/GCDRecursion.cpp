#include<iostream>
using namespace std;

//A recursive function for obtaining Greates Common Divisor (GCD) of two numbers
// GCD(a,b) = GCD(b, a % b), a > b
int GCD(int a, int b){ // Tail - Recursion
	if (b==0){
		return a;
	}
	else{
		GCD(b, a%b);
	}
}

//A recursive function for obtaining factorial of a number
int factorial(int n){ // non-Tail Recusrsion
	if (n==0 || n==1){
		return 1;
	}
	return n*factorial(n-1);
	
}

int main(){
	int a=48, b=20;
	cout<<"GCD of a = "<<a<<" and b = "<<b<< " is : "<<GCD(a, b)<<endl;
	int n=4;
	cout<<"Factorial of n = "<<n<<" is : "<<factorial(4)<<endl;
			
}

