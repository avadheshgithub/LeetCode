#define pi pair<int,int>

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int x : nums) mp[x]++;
        
        // heap pair is <freq,ele>
        priority_queue<pi,vector<pi>,greater<pi> > pq;
        for(auto x:mp){
            pq.push({x.second,x.first}); // push in heap but pair rev
            if(pq.size()>k)pq.pop();
        }
        
        vector<int>ans;
        while(pq.size()>0){
            int ele = pq.top().second;
            ans.push_back(ele);
            pq.pop();
        }
        return ans;
    }
};