class Solution {
public:
    void bfs(vector<vector<int>>& arr,vector<bool>&vis,int i){
        queue<int>q;
        q.push(i);
        vis[i]=true;

        while(!q.empty()){
            int currCity = q.front();
            q.pop();

            for(int j=0;j<arr.size();j++){
                if(arr[currCity][j]==1 && !vis[j]){
                    vis[j] = true;
                    q.push(j);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& arr) {
        int n = arr.size();
        int province = 0;

        vector<bool>vis(n,false);

        for(int i=0;i<n;i++){
            if(!vis[i]){
                bfs(arr,vis,i);
                province++;
            }
        }
        return province;
    }
};