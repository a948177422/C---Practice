#include <vector>
#include <iostream>
#include <algorithm>
#include <time.h>
#include <cassert>

using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {        
		auto iter_1 = nums.begin();
		auto iter_2 = iter_1 + 1;

		for(; iter_2 != nums.end(); iter_2++){
			if(*iter_1 != *iter_2)
				*(++iter_1) = *iter_2;
		}

		return distance(nums.begin(),iter_1);
	}
};

int main()
{
	//int nums_1[] = {};
	int nums_2[] = {1,2,3,4};

	vector<int> vec_num_1;
	//vector<int> vec_num_1(nums_1, nums_1 + sizeof(nums_1)/sizeof(nums_1[0]));
	vector<int> vec_num_2(nums_2, nums_2 + sizeof(nums_2)/sizeof(nums_2[0]));
	vector<int> vec_num_rand;

	vector<vector<int>> vec_result;

	Solution foo;

	int ran_num;
	//srand((unsigned)time(0));
	srand(1);
	for(auto i = 0; i < 500; i++){
		ran_num = rand() % 2000 - 1000;
		vec_num_rand.push_back(ran_num);
	}

	int test_1 = -996 + 503;

	int res = foo.removeDuplicates(vec_num_2);
	
	reverse(vec_num_2.begin(), vec_num_2.end());

	swap(vec_num_2[3], vec_num_2[2]);

	int xxx;
	cin >> xxx;
}

