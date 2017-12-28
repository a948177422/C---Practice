#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main()
{
	/***********
		map
	***********/
	std::map<int, std::string> my_map_1;

	// 赋值1;
	my_map_1[226] = "HouXuan";
	my_map_1[116] = "Liyaoyao";
	my_map_1[227] = "xiapengcheng";

	// 赋值2;
	my_map_1.insert(std::map<int, std::string>::value_type(2, "two"));

	// 查找;
	std::string name_1 = my_map_1[226];
	std::cout << name_1 <<std::endl;
	std::cout <<std::endl;
	cout << "容器的容量为：" << my_map_1.size() << endl << endl;

	std::string name_2 = my_map_1[229];
	std::cout << name_2 <<std::endl;
	cout << "容器的容量为：" << my_map_1.size() << endl << endl;

	// 遍历打印;
	for (std::map<int, std::string>::iterator iter = my_map_1.begin(); iter != my_map_1.end(); iter++)
	{
		std::cout << iter->first << std::endl;
		std::cout << iter->second << std::endl;
		std::cout << std::endl;
	}

	/***********
		array
	***********/
	/*
	int nums[] = {1, 2, 2};

	int size_1 = sizeof(nums);
	int size_2 = sizeof(nums[0]);

	int length_1 = sizeof(nums)/sizeof(nums[0]);
	for (unsigned i = 0; i < sizeof(nums)/sizeof(nums[0]); i++)
	{
		cout << nums[i] << " ";
	}
	cout << endl;

	nums[3] = 4;
	int length_2 = sizeof(nums)/sizeof(nums[0]);
	for (unsigned i = 0; i < sizeof(nums)/sizeof(nums[0]); i++)
	{
		cout << nums[i] << " ";
	}
	cout << endl;*/

	/************
		vector
	*************/
	int nums_0[] = {1,2,3};
	std::vector<int> nums(nums_0, nums_0 + 3);
	nums.insert(nums.begin(), 4);
	//nums.insert(nums.end() + 3, 19);

	int x;
	std::cin >> x;

	return 0;
}