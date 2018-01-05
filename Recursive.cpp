#include <vector>
#include <iostream>
#include <algorithm>
#include <time.h>
#include <cassert>

using namespace std;

unsigned int OutuutFactorial(unsigned int num){
	if(num > 1)
		return num * OutuutFactorial(num - 1);
	else
		return 1;
}

static long fibonacci(int n) {  
	if((0 == n) || (1 == n)) {
		return n;  
	}else {
		cout << fibonacci(n-1) + fibonacci(n-2) << "  ";
		return fibonacci(n-1) + fibonacci(n-2);  
	}
	
}  

int main()
{/*
	// factorial
	int x = 0;
	int factorial = 1;
	cin >> x;

	// loop method
	while(x > 0){
		factorial *= x--;
	}

	cout << factorial << endl;

	// recursive method
	unsigned int input_1 = 0;
	cin >> input_1;
	cout << "calculate factorial with recursive method: "<< OutuutFactorial(input_1) << endl;
	*/
	// recursive fibonacci
	/** 
     * fibonacciÊýÁÐ 
     * @param n 
     * @return 
     */  
	cout << fibonacci(4) << endl;


	// pause
	int pauseline;
	cin >> pauseline;
}

