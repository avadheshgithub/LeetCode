class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int tar) {
        int n = nums.size();

        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            int first = nums[i];
            int sec = tar-first;

            if(mp.find(sec) != mp.end()) return {mp[sec],i};
            else mp[first]=i; 
        }
        return {};
    }
};