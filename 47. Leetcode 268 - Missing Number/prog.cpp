// Missing Number
// Leetcode 268


// time complexity: O(n)
// space complexity: O(1)


class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // Cyclic Sort O(n)
        int n = nums.size();
        int i=0;
        while(i<n){
            int correctIdx = nums[i];
            if(correctIdx==i || nums[i]==n)i++;
            else swap(nums[i],nums[correctIdx]);
        }
        // find missing
        for(int i=0;i<n;i++){
            if(nums[i]!=i) return i;
        }
        return n;
    }
};


// second approach using sum formula
class Solution2 {
public: 
    int missingNumber(vector<int>& nums) {
        // Sum formula O(n)
        int n = nums.size();    
        int sum = n * (n + 1) / 2;
        for(int i=0;i<n;i++){
            sum -= nums[i];
        }
        return sum;
    }
};


// third methode - XOR

