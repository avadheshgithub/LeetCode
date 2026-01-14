class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char,int>mp;

        for(auto x:s) mp[x]++; // freq

        unordered_set<int>st; //set
        int count = 0;

        for(auto x:mp){
            while(x.second>0 && st.count(x.second)){
                x.second--;
                count++;
            }
            if(x.second>0) st.insert(x.second);
        }
        return count;
    }
};