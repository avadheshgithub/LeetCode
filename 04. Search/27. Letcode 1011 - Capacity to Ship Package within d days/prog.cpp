// Capacity to Ship Package within d days
// Letcode 1011

// Method: Binary Search
// Time Complexity: O(n log m), where n is the number of packages and m is the maximum weight of a package.
// Space Complexity: O(1)   

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);
            while (left < right) {
                int mid = left + (right - left) / 2;    
                int total = 0, count = 1;
                for (int weight : weights) {
                    total += weight;    
                    if (total > mid) {
                        total = weight;
                        count++;
                    }
                }   
                if (count > days) {
                    left = mid + 1;  // Increase the capacity
                } else {
                    right = mid;  // Decrease the capacity
                }
            }
            return left;  // The minimum capacity required to ship within d days
    }   
};
// Example usage:
// int main() {
//     Solution solution;   

// Methode 02 - 
class Solution {
public:
    bool check(int mid, vector<int>&weights,int days){
        int count = 1; // Num of Day Needed
        int currentWight=0; // current Ship Wieght
        for(int weight : weights){
            if(weight + currentWight >mid){
                count++; // New Day
                currentWight = weight;
            }
            else currentWight +=weight;
        }
        return count<=days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end());// Max Ele
        int high = accumulate(weights.begin(),weights.end(),0); // Sum of Ele
        int minCapacity = high; // max possible capacity
        while(low<=high){
            int mid = low+((high-low)/2);
            if(check(mid,weights,days)){
                minCapacity = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return minCapacity;
    }
};




// Methode 03 - 
class Solution {
public:
    bool check(int mid, vector<int>&weights,int days){
        int m = mid;
        int count = 1;
        for(int  i=0;i<weights.size();i++){
            if(m>=weights[i]){
                m -=weights[i];
            }
            else{
                count++;
                m = mid;
                m -=weights[i];
            }
        }
        if(count>days) return false;
        else return true;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end());// Max Ele
        int high = accumulate(weights.begin(),weights.end(),0); // Sum of Ele
        int minCapacity = high; // max possible capacity
        while(low<=high){
            int mid = low+((high-low)/2);
            if(check(mid,weights,days)){
                minCapacity = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return minCapacity;
    }
};