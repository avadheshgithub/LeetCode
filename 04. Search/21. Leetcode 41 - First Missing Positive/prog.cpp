// First Missing Positive
// Leetcode problem number: 41

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end()); // -1 1 3 4
        int res=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==res) res++;
            else if (nums[i]>res) break;
        }
        return res;
    }
};


// 2nd mathode using set

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int>st;
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }
        for(int i=1;i<=st.size()+1;i++){
            if(st.find(i)==st.end()) return i;
        }
        return -1;
    }
};


// 3rd methode using cyclic sort
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();        
        for(int i=0;i<n;i++){   
            while(nums[i]>0 && nums[i]<=n && nums[nums[i]-1]!=nums[i]){
                swap(nums[i], nums[nums[i]-1]); 
            };
        }

        // we check for the first missing positive integer
        for(int i=0;i<n;i++){
            if(nums[i]!=i+1) return i+1; 
        }
        return n+1; // if all numbers are in their correct position, return n+1

    }
};