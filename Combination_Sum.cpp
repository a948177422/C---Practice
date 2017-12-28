#include <vector>
#include <iostream>
#include <algorithm>
#include <time.h>
#include <cassert>

using namespace std;

class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>> vec_ret;

		return vec_ret;
	}
};

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

	vector<vector<int>> res = foo.combinationSum(vec_num_2, 4);

	// factorial
	int xxx = 0;
	int factorial = 1;
	cin >> xxx;

	while(xxx > 0){
		factorial *= xxx--;
	}

	cout << factorial;

	int pauseline;
	cin >> pauseline;
}

