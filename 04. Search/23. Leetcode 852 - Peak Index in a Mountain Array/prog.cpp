// Peak index in a Mountain Array
// Leetcode problem number: 852

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        for(int i=1;i<n;i++){
            if(arr[i]>arr[i-1] && arr[i]>arr[i+1]){
                return i;
            } 
        }
        return -1 ;
    }
};


// Methode 02 - binary search
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int low = 1;
        int high = arr.size()-1; 
        while(low<=high){
            int mid = low+((high-low)/2; 
            if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]) return mid;
            else if(arr[mid]>arr[mid-1]) low = mid+1;
            else high = mid-1;
        }
        return -1;
    }
};