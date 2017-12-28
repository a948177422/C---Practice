class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> group_1;
        vector<int> group_2;
        vector<int> ret;
        typedef vector<int>::iterator vec_it;
        
        for(vec_it iter = nums.begin(); iter != nums.end(); iter++)
        {
            if((*iter) < (target/2))
                group_1.push_back(*iter);
            else
                group_2.push_back(*iter);
        }
        
        
        if(target%2 == 0)
        {
           for(vec_it iter_1 = group_1.begin(); iter_1 != nums.end(); iter_1++) 
           {
               if((*iter_1)%2 == 0)
               {
                   for(vec_it iter_2 = group_2.begin(); iter_2 != group_2.end(); iter_2++)
                   {
                       if((*iter_2)%2 == 0)
                       {
                           if((*iter_1) + (*iter_2) == target)
                           {
                               vec_it iter_res_1 = find(nums.begin(), nums.end(), *iter_1);
                               vec_it iter_res_2 = find(nums.begin(), nums.end(), *iter_2);                               
                               ret.push_back(distance(nums.begin(), iter_res_1));
                               ret.push_back(distance(nums.begin(), iter_res_2));
                               return ret;
                           }                               
                       }
                   }
               }
               else
               {
                   for(vec_it iter_2 = group_2.begin(); iter_2 != group_2.end(); iter_2++)
                   {
                       if((*iter_2)%2 == 1)
                       {
                           if((*iter_1) + (*iter_2) == target)
                           {
                               vec_it iter_res_1 = find(nums.begin(), nums.end(), *iter_1);
                               vec_it iter_res_2 = find(nums.begin(), nums.end(), *iter_2);                               
                               ret.push_back(distance(nums.begin(), iter_res_1));
                               ret.push_back(distance(nums.begin(), iter_res_2));
                               return ret;
                           }                               
                       }
                   }
               }

           }
        }        
        
        
/*
           for(vec_it iter_1 = group_1.begin(); iter_1 != nums.end(); iter_1++) 
           {
                   for(vec_it iter_2 = group_2.begin(); iter_2 != group_2.end(); iter_2++)
                   {
                           if((*iter_1) + (*iter_2) == target)
                           {
                               vec_it iter_res_1 = find(nums.begin(), nums.end(), *iter_1);
                               vec_it iter_res_2 = find(nums.begin(), nums.end(), *iter_2);                               
                               ret.push_back(distance(nums.begin(), iter_res_1));
                               ret.push_back(distance(nums.begin(), iter_res_2));
                               return ret;
                           }    
                   }   
           }*/
        
    }
};