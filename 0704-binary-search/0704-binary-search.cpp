class Solution {
public:
    int bs(vector<int>&arr, int tar,int st, int end){
        if(st<=end){
            int mid = st + (end-st)/2;
            if(arr[mid]==tar) return mid;
            if(arr[mid]<tar) return bs(arr,tar,mid+1,end);
            else return bs(arr,tar,st,mid-1);
        }
        else{
            return -1;
        }
    }
    int search(vector<int>& nums, int target) {
        return bs(nums,target,0,nums.size()-1);
    }
};