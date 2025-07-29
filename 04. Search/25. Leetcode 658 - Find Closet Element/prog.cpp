// Find Closest Element
// Leetcode Problem 658: Find Closest Element

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int low = 0;
        int high = arr.size() - 1;
        
        // Step 01 - Shrink the window until we have k elements
        while (high - low + 1 > k) {
            if (abs(arr[low] - x) > abs(arr[high] - x)) low++;// Compare absolute diff from x
            else high--; 
        
        }

        vector<int> result;
        for (int i = low; i <= high; ++i) {
            result.push_back(arr[i]);
        }
        
        return result;
    }
};


// Methode 02 -
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {

        //Methode : Sliding Window of size k
        int left = 0;
        int right = arr.size() - 1;
        
        while (right - left + 1 > k) {
            if (abs(arr[left] - x) > abs(arr[right] - x)) left++;
            else right--; 
        
        }

        vector<int> result;
        for (int i = left; i <= right; ++i) {
            result.push_back(arr[i]);
        }
        
        return result;
    }
};