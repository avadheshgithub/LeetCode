class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& Arr) {
        sort(Arr.begin(),Arr.end());
        vector<vector<int>>ans;

        for(auto it:Arr){
            if(ans.empty() or it[0]>ans.back()[1]){
                ans.push_back(it);
                continue;
            }
            else ans.back()[1] = max(ans.back()[1],it[1]);
        }
        return ans;
    }
};