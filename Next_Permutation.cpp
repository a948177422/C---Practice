#include <vector>
#include <iostream>
#include <algorithm>
#include <time.h>
#include <cassert>

using namespace std;

class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		unsigned int bits = 1;
		unsigned int j = nums.size() - 1;

		if(nums.size() > 1){
			// 从后向前找到不遵循升序排序的第一位,位数记为bits;
			while(j > 0 && nums[j] <= nums[j-1]){
				bits++;
				j--;
			}

			if(bits == nums.size())	// 整个数组为倒序;
				reverse(nums.begin(), nums.end());
			else if(bits == 1)	// 后两位为顺序, 则交换后两位;
				swap(nums[j], nums[j-1]);
			else{
				unsigned int i = nums.size() - 1;
				while(nums[i] <= nums[nums.size()-bits-1])	// 在倒序数字中找到第一个大于倒序数字前的第一位数字的数字;
					i--;
				swap(nums[i], nums[nums.size()-bits-1]); // 交换这两个数字;
				auto iter_1 = nums.begin() + nums.size() - bits;			
				reverse(iter_1, nums.end()); // 逆转数字排序;
			}
		}

	}
};

int main()
{
	//int nums_1[] = {};
	int nums_2[] = {4,2,4,4,3};

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

	foo.nextPermutation(vec_num_2);

	reverse(vec_num_2.begin(), vec_num_2.end());

	swap(vec_num_2[3], vec_num_2[2]);

	int xxx;
	cin >> xxx;
}

