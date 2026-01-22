class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        if(root == NULL) return 0;

        queue<TreeNode*> q;
        vector<vector<int>> ans;

        q.push(root);

        while(!q.empty()){
            int size = q.size();
            vector<int> temp;

            for(int i = 0; i < size; i++){
                TreeNode* node = q.front();
                q.pop();

                temp.push_back(node->val);

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }

            ans.push_back(temp); 
        }

        int maxSum = INT_MIN;
        int idx = -1;

        for(int i = 0; i < (int)ans.size(); i++){
            int sum = 0;
            for(int j = 0; j < (int)ans[i].size(); j++){
                sum += ans[i][j];
            }

            if(sum > maxSum){
                maxSum = sum;
                idx = i;
            }
        }
        return idx + 1; 
    }
};
