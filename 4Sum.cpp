#include <vector>
#include <iostream>
#include <algorithm>
#include <time.h>
#include <cassert>

using namespace std;

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> vec_ret;

		if(nums.size() < 4)
			return vec_ret;

		sort(nums.begin(), nums.end());

		for(unsigned p = 0; p != nums.size() - 3; ++p){
			if(p > 0 && nums[p] == nums[p - 1])
				continue;

			int to_find_for_p = target - nums[p];
			for(unsigned q = p + 1; q != nums.size() - 2; ++q){                
				if(q > p + 1 && nums[q] == nums[q -1])
					continue;

				int to_find_for_q = to_find_for_p - nums[q];
				unsigned i = q + 1;
				unsigned j = nums.size() - 1;

				while(i < j){
					if(nums[i] + nums[j] < to_find_for_q){
						++i;
						while(nums[i] == nums[i - 1] && i < j)	++i;
					}
					else if(nums[i] + nums[j] > to_find_for_q){
						--j;
						while(nums[j] == nums[j + 1] && i < j)	--j;
					}
					else{
						int nums_answer[] = {nums[p], nums[q], nums[i], nums[j]};
						vector<int> vec_an_answer(nums_answer, nums_answer + sizeof(nums_answer)/sizeof(nums_answer[0]));
						vec_ret.push_back(vec_an_answer);
						++i;
						while(nums[i] == nums[i - 1] && i < j)	++i;
						--j;
						while(nums[j] == nums[j + 1] && i < j)	--j;
					}

				}
			}
		}

		return vec_ret;
	}
};


int main()
{
	//int nums_1[] = {};
	int nums_2[] = {0,0,0,0};

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

	vec_result = foo.fourSum(vec_num_2, 0);

	int x;
	cin >> x;
}

