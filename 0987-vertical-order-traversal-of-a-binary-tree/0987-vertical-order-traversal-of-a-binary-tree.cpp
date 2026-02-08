class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        map<int,map<int,multiset<int>>> mp;
        queue<pair<TreeNode*, pair<int,int>>> q;// node, {row, col}

        q.push({root, {0, 0}});

        while (!q.empty()) {
            auto it = q.front();
            q.pop();

            TreeNode* node = it.first;
            int row = it.second.first;
            int col = it.second.second;

            mp[col][row].insert(node->val);

            if (node->left)
                q.push({node->left, {row + 1, col - 1}});

            if (node->right)
                q.push({node->right, {row + 1, col + 1}});
        }

        vector<vector<int>> ans;
        for (auto &c : mp) {
            vector<int> val;
            for (auto &r : c.second) {
                val.insert(val.end(),r.second.begin(),r.second.end());
            }
            ans.push_back(val);
        }

        return ans;
    }
};
