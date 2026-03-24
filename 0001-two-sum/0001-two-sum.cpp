class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;

        for(int i=0;i<nums.size();i++){
            int comp = target - nums[i];

            if(mp.count(comp)){
                return {i,mp[comp]};
            }
            mp[nums[i]] = i;
        }
        return {-1,-1};
    }
};