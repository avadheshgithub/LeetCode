class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL) return {};

        queue<TreeNode*>q;
        q.push(root);

        bool level = true;
        vector<vector<int>>ans;

        while(!q.empty()){
            int size = q.size();
            vector<int>temp(size);

            for(int i=0;i<size;i++){
                TreeNode *node = q.front();
                q.pop();

                int index = level ? i: size-i-1; // odd/even
                temp[index] = node->val;

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ans.push_back(temp);
            level = !level; // odd/Even
        }
        return ans;
    }
};