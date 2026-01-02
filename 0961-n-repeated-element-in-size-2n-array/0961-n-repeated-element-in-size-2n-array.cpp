class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        // n+1 unique mean --> ele if repeated even 2 times --> ans

        unordered_map<int,int>mp;
        for(auto x:nums){
            if(mp[x]==1)return x;
            mp[x]++; 
        }
        return -1;
    }
};