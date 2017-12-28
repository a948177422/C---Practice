#include <vector>
#include <iostream>
#include <algorithm>
#include <time.h>
#include <cassert>

using namespace std;
int OutuutFactorial(int num){
	int ret = 1;

	if(num > 1)
		return num * OutuutFactorial(num - 1);
	else
		return 1;
}

int main()
{
	// factorial
	int x = 0;
	int factorial = 1;
	cin >> x;

	// loop method
	while(x > 0){
		factorial *= x--;
	}

	cout << factorial;

	// recursive method


	// pause
	int pauseline;
	cin >> pauseline;
}

