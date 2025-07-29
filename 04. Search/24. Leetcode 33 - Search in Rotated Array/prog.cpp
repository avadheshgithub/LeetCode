// Search in Rotated Sorted Array
// LeetCode problem number: 33

// Methode 01
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1;
    
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) return mid;
            
            // Step 01 - Check if left half [low, mid] is sorted
            if (nums[low] <= nums[mid]) {
                // Check if target lies in the sorted left half
                if (nums[low] <= target && target < nums[mid]) high = mid - 1; 
                else low = mid + 1; 
            }
            // Step 02 - Right half [mid, high] is sorted
            else {
                // Check if target lies in the sorted right half
                if (nums[mid] < target && target <= nums[high]) low = mid + 1;
                else high = mid - 1; 
            }
        }
        return -1; 
    }
};



// Methode 02
class Solution {
public: 
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==target) return i;
        }
        return -1;
    }
};