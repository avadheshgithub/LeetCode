// Reducing Dishes
// Leetcode 1402

class Solution {
public:
    int maxSatisfaction(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end());

        // Sufix Sum
        vector<int>suf(n+1,0);
        suf[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--){
            suf[i] = suf[i+1]+arr[i];
        }
        // find the pivot index
        int idx=-1;
        for(int i=0;i<n;i++){
            if(suf[i]>=0){
                idx=i;
                break;
            }
        }

        if(idx==-1) return 0;
        // Return max sum of satisfaction
        int maxSum=0;
        int x = 1;
        for(int i=idx;i<n;i++){
            maxSum += arr[i]*x;
            x++;
        }

        return maxSum;

    }
};