// Permutations 
// Leetcode 46

// time complexity: O(n! * n)
// space complexity: O(n)

class Solution {
public:
    void getPerms(vector<int>&nums,int idx,vector<vector<int>>&ans){
        if(idx==nums.size()){
            ans.push_back(nums);
        }
        for(int i=idx;i<nums.size();i++){
            swap(nums[idx],nums[i]); // idx place => ith Elment Choice
            getPerms(nums,idx+1,ans);
            swap(nums[idx],nums[i]);  // BackTracking 
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        getPerms(nums,0,ans);
        return ans;
    }
};


// method 2: Using STL next_permutation
// time complexity: O(n! * n)
// space complexity: O(n)

class solution {
public:

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        do {
            ans.push_back(nums);
        }
        while (next_permutation(nums.begin(), nums.end()));
        return ans;
    }
};

