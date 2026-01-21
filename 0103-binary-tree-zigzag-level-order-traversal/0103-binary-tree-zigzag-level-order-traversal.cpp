class Solution {
public:
    vector<vector<int>> ans;

    void order(TreeNode* root, int level) {
        if(root == NULL) return;

        if(ans.size() == level) {
            ans.push_back(vector<int>());
        }

        ans[level].push_back(root->val);

        order(root->left, level + 1);
        order(root->right, level + 1);
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        ans.clear();
        order(root, 0);

        // reverse odd level
        for(int i=1; i<ans.size(); i+=2) {
            reverse(ans[i].begin(),ans[i].end());
        }

        return ans;
    }
};
