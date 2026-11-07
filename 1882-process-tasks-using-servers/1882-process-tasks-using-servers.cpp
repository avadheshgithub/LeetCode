
class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        using ll = long long;

        // {weight, index}
        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>> available;

        // {free_time, weight, index}
        using T = tuple<ll, int, int>;

        priority_queue<T, vector<T>, greater<T>> busy;

        int n = servers.size();
        int m = tasks.size();

        for (int i = 0; i < n; i++) {
            available.push({servers[i], i});
        }

        vector<int> ans;
        ll time = 0;

        for (int i = 0; i < m; i++) {
            time = max(time, (ll)i);

            // Move all free servers to available heap
            while (!busy.empty() && get<0>(busy.top()) <= time) {
                auto [freeTime, weight, index] = busy.top();
                busy.pop();

                available.push({weight, index});
            }

            // If no server is available, wait
            if (available.empty()) {
                time = get<0>(busy.top());

                while (!busy.empty() && get<0>(busy.top()) <= time) {
                    auto [freeTime, weight, index] = busy.top();
                    busy.pop();

                    available.push({weight, index});
                }
            }

            // Select the best available server
            auto [weight, index] = available.top();
            available.pop();

            ans.push_back(index);

            // Assign task
            busy.push({time + tasks[i], weight, index});
        }

        return ans;
    }
};
