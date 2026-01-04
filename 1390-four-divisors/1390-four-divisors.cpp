class Solution {
public:
    int divisors(int n){
        int count = 2;
        int sum = 1+n;
        for(int i=n/2;i>1;i--){
            if(count>4) break;
            if(n%i==0){
                count++;
                sum += i;
            }
        }
        return (count==4) ? sum : 0;
    }

    int sumFourDivisors(vector<int>& nums) {
        int total = 0;
        for(auto x:nums){
            total += divisors(x);
        }
        return total;
    }
};