#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

// use the space to optimize the time
// Method: Auxilary Hash table
class Solution{

public:

    vector<int> sum_two_brutal(vector<int>& nums, int target){
        int size = nums.size();
        for(int i = 0; i < size; i ++){
            for(int j = i + 1; j < size; j ++){
                if(nums[j] + nums[i] == target){
                    return {i, j};
                }
            }
        }
        return {};
    }


    vector<int> sum_two_hash_table(vector<int>& nums, int target){
        int size = nums.size();
        unordered_map<int, int> dic;
        for(int i = 0; i < size; i++){
            if(dic.find(target - nums[i]) != dic.end()){
                return {dic[target - nums[i]], i};
            }
            dic.emplace(nums[i], i);
        }
        return {};
    }

};