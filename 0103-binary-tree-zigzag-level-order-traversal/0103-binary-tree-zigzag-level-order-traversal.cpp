class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL) return {};
        
        vector<vector<int>>ans;
        bool level = true;

        queue<TreeNode *>q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            vector<int>temp(size);

            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();

                int idx = level ? i : size-i-1;
                temp[idx] = node->val;

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            level = !level; // odd/even
            ans.push_back(temp);
        }
        return ans;
    }
};