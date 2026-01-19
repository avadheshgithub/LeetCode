class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return {nums[0]};

        sort(begin(nums),end(nums));
        
        vector<int>ans;

        for(int i=0;i<n;i++){
            if(i == 0){
                if(nums[i]!=nums[i+1] && nums[i+1]-nums[i]!=1) ans.push_back(nums[i]);
            }
            else if(i == n-1){
                if(nums[i]!=nums[i-1] && nums[i]-nums[i-1]!=1) ans.push_back(nums[i]);
            }
            else{
                if(nums[i]!=nums[i+1] && nums[i]!=nums[i-1] && nums[i]-nums[i-1]!=1 && nums[i+1]-nums[i]!=1)
                    ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};