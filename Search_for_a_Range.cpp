#include <vector>
#include <iostream>
#include <algorithm>
#include <time.h>
#include <cassert>

using namespace std;

// ==================================================
// 未采用STL算法：lower_bound、upper_bound
// ==================================================
#if 0
class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> ret;

		if(nums.empty()){
			ret.push_back(-1);
			ret.push_back(-1);
			return ret;
		}

		int l = 0;
		int r = nums.size() - 1;        

		while(l <= r){
			int mid = (l + r) / 2;
			if(nums[mid] == target){
				int r1 = mid;
				int l1 = mid;

				int mid1 = (l + r1) / 2;
				while(l < r1){                    
					if(nums[mid1] == target)
						r1 = mid1;                    
					else
						l = mid1 + 1;
					mid1 = (l + r1) / 2;
				}
				ret.push_back(l);

				int mid2 = (l1 + r) / 2;
				while(l1 < r){
					if(nums[mid2] == target)
						l1 = mid2;
					else
						r = mid2 - 1;
					mid2 = (l1 + r) / 2 + 1;
				}
				ret.push_back(r);

				return ret;
			}
			else if(nums[mid] < target)
				l = mid + 1;
			else
				r = mid - 1;
		}

		ret.push_back(-1);
		ret.push_back(-1);
		return ret;
	}
};
#endif

// ==================================================
// 采用STL算法：lower_bound、upper_bound
// ==================================================
#if 1
class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> vec_ret(2, -1);

		if(nums.empty())
			return vec_ret;

		auto iter_left = lower_bound(nums.begin(), nums.end(), target);
		auto iter_right = upper_bound(nums.begin(), nums.end(), target);
		
		if (iter_left == nums.end())
			return vec_ret;
		
		if(*iter_left != target)
			return vec_ret;

		vec_ret[0] = distance(nums.begin(), iter_left);
		vec_ret[1] = distance(nums.begin(), --iter_right);

		return vec_ret;
	}
};
#endif

int main()
{
	//int nums_1[] = {};
	int nums_2[] = {1};

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

	vector<int> res = foo.searchRange(vec_num_2, 1);

	int xxx;
	cin >> xxx;
}

