// Find the Duplicate Number

// Leetcode 287


// time complexity: O(n)
// space complexity: O(1)   

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // cylcic sort - O(n)
        int n = nums.size();
        int i=0;
        while(i<n){
            int correctIdx = nums[i];
            if(nums[correctIdx]==nums[i]) return nums[i];
            else swap(nums[i],nums[correctIdx]);
        }
        return -1;
    }
};


// seconf approach using sum formula

// time complexity: O(n)
// space complexity: O(1)
class Solution2 {
public:
    int findDuplicate(vector<int>& nums) {
        // Sum formula O(n)
        int n = nums.size();
        int sum = n * (n - 1) / 2;
        for(int i=0;i<n;i++){
            sum -= nums[i];
        }
        return -sum;
    }
};



// third approach - using XOR

// time complexity: O(n)
// space complexity: O(1)
class Solution3 {
public:
    int findDuplicate(vector<int>& nums) {
        // XOR O(n)
        int n = nums.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            ans ^= nums[i];
            ans ^= i; // XOR with index
        }
        return ans;
    }
};