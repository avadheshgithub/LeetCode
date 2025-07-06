// Find First and Last Position of Element in Sorted Array
// Leetcode problem number: 34
// Leetcode problem link: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
// Leetcode problem difficulty: Medium
// Leetcode problem tags: Array, Binary Search

class Solution {
public:
    int firstPos(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                if (mid == 0 || nums[mid - 1] != target) return mid;
                else high = mid - 1;
            }
            else if (nums[mid] > target) high = mid - 1;
            else low = mid + 1;
        }
        return -1;
    }

    int lastPos(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                if (mid == n - 1 || nums[mid + 1] != target) return mid;
                else low = mid + 1;
            }
            else if (nums[mid] > target) high = mid - 1;
            else low = mid + 1;
        }
        return -1;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        ans.push_back(firstPos(nums, target));
        ans.push_back(lastPos(nums, target));
        return ans;
    }
};