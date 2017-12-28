#include <vector>
#include <iostream>
#include <algorithm>
#include <time.h>

using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> vec_ret;

		// 不足3个数直接返回;
		if(nums.size() < 3)
			return vec_ret;

		// 排序;
		sort(nums.begin(), nums.end());

		// 全0或非正直接返回;
		auto iter_last = nums.end() - 1;
		if(nums[0] == 0 && *iter_last == 0){
			vector<int> vec_zero(3,0);
			vec_ret.push_back(vec_zero);
			return vec_ret;
		}
		if (*iter_last <= 0)
			return vec_ret;		

		for(auto iter = nums.begin(); iter != nums.end(); ++iter){
			// 全正，或遍历到正数后，直接返回向量;
			if(*iter > 0)
				break;
			// 和上一个数相同则直接跳到下一个数字;
			else if((iter != nums.begin()) && (*iter == *(iter - 1)))
				continue;

			auto iter_num_1 = iter + 1;
			auto iter_num_2 = iter_last;

			while(iter_num_1 < iter_num_2){
				int _3sum = *iter + *iter_num_1 + *iter_num_2;
				if(_3sum ==0){
					int nums_answer[] = {*iter, *iter_num_1, *iter_num_2};
					vector<int> vec_answer(nums_answer, nums_answer + sizeof(nums_answer)/sizeof(nums_answer[0]));
					vec_ret.push_back(vec_answer);
					// 跳过后续相同数字;
					while(*iter_num_1 == *(iter_num_1 + 1))
						++iter_num_1;
					while(*iter_num_2 == *(iter_num_2 - 1))
						--iter_num_2;					
					++iter_num_1;
					--iter_num_2;
				}
				else if(_3sum > 0)
					--iter_num_2;
				else
					++iter_num_1;
			}

		}

		return vec_ret;
	}
};

int main()
{
	//int nums_1[] = {};
	int nums_2[] = {-4,-1,0,-1,1,2};

	vector<int> vec_num_1;
	//vector<int> vec_num_1(nums_1, nums_1 + sizeof(nums_1)/sizeof(nums_1[0]));
	vector<int> vec_num_2(nums_2, nums_2 + sizeof(nums_2)/sizeof(nums_2[0]));
	vector<int> vec_num_rand;

	Solution foo;

	int ran_num;
	//srand((unsigned)time(0));
	srand(1);
	for(auto i = 0; i < 500; i++){
		ran_num = rand() % 2000 - 1000;
		vec_num_rand.push_back(ran_num);
	}

	int test_1 = -996 + 503;

	vector<vector<int>> vec_answer = foo.threeSum(vec_num_2);

	int x;
	cin >> x;
}