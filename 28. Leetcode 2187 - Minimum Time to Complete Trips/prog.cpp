// Minimum time to complete trips
// Leetcode problem 2187

// Method 01: Binary Search

class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long low = 1, ans = -1;
        long long high = (long long)*min_element(time.begin(),time.end())*totalTrips;
        while (low <= high) {
            long long mid = low + (high - low) / 2; 
            long long trips = 0;
            for (int t : time) {
                trips += mid / t;
            }
            if (trips >= totalTrips) {
                ans = mid; // valid time, find smaller one
                high = mid - 1;
            } else low = mid + 1; // Not enough trips, increase time
        }
        return ans;
    }
};


// Methode 02 -
class Solution {
public:

    bool check(long long mid,vector<int>& time,int totalTrips){
        long long trips = 0;
        for(int i=0;i<time.size();i++){
            trips +=mid/(long long)time[i]; // Requried Trips calcuclated
        }
        if(trips>=(long long)totalTrips) return true;
        else return false;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long low =1;
        long long high = (long long)*min_element(time.begin(),time.end())*totalTrips;
        long long ans = -1;
        while(low<=high){
            long long mid = low+(high-low)/2;
            if(check(mid,time,totalTrips)==true){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
};