class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL) return {};
        
        vector<vector<int>>ans;

        queue<TreeNode *>q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            vector<int>temp(size);

            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();

                temp[i] = node->val;

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};