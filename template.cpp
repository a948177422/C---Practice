#include <iostream>
#include <string>
#include <sstream>

using namespace std;

template<class T1, class T2>
T2 TypeConvert(const T1 &scr, T2 &ret){	
	stringstream ss;
	ss << scr;
	ss >> ret;

	return ret;
}

int main()
{
	string strNum = "";
	int num = 100;
	TypeConvert(500, strNum);
	TypeConvert(num, strNum);

	int x;
	cin >> x;
}


