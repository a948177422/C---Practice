#include <vector>
#include <iostream>
#include <algorithm>
#include <time.h>

using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {

		typedef vector<int>::iterator vec_it;
		vector<vector<int>> vec_ret;
		// 创建副本;
		vector<int> m_nums(nums);

		// 给定数组小于3个元素，返回空;
		if(nums.size() < 3)
			return vec_ret;             

		// 是否含有0的标识;
		bool is_zero_exist = false;     

		vector<int> vec_neg_nums;
		vector<int> vec_pos_nums;

		// 数组排序;
		sort(m_nums.begin(), m_nums.end());

		// 数组元素全为0,返回[0,0,0];
		if(m_nums[0] == 0 && *(m_nums.end() - 1) == 0){
			int answer[] = {0,0,0};
			vector<int> vec_answer(answer,answer + 3);
			vec_ret.push_back(vec_answer);    
			return vec_ret;
		}   
		// 全非负数，返回空;
		else if (m_nums[0] >= 0)
			return vec_ret; 
		// 全非正数，返回空;
		else if (*(m_nums.end() - 1) <= 0)
			return vec_ret; 

		// 检查是否含有0;
		if(find(m_nums.begin(), m_nums.end(), 0) != m_nums.end())
			is_zero_exist = true;

		// 分组，正数一组vec_pos_nums，负数一组vec_neg_nums;
		for (vector<int>::iterator iter = m_nums.begin(); iter != m_nums.end(); iter++){
			if(*iter < 0)
				vec_neg_nums.push_back(*iter);
			else if(*iter > 0)
				vec_pos_nums.push_back(*iter);
		}

		// 遍历数组,进行判断;		
		int last_neg = 0;	// 上一个负数，初始设为0;
		while(!vec_neg_nums.empty()){
			vec_it iter_neg = vec_neg_nums.begin();
			// 判断当前负数是否和上一个相等;
			if(*iter_neg == last_neg){
				vec_neg_nums.erase(iter_neg);
				continue;
			}
			// 创建临时副本;
			vector<int> tem_to_find_neg(vec_neg_nums);
			vector<int> tem_to_find_pos(vec_pos_nums);

			// 去除当前负数;
			tem_to_find_neg.erase(find(tem_to_find_neg.begin(), tem_to_find_neg.end(), *iter_neg));

			// 遍历临时正数组;
			while(!tem_to_find_pos.empty()){
				vec_it iter_pos = tem_to_find_pos.begin();
				// 需要在负数组中匹配;
				if(*iter_neg + *iter_pos > 0){
					// 在临时负数组中查找另一个匹配的负数;
					vec_it iter_target = find(tem_to_find_neg.begin(), tem_to_find_neg.end(), -(*iter_neg + *iter_pos));
					// 若匹配到;
					if(iter_target != tem_to_find_neg.end()){
						vector<int> vec_answer;
						vec_answer.push_back(*iter_neg);
						vec_answer.push_back(*iter_target);
						vec_answer.push_back(*iter_pos);
						vec_ret.push_back(vec_answer);
						// 删除已配对的数字和与其相同的数字;
						int now_pos = *iter_pos;
						int num_target = *iter_target;
						vec_it iter_flag_same = find(tem_to_find_pos.begin(), tem_to_find_pos.end(), *iter_pos);
						while (iter_flag_same != tem_to_find_pos.end()){
							iter_flag_same = tem_to_find_pos.erase(iter_flag_same);
							iter_flag_same = find(iter_flag_same, tem_to_find_pos.end(), now_pos);
						}/*
						iter_flag_same = find(tem_to_find_neg.begin(), tem_to_find_neg.end(), num_target);
						while (iter_flag_same != tem_to_find_neg.end()){
							iter_flag_same = tem_to_find_neg.erase(iter_flag_same);
							iter_flag_same = find(iter_flag_same, tem_to_find_neg.end(), num_target);
						}*/
					}
					// 未匹配到，删去当前遍历到的正数;
					else
						tem_to_find_pos.erase(iter_pos);
				}
				// 需要在正数组中匹配;
				else if (*iter_neg + *iter_pos < 0){

					int to_find = (int)abs(*iter_neg) - (int)(*iter_pos);
					vec_it iter_target = find(tem_to_find_pos.begin() + 1, tem_to_find_pos.end(), to_find);
					if(iter_target != tem_to_find_pos.end()){
						vector<int> vec_answer;
						vec_answer.push_back(*iter_neg);
						vec_answer.push_back(*iter_pos);
						vec_answer.push_back(*iter_target);
						vec_ret.push_back(vec_answer);
						// 删除已配对的数字和与其相同的数字;
						int now_pos = *iter_pos;
						int num_target = *iter_target;
						vec_it iter_flag_same = find(tem_to_find_pos.begin(), tem_to_find_pos.end(), *iter_pos);
						while (iter_flag_same != tem_to_find_pos.end()){
							iter_flag_same = tem_to_find_pos.erase(iter_flag_same);
							iter_flag_same = find(iter_flag_same, tem_to_find_pos.end(), now_pos);
						}
						iter_flag_same = find(tem_to_find_pos.begin(), tem_to_find_pos.end(), num_target);
						while (iter_flag_same != tem_to_find_pos.end()){
							iter_flag_same = tem_to_find_pos.erase(iter_flag_same);
							iter_flag_same = find(iter_flag_same, tem_to_find_pos.end(), num_target);
						}
					}
					else
						tem_to_find_pos.erase(iter_pos);
				}
				else if (is_zero_exist){
					vector<int> vec_answer;
					vec_answer.push_back(*iter_neg);
					vec_answer.push_back(0);
					vec_answer.push_back(*iter_pos);
					vec_ret.push_back(vec_answer);
					// 删除已配对的数字;
					tem_to_find_pos.erase(iter_pos);
					continue;
				}
				else if(!tem_to_find_pos.empty()){
					tem_to_find_pos.erase(tem_to_find_pos.begin());
				}				
			}
			//}
			last_neg = *iter_neg;
			vec_neg_nums.erase(vec_neg_nums.begin());
		}
			//iter_neg_las = iter_neg;
		//}


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

	vector<vector<int>> vec_answer = foo.threeSum(vec_num_rand);

	int x;
	cin >> x;
}