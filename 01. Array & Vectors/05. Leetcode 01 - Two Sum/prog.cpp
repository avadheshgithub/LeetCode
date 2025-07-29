// Methode 01 - Brute Force Approach

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Brute Force Approach
        int n = nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]+nums[j]==target) return {i,j};
            }
        }
        return {-1,-1};
    }
};


// Methode 02 - Better Optimize (two pinter & 2D vec)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        // better Optimized (Two Pointer & 2D vector)
        vector<pair<int,int>>vec;
        for(int i=0;i<nums.size();i++){
            vec.push_back({nums[i],i});
        }
        sort(vec.begin(),vec.end());
        int st = 0; int end = nums.size()-1;
        while(st<end){
            int sum = vec[st].first + vec[end].first;
            if(sum==target) return {vec[st].second,vec[end].second};
            else if (sum>target) end--;
            else st++;
        }
        return {}; 
    }
};

// Methode 03 - Hash Map (Optimal Approach)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // optimized Approach - hashMap

        int n = nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            int first = nums[i];
            int sec = target-first;
            if(mp.find(sec) != mp.end()) return {mp[sec],i};
            else mp[first]=i; // not found --> store into map
        }
        return {};
    }
};