class Solution {
public:
    int minimumDistance(vector<int>& Arr) {
        unordered_map<int,vector<int>> mp;

        for (int i=0; i<Arr.size();i++) {
            mp[Arr[i]].push_back(i);
        }
        
        int ans = INT_MAX;

        for (auto &it : mp) {
            vector<int> &v = it.second;
            if(v.size()<3) continue;
            
            for(int i=0; i+2<v.size(); i++) { // sliding window
                int dist = 2*(v[i+2]-v[i]);
                ans = min(ans, dist);
            }
        }
        return (ans == INT_MAX) ? -1 : ans;
    }
};