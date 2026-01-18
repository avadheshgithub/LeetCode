class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& arr) {
        long long finish = 0;
        long long waitTime = 0;

        for (int i = 0; i < arr.size(); i++) {
            finish = max(finish, (long long)arr[i][0]) + arr[i][1];
            waitTime += finish - arr[i][0];
        }

        return (double)waitTime / arr.size();
    }
};
