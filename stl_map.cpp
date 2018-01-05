#include <map>
#include <string>
#include <iostream>


using namespace std;

int main()
{
	map<int, string> mapStudents;

	// ================================
	//	插入;
	// ================================
	// insert()方法：
	// 无法插入已存在关键字（不可覆盖）;

	// 插入数据1.1： insert()方法插入pair;
	mapStudents.insert(pair<int, string>(1, "Jenny"));
	mapStudents.insert(pair<int, string>(6, "Jerry"));
	
	for(auto iter = mapStudents.begin(); iter != mapStudents.end(); iter++)
		cout << "StudentNumber: " << iter->first << "   Name: " << iter->second << endl;
	cout << "--------------------------------------------------" << endl;	

	// 插入数据1.2： insert()方法插入value_type:
	mapStudents.insert(map<int, string>::value_type(3, "Tom"));
	mapStudents.insert(map<int, string>::value_type(4, "Tim"));

	for(auto iter = mapStudents.begin(); iter != mapStudents.end(); iter++)
		cout << "StudentNumber: " << iter->first << "   Name: " << iter->second << endl;
	cout << "--------------------------------------------------" << endl;

	// 插入数据2：数组方式插入数据，可以覆盖相同关键字;
	pair<map<int, string>::iterator, bool> insertPair;

	insertPair = mapStudents.insert(pair<int, string>(1, "Jimmy"));	
	cout << insertPair.second << endl;
	cout << "用insert方法插入关键字为“1”的，姓名为“Jimmy”，的数据后：" << endl;
	for(auto iter = mapStudents.begin(); iter != mapStudents.end(); iter++)
		cout << "StudentNumber: " << iter->first << "   Name: " << iter->second << endl;

	mapStudents[1] = "Jimmy";
	cout << "用数组方法插入关键字为“1”的，姓名为“Jimmy”，的数据后：" << endl;
	for(auto iter = mapStudents.begin(); iter != mapStudents.end(); iter++)
		cout << "StudentNumber: " << iter->first << "   Name: " << iter->second << endl;
	cout << "--------------------------------------------------" << endl;

	// size()
	cout << "map的当前大小为： " << mapStudents.size() << endl;	


	// ================================
	//	遍历;
	// ================================
	// 1.迭代器正向遍历，略过不表;
	// 2.迭代器反向遍历;
	cout << "-------------------------反向遍历-------------------------" << endl;
	cout << "map的当前大小为： " << mapStudents.size() << endl;	
	for(map<int, string>::reverse_iterator iter = mapStudents.rbegin(); iter != mapStudents.rend(); iter++)
		cout << "StudentNumber: " << iter->first << "   Name: " << iter->second << endl;
	cout << "map的当前大小为： " << mapStudents.size() << endl;	
	// 3.数组方式遍历;
	// 采用数组遍历后，会改变map的size，如本例，遍历前size为4，遍历后size为6;
	cout << "-------------------------数组遍历-------------------------" << endl;
	cout << "map的当前大小为： " << mapStudents.size() << endl;	
	for(int i = 1; i <= mapStudents.size(); i++)
		cout << mapStudents[i] << endl;
	cout << "map的当前大小为： " << mapStudents.size() << endl;	

	// ================================
	//	查找;
	// ================================
	cout << "-------------------------查找-------------------------" << endl;
	// count()方法;
	cout << mapStudents.count(3) <<endl;
	// find()方法;
	auto iter = mapStudents.begin();
	if(mapStudents.find(6) != mapStudents.end()){
		cout << "find successfully!" << endl;
		cout << iter->first << "   " << iter->second << endl;
	}
	// upper_bound()、lower_bound()、Equal_range()
	{
	map<int, string>::iterator iter;
	iter = mapStudents.lower_bound(3);
	cout << "lower_bound(): " << endl;
	cout << iter->first << "   " << iter->second << endl;
	iter = mapStudents.upper_bound(3);
	cout << "upper_bound(): " << endl;
	cout << iter->first << "   " << iter->second << endl;
	pair<map<int, string>::iterator, map<int, string>::iterator> pairRange;
	pairRange = mapStudents.equal_range(3);
	cout << "equal_range(): " << endl;
	cout << pairRange.first->first << "   " << pairRange.first->second << endl;
	cout << pairRange.second->first << "   " << pairRange.second->second << endl;
	}

	// ================================
	//	删除;
	// ================================
	cout << "-------------------------删除-------------------------" << endl;
	cout << "map的当前大小为： " << mapStudents.size() << endl;	
	cout << "删除操作之前的map： " << endl;
	for(auto iter = mapStudents.begin(); iter != mapStudents.end(); iter++)
		cout << "StudentNumber: " << iter->first << "   Name: " << iter->second << endl;
	// 用迭代器删;
	map<int, string>::iterator iterDelete;
	iterDelete = mapStudents.find(1);
	mapStudents.erase(iterDelete);
	cout << "用迭代器删除后结果： " << endl;
	for(auto iter = mapStudents.begin(); iter != mapStudents.end(); iter++)
		cout << "StudentNumber: " << iter->first << "   Name: " << iter->second << endl;
	// 用关键字删;
	int flagDelete = mapStudents.erase(3);
	cout << "用关键字删除后结果： " << endl;
	cout << flagDelete << endl;
	for(auto iter = mapStudents.begin(); iter != mapStudents.end(); iter++)
		cout << "StudentNumber: " << iter->first << "   Name: " << iter->second << endl;
	// 用迭代器删除一个区间;
	mapStudents.erase(mapStudents.begin(), mapStudents.end());
	if(mapStudents.empty())
		cout << "容器现在是空的!" << endl;
	else
		cout << "删除失败！" << endl;

	int x;
	cin >> x;

	return 0;
}
