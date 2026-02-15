class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;

        queue<pair<pair<int,int>,int>>q; //((i,j),time)

        // 2. push all source node in queue
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0}); //({i,j},time)
                }
            }
        }

        //bfs
        while(!q.empty()){
            int i = q.front().first.first;
            int j = q.front().first.second;
            int time = q.front().second;
            q.pop();

            ans = max(ans,time);

            if(i-1>=0 && grid[i-1][j]==1){ // top --> i-1,j
                q.push({{i-1,j},time+1});
                grid[i-1][j]=2;
            }

            if(j+1<n && grid[i][j+1]==1){// right --> i,j+1
                q.push({{i,j+1},time+1});
                grid[i][j+1]=2;
            }

            if(i+1<m && grid[i+1][j]==1){// bottom --> i+1,j
                q.push({{i+1,j},time+1});
                grid[i+1][j]=2;
            }

            if(j-1>=0 && grid[i][j-1]==1){// left --> i,j-1
                q.push({{i,j-1},time+1});
                grid[i][j-1]=2;
            }

        }

        // check for fresh oranges -> still fresh 
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return ans;

    }
};