// Find all the numbers disappeared in an array
// leetcode 448

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        // cyclic sort
        int n = nums.size();
        int i=0;
        while(i<n){
            int correctIdx = nums[i]-1; //oth index
            if(nums[correctIdx]==nums[i]) i++; 
            else swap(nums[i],nums[correctIdx]);
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(nums[i]!=i+1) ans.push_back(i+1);
        }
        return ans;
    }
};

// methode 02 - 