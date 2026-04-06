class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        int x = 0, y = 0, di = 0;

        set<pair<int, int>> obstacleSet;
        for (auto& obs : obstacles) {
            obstacleSet.insert({obs[0], obs[1]});
        }

        int maxDistSq = 0;
        for (int cmd : commands) {
            if (cmd == -2) {
                di = (di + 3) % 4;
            } else if (cmd == -1) { 
                di = (di + 1) % 4;
            } else { 
                for (int i = 0; i < cmd; ++i) {
                    int nx = x + dx[di];
                    int ny = y + dy[di];
                    if (obstacleSet.find({nx, ny}) == obstacleSet.end()) {
                        x = nx;
                        y = ny;
                        maxDistSq = max(maxDistSq, x * x + y * y);
                    } else {
                        break; 
                    }
                }
            }
        }
        return maxDistSq;
    }
};
