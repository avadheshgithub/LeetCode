// Koko Eating Bananas
// Leetcode - 875

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long low = 1, high = *max_element(piles.begin(),piles.end());
        long long ans = -1; 
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long hours = 0;
            for (int p : piles) {
                hours += (p + mid - 1) / mid; // Equivalent to ceil(p / mid)    
            }
            if (hours <= h) {
                ans = mid; // Valid speed, try to find a smaller one
                high = mid - 1;
            } else {
                low = mid + 1; // Not enough time, increase speed
            }
        }
        return ans;
    }   
};

// Methode 02 - 

class Solution {
public:
    bool check(vector<int>& piles,int h,int mid){
        long long hour = 0;
        for(int pile:piles){
            hour += (pile+mid-1)/mid;
        }
        if(hour<=h) return true;
        else return false;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        long long low = 1;
        long long high = *max_element(piles.begin(),piles.end());
        long long ans = -1;
        while(low<=high){
            long long mid = low+((high-low)/2);
            if(check(piles,h,mid)){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
};