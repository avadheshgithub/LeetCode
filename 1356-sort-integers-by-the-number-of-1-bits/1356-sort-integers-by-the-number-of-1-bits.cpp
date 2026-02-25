class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        auto cntBits = [](int x) {
            int count = 0;
            while(x) {
                count += (x & 1);
                x >>= 1;
            }
            return count;
        };

        sort(arr.begin(), arr.end(), [&](int a, int b) {
            int bitA = cntBits(a);
            int bitB = cntBits(b);

            if(bitA == bitB) return a < b;
            return bitA < bitB;
        });
        return arr;
    }
};