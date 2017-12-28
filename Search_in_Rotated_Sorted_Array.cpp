#include <vector>
#include <iostream>
#include <algorithm>
#include <time.h>
#include <cassert>

using namespace std;

/*
class Solution {
public:
	int search(vector<int>& nums, int target) {
		if(nums.empty())
			return -1;

		int i = 0;
		int j = nums.size() - 1;

		if(target > nums[i]){
			i++;
			while(i < nums.size() && nums[i] > nums[i-1]){
				if(nums[i] == target)
					return i;
				else
					i++;
			}
		}
		else if(target < nums[i]){
			if(target < nums[j]){
				j--;
				while(j >= 0 && nums[j] < nums[j+1]){
					if(nums[j] == target)
						return j;
					else
						j--;                    
				}
			}
			else if(target == nums[j])
				return j;
		}
		else
			return i;

		return -1;

	}
};
*/

class Solution {
public:
	int search(vector<int>& nums, int target) {
		if(nums.empty())
			return -1;

		unsigned int l = 0;
		unsigned int r = nums.size() - 1;
		unsigned int mid = (l + r) / 2;

		while(l <= r){
			if(nums[mid] == target)
				return mid;
			// 左半部分有序;
			else if(nums[l] <= nums[mid]){
				if(nums[l] == target)
					return l;
				else if(nums[l] < target && target < nums[mid]){
					r = mid - 1;
					mid = (l + r) / 2;
				}
				else{
					l = mid + 1;
					mid = (l + r) / 2;
				}
			}
			// 右半部分有序;
			else if(nums[mid] <= nums[r]){
				if(nums[r] == target)
					return r;
				else if(nums[mid] < target && target < nums[r]){
					l = mid + 1;
					mid = (l + r) / 2;
				}
				else{
					r = mid - 1;
					mid = (l + r) / 2;
				}
			}
		}

		return -1;
	}
};

int main()
{
	//int nums_1[] = {};
	int nums_2[] = {3,1};

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

	int res = foo.search(vec_num_2, 1);

	int xxx;
	cin >> xxx;
}

