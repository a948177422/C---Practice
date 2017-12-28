#include <vector>
#include <iostream>
#include <algorithm>
#include <time.h>
#include <cassert>

using namespace std;

#if 0
class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		if(nums.empty())
			return 0;

		auto iter = lower_bound(nums.begin(), nums.end(), target);

		if(iter == nums.end())
			return nums.size();

		return iter - nums.begin();
	}
};
#endif

#if 1
class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		if(nums.empty())
			return 0;

		int l = 0;
		int r = nums.size() -1;
		int mid = (l + r) / 2;

		while(l <= r){
			if(nums[mid] == target){
				return mid;
			}
			else if(nums[mid] < target)
				l = mid + 1;
			else
				r = mid - 1;
			mid = (l + r) / 2;
		}
		return nums[mid] < target ? mid + 1 : mid;
	}
};
#endif

int main()
{
	//int nums_1[] = {};
	int nums_2[] = {1,3,5,6};

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

	int res = foo.searchInsert(vec_num_2, 4);

	int xxx;
	cin >> xxx;
}

