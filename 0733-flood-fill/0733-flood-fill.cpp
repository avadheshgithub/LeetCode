class Solution {
public:
    void dfs(int i, int j,vector<vector<int>>& image,int orgColor,int newColor){
        if(i<0 || j<0 || i>=image.size() || j>=image[0].size() || image[i][j]==newColor || image[i][j]!=orgColor) return ;

        image[i][j] = newColor;

        dfs(i-1,j,image,orgColor,newColor); // top
        dfs(i,j+1,image,orgColor,newColor); // right
        dfs(i+1,j,image,orgColor,newColor); // bottom
        dfs(i,j-1,image,orgColor,newColor); // left
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int i, int j, int color) {
        dfs(i,j,image,image[i][j],color);
        return image;
    }
};