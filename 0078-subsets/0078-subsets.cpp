class Solution {
public:
    
    void ps(vector<int>&nums,vector<int>&temp,int i,vector<vector<int>>&ans){
        if(i==nums.size()){
            ans.push_back({temp});
            return;
        }
    
        temp.push_back(nums[i]); // include
        ps(nums,temp,i+1,ans);

        temp.pop_back(); // backtrack
        
        ps(nums,temp,i+1,ans); // exclude
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>temp;
        vector<vector<int>>ans;

        ps(nums,temp,0,ans);

        return ans;
    }
};