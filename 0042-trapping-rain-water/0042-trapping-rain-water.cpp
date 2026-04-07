class Solution {
public:
    int trap(vector<int>& height) {  
        int n = height.size();
        int ans = 0;

        int l=0, r=n-1;
        int Lmax=0, Rmax=0;

        while(l<r){
            Lmax = max(Lmax,height[l]);
            Rmax = max(Rmax,height[r]);

            if(Lmax<Rmax){
                ans += Lmax - height[l];
                l++;
            }
            else{
                ans += Rmax - height[r];
                r--;
            }
        }
        return ans;
    }
};