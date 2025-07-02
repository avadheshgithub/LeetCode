class Solution {
public:
    void nextPermutation(vector<int>& nums) {

       int n = nums.size();

       // Step 01 - Find the Pivot Index
       int idx = -1;
       for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                idx = i;
                break;
            }
       } 

       // Step 02 - if pivot index not found
       if(idx==-1){
            reverse(nums.begin(),nums.end());
            return;
       }

       // Step 03 - find the index of that values who is greate than nums[idx]
       int nextGreaterIdx = idx+1;
        for(int i=n-1;i>=0;i--){
            if(nums[idx] < nums[i]){
                nextGreaterIdx = i;
                break;
            }
        }

        // Step 04 - swap both values
        swap(nums[idx],nums[nextGreaterIdx]);

        // Step 05 - reverse from idx+1 to end 
        reverse(nums.begin()+idx+1,nums.end());
    }
};