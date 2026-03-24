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