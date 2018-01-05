#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	string str1 = "Text with some   spaces";
	string::size_type size0 = str1.size();
	std::remove(str1.begin(), str1.end(), ' ');
	string::size_type size1 = str1.size();
	str1.erase(std::remove(str1.begin(), str1.end(), ' '),  str1.end());  // "Textwithsomespaces"
	string::size_type size2 = str1.size();
}