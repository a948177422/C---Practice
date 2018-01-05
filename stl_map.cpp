#include <map>
#include <string>
#include <iostream>


using namespace std;

int main()
{
	map<int, string> mapStudents;

	// ================================
	//	����;
	// ================================
	// insert()������
	// �޷������Ѵ��ڹؼ��֣����ɸ��ǣ�;

	// ��������1.1�� insert()��������pair;
	mapStudents.insert(pair<int, string>(1, "Jenny"));
	mapStudents.insert(pair<int, string>(6, "Jerry"));
	
	for(auto iter = mapStudents.begin(); iter != mapStudents.end(); iter++)
		cout << "StudentNumber: " << iter->first << "   Name: " << iter->second << endl;
	cout << "--------------------------------------------------" << endl;	

	// ��������1.2�� insert()��������value_type:
	mapStudents.insert(map<int, string>::value_type(3, "Tom"));
	mapStudents.insert(map<int, string>::value_type(4, "Tim"));

	for(auto iter = mapStudents.begin(); iter != mapStudents.end(); iter++)
		cout << "StudentNumber: " << iter->first << "   Name: " << iter->second << endl;
	cout << "--------------------------------------------------" << endl;

	// ��������2�����鷽ʽ�������ݣ����Ը�����ͬ�ؼ���;
	pair<map<int, string>::iterator, bool> insertPair;

	insertPair = mapStudents.insert(pair<int, string>(1, "Jimmy"));	
	cout << insertPair.second << endl;
	cout << "��insert��������ؼ���Ϊ��1���ģ�����Ϊ��Jimmy���������ݺ�" << endl;
	for(auto iter = mapStudents.begin(); iter != mapStudents.end(); iter++)
		cout << "StudentNumber: " << iter->first << "   Name: " << iter->second << endl;

	mapStudents[1] = "Jimmy";
	cout << "�����鷽������ؼ���Ϊ��1���ģ�����Ϊ��Jimmy���������ݺ�" << endl;
	for(auto iter = mapStudents.begin(); iter != mapStudents.end(); iter++)
		cout << "StudentNumber: " << iter->first << "   Name: " << iter->second << endl;
	cout << "--------------------------------------------------" << endl;

	// size()
	cout << "map�ĵ�ǰ��СΪ�� " << mapStudents.size() << endl;	


	// ================================
	//	����;
	// ================================
	// 1.����������������Թ�����;
	// 2.�������������;
	cout << "-------------------------�������-------------------------" << endl;
	cout << "map�ĵ�ǰ��СΪ�� " << mapStudents.size() << endl;	
	for(map<int, string>::reverse_iterator iter = mapStudents.rbegin(); iter != mapStudents.rend(); iter++)
		cout << "StudentNumber: " << iter->first << "   Name: " << iter->second << endl;
	cout << "map�ĵ�ǰ��СΪ�� " << mapStudents.size() << endl;	
	// 3.���鷽ʽ����;
	// ������������󣬻�ı�map��size���籾��������ǰsizeΪ4��������sizeΪ6;
	cout << "-------------------------�������-------------------------" << endl;
	cout << "map�ĵ�ǰ��СΪ�� " << mapStudents.size() << endl;	
	for(int i = 1; i <= mapStudents.size(); i++)
		cout << mapStudents[i] << endl;
	cout << "map�ĵ�ǰ��СΪ�� " << mapStudents.size() << endl;	

	// ================================
	//	����;
	// ================================
	cout << "-------------------------����-------------------------" << endl;
	// count()����;
	cout << mapStudents.count(3) <<endl;
	// find()����;
	auto iter = mapStudents.begin();
	if(mapStudents.find(6) != mapStudents.end()){
		cout << "find successfully!" << endl;
		cout << iter->first << "   " << iter->second << endl;
	}
	// upper_bound()��lower_bound()��Equal_range()
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
	//	ɾ��;
	// ================================
	cout << "-------------------------ɾ��-------------------------" << endl;
	cout << "map�ĵ�ǰ��СΪ�� " << mapStudents.size() << endl;	
	cout << "ɾ������֮ǰ��map�� " << endl;
	for(auto iter = mapStudents.begin(); iter != mapStudents.end(); iter++)
		cout << "StudentNumber: " << iter->first << "   Name: " << iter->second << endl;
	// �õ�����ɾ;
	map<int, string>::iterator iterDelete;
	iterDelete = mapStudents.find(1);
	mapStudents.erase(iterDelete);
	cout << "�õ�����ɾ�������� " << endl;
	for(auto iter = mapStudents.begin(); iter != mapStudents.end(); iter++)
		cout << "StudentNumber: " << iter->first << "   Name: " << iter->second << endl;
	// �ùؼ���ɾ;
	int flagDelete = mapStudents.erase(3);
	cout << "�ùؼ���ɾ�������� " << endl;
	cout << flagDelete << endl;
	for(auto iter = mapStudents.begin(); iter != mapStudents.end(); iter++)
		cout << "StudentNumber: " << iter->first << "   Name: " << iter->second << endl;
	// �õ�����ɾ��һ������;
	mapStudents.erase(mapStudents.begin(), mapStudents.end());
	if(mapStudents.empty())
		cout << "���������ǿյ�!" << endl;
	else
		cout << "ɾ��ʧ�ܣ�" << endl;

	int x;
	cin >> x;

	return 0;
}
