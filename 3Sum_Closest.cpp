#include <vector>
#include <iostream>
#include <algorithm>
#include <time.h>
#include <cassert>

using namespace std;

class Solution {
public:
	/*
		已通过;
	*/
	int threeSumClosest(vector<int>& nums, int target) {        

		// 若所给数组成员小于3个，中断程序;
		assert(nums.size() >= 3);

		sort(nums.begin(), nums.end());

		// 预判断，若目标数字落在所给数组所有可能和的范围之外，直接返回和的最大值（落于之右）或最小值（落于之左）;
		if(*nums.begin() + *(nums.begin() + 1) + *(nums.begin() + 2) > target)
			return *nums.begin() + *(nums.begin() + 1) + *(nums.begin() + 2);
		else if(*(nums.end() - 1) + *(nums.end() - 2) + *(nums.end() - 3) < target)
			return *(nums.end() - 1) + *(nums.end() - 2) + *(nums.end() - 3);

		int most_exact_number = 0;

		for(unsigned int n = 0; n < nums.size() - 2; ++n){
			unsigned int i = n + 1;
			unsigned int j = nums.size() - 1;

			// 只在第一次对most_exact_number初始化;
			if(n == 0 && i == 1 && j == nums.size() - 1)
				most_exact_number = nums[n] + nums[i] + nums[j];

			// 对当前nums[n]进行预判断，原理同上;
			if(nums[n] + nums[j] + nums[j-1] < target && abs(nums[n] + nums[j] + nums[j-1] - target) < abs(most_exact_number - target)){
				most_exact_number = nums[n] + nums[j] + nums[j-1];
				continue;
			}
			else if(nums[n] + nums[j] + nums[j-1] < target)
				continue;
			else if(nums[n] + nums[i] + nums[i+1] > target && abs(nums[n] + nums[i] + nums[i+1] - target) < abs(most_exact_number - target)){
				most_exact_number = nums[n] + nums[i] + nums[i+1];
				continue;
			}
			else if(nums[n] + nums[i] + nums[i+1] > target)
				continue;

#if 0
			int sum_now = nums[n] + nums[i] + nums[j];
			bool is_i_change;


			if(sum_now < target){
				/*
				while(i < j && sum_now < target){
					sum_last_1 = sum_now;
					if(++i != j)
						sum_now = nums[n] + nums[i] + nums[j];
				}
				while(i < j && sum_now > target){
					sum_last_2 = sum_now;
					if(--j != i)
						sum_now = nums[n] + nums[i] + nums[j];
				}
				*/
				is_i_change = true;

				while(i < j){
					if(abs(sum_now - target) < abs(most_exact_number - target))
						most_exact_number = sum_now;
					
					if(is_i_change)
						++i;
					else
						--j;

					sum_now = nums[n] + nums[i] + nums[j];

					if(sum_now < target)
						is_i_change = true;
					else if(sum_now > target)
						is_i_change = false;
					else
						return sum_now;
				}

			}
			else if(sum_now > target){
				/*
				while(i < j && sum_now > target){
					sum_last_1 = sum_now;					
					if(--j != i)
						sum_now = nums[n] + nums[i] + nums[j];					
				}
				while(i < j && sum_now < target){
					sum_last_2 = sum_now;
					if(++i != j)
						sum_now = nums[n] + nums[i] + nums[j];
				}
				*/
				is_i_change = false;

				while(i < j){
					if(abs(sum_now - target) < abs(most_exact_number - target))
						most_exact_number = sum_now;
					
					if(is_i_change)
						++i;
					else
						--j;

					sum_now = nums[n] + nums[i] + nums[j];

					if(sum_now < target)
						is_i_change = true;
					else if(sum_now > target)
						is_i_change = false;
					else
						return sum_now;
				}

			}
			else
				return target;  
		}
#endif
			while(i < j){
				int sum_now = nums[n] + nums[i] +nums[j];

				if(abs(sum_now - target) < abs(most_exact_number - target))
					most_exact_number = sum_now;
				if(sum_now < target)
					++i;
				else if(sum_now > target)
					--j;
				else
					return target;
			}
		}
		return most_exact_number;
	}
};
int main()
{
	//int nums_1[] = {};
	int nums_2[] = {-1,0,1,1,55};

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

	int result = foo.threeSumClosest(vec_num_2, 3);

	int x;
	cin >> x;
}