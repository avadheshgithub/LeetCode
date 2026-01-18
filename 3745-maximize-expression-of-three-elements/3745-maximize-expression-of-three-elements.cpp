class Solution {
public:
    int maximizeExpressionOfThree(vector<int>& nums) {
        int maxi = INT_MIN;
        int smax = INT_MIN;
        int mini = INT_MAX;

        for(int i=0;i<nums.size();i++){
            mini = min(mini,nums[i]);
            if(nums[i]>maxi){
                smax = maxi;
                maxi = nums[i];
            }
            else if(smax<nums[i]){
                smax = nums[i];
            }
            
        }
        cout<<maxi<<" "<<smax<< " "<<mini<<endl;
        return (maxi+smax)-mini;
    }
};