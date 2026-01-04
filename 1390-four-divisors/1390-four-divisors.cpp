class Solution {
public:
    int divisors(int n){
        int div = 0;
        int sum = 0;
        for(int i=1;i*i<=n;i++){
            if(n%i==0){
                int Sfact = n/i;
                if(Sfact==i) {
                    div += 1;
                    sum += i;
                } else{
                    div += 2;
                    sum += (i + Sfact);
                }
            }
            if(div>4) return 0;
        }
        return (div==4) ? sum:0;
    }

    int sumFourDivisors(vector<int>& nums) {
        int total = 0;
        for(auto x:nums){
            total += divisors(x);
        }
        return total;
    }
};