class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        
        auto countBits = [](int x) {
            int count = 0;
            while(x) {
                count += (x & 1);
                x >>= 1;
            }
            return count;
        };

        sort(arr.begin(), arr.end(), [&](int a, int b) {
            int bitsA = countBits(a);
            int bitsB = countBits(b);

            if(bitsA == bitsB)
                return a < b;

            return bitsA < bitsB;
        });

        return arr;
    }
};