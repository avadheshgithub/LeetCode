class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        // n+1 unique mean --> ele if repeated even 2 times --> ans

        unordered_set<int>st;
        for(auto x:nums){
            if(st.find(x)!=st.end()) return x;
            st.insert(x); 
        }
        return -1;
    }
};