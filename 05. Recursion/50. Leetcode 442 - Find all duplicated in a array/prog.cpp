// Find all the numbers disappeared in an array
// Leetcode 448

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        // cyclic sort --> O(n)
        int n = nums.size();
        int i=0;
        while(i<n){
            int correctIdx = nums[i]-1; //oth index
            if(nums[correctIdx]==nums[i]) i++; 
            else swap(nums[i],nums[correctIdx]);
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(nums[i]!=i+1) ans.push_back(nums[i]);
        }
        return ans;
    }
};


// second approach
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>ans;
        unordered_set<int>s;
        for(int val:nums){
            if(s.find(val) !=s.end()) ans.push_back(val);
            s.insert(val);
        }
        return ans;
    }
};