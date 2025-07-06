// Majority Element
// LeetCode problem number: 169

// Time complexity: O(n log n)
// Space complexity: O(1)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        return (nums[n/2]);
    }
};
 
  // Alternative solution using brute force approach
// Time complexity: O(n^2)
// Space complexity: O(1)


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            int count =1;
            for(int j=i+1;j<n;j++){
                if(nums[i]==nums[j]) count++;
            }
            if(count>n/2) return nums[i];
        }
        return -1;
    }
};