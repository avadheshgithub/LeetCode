// Subsets 
// Leetcode -78

// Methode 01 - backtracking
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

        ans.pop_back(); // backTrcking
        // Exclude
        getAllSubsets(nums,ans,i+1,allSubsets);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>ans;
        vector<vector<int>>allSubsets;

        getAllSubsets(nums,ans,0,allSubsets);

        return allSubsets;
    }
};


// methode 02 - bit manipulation
// Time Complexity: O(2^n)
// Space Complexity: O(n)
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>allSubsets;
        int n = nums.size();
        int totalSubsets = 1 << n; // 2^n   
        for(int i = 0; i < totalSubsets; i++){
            vector<int>subset;
            for(int j = 0; j < n; j++){
                if(i & (1 << j)){ // check if jth bit is set in i
                    subset.push_back(nums[j]);
                }
            }
            allSubsets.push_back(subset);
        }
        return allSubsets;
    }
};