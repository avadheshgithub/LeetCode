// Subsets II
// Leetcode 90

// Time Complexity: O(2^n)
// Space Complexity: O(n)


class Solution {
public:
    void getAllSubsets(vector<int>&nums,vector<int>&ans,int i,vector<vector<int>>&allSubsets){
        if(i==nums.size()){
            allSubsets.push_back({ans});
            return;
        }
        // include
        ans.push_back(nums[i]);
        getAllSubsets(nums,ans,i+1,allSubsets);

        ans.pop_back();
        // Exclude --> Extra for Avoide duplicate
        int idx = i+1;
        while(idx<nums.size() && nums[idx] == nums[idx-1]) idx++;
        getAllSubsets(nums,ans,idx,allSubsets);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>ans;
        vector<vector<int>>allSubsets;

        getAllSubsets(nums,ans,0,allSubsets);

        return allSubsets;
    }
};


// methode 02 - using bit manipulation
// Time Complexity: O(2^n)
// Space Complexity: O(n)   
/*
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        int n = nums.size();
        int totalSubsets = 1 << n; // 2^n   
        for (int i = 0; i < totalSubsets; ++i) {
            vector<int> subset;
            for (int j = 0; j < n; ++j) {
                if (i & (1 << j)) { 
                    subset.push_back(nums[j]);
                }
            }   
            if (find(result.begin(), result.end(), subset) == result.end()) {
                result.push_back(subset);
            }
        }
        return result;
    }
};
*/