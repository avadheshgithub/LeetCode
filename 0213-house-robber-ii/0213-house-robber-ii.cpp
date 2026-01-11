class Solution {
public:
    int rob(vector<int>& nums) {
        int rob1=0; int rob2=0;
        int maxi1=nums[0]; int maxi2 = 0;

        for(int i=0;i<nums.size()-1;i++){   // 0 to n-1
            maxi1 = max(rob1+nums[i],rob2);
            rob1 = rob2;
            rob2 =maxi1;
        }

        rob1=0; rob2=0;

        for(int i=1;i<nums.size();i++){     // 1 to n
            maxi2 = max(rob1+nums[i],rob2);
            rob1 = rob2;
            rob2 =maxi2;
        }

        return max(maxi1,maxi2);
    }
};