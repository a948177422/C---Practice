#include <Windows.h>
#include <iostream>
#include <string>

using namespace std;

void printWelcome(int len)
{
	printf("欢迎欢迎 -- %d/n", len);
}

void printGoodbye(int len)
{
	printf("送客送客 -- %d/n", len);
}

void callback(int times, void (* print)(int))
{
	int i;
	for (i = 0; i < times; ++i)
	{
		print(i);
	}
	printf("/n我不知道你是迎客还是送客!/n/n");
}

int main()
{
	callback(10, printWelcome);
	callback(10, printGoodbye);
	printWelcome(5);


	char fileName[MAX_PATH];
	char* pstr;
	string* str;
	
	strcpy_s(fileName, "C:\\Game\\play\\bin.exe");
	
	char* pchar;

	pchar = strrchr(fileName, '\\');


	cout<<pchar<<endl;

	pchar[1] = '\0';
	string pluginPath = string(fileName) + "players\\";

	cout<<pchar<<endl;
	cout<<pluginPath<<endl;
// 	pstr = strrchr(fileName, '\\');
// 	//(*pstr)[1] = '\0';
// 	string str = "ring";
// 	const char* pchar1 = str.c_str();
// 	char char2[20];
// 
// 	//strcpy_s(char2, str.c_str());
// 
// 	for(int i = 0; i < str.size(); ++i)
// 	{
// 		char2[i] = pchar1[i];
// 		cout << char2[i] << endl;
// 	}
// 
// 	char2[str.size()] = '\0';
// 
// 	string str1(char2);
// 	cout << str1 << " and str1's length is " << str1.size() << endl;
// 
// 	cout << sizeof(char2) << endl;
// 	cout << strlen(char2) << endl;
// 	cout << sizeof(char*) << endl;
// 	cout << str.size() << endl;
// 
// 	cout << pchar1 << endl;
// 	cout << char2 << endl;
// 
// 	cout << pstr << endl;

	system("pause");

	return 1;
}