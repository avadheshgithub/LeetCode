class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        sort(arr.begin(),arr.end()); 

        vector<vector<int>>ans;
        for(auto e:arr){
            if(ans.empty() || ans.back()[1]<e[0]) ans.push_back(e);
            else ans.back()[1] = max(ans.back()[1],e[1]);
        }
        return ans;
    }
};