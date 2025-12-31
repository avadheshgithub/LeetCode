class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int>ans;

        priority_queue<int,vector<int>,greater<int>>pq;

        for(auto x:nums){
            pq.push(x);
        }

        while(!pq.empty()){
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};