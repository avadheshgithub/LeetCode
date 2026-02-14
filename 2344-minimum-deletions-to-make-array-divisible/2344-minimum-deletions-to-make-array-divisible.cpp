class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        map<int,int>mp;
        for(auto x:nums){
            mp[x]++;
        }

        int count = 0;
        for(auto x:mp){
            bool flag = true;
            for(int i=0;i<numsDivide.size();i++){
                if(numsDivide[i]%x.first!=0){
                    count += x.second;
                    flag = false;
                    break;
                }
            }
            if(count==nums.size()) return -1;
            if(flag) return count;
        }
        return count;
    }
};