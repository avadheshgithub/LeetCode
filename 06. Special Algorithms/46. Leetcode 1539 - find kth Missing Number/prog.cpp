/*
        ## FInd the kth positive missing value     [Leetcode 1539]
*/

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int low = 0;
        int high = n-1;
        while(low<=high){
            int mid = (low+high)/2;
            int missing =arr[mid]-mid-1;
            if(missing<k) low = mid+1;
            else high = mid-1;
        }
        return low+k;
    }
};

// method 2: iteration

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        unordered_set<int> st(arr.begin(), arr.end()); 
        int count = 0; 
        for (int i = 1; ; i++) { 
            if (st.find(i) == st.end()) { 
                count++;
                if (count == k) { 
                    return i;
                }
            }
        }
        return -1; 
    }
};


class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            int missing = arr[i] - (i + 1); // Number of missing integers up to arr[i]
            if (missing >= k) {
                return k + i; // kth missing number is k + i
            }
        }
        // If kth missing number is beyond arr[n-1]
        return k + n;
    }
};