class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL) return 0;

        queue<pair<TreeNode*,long long>>q;
        q.push({root, 0});

        long long maxWidth = 0;

        while (!q.empty()) {
            int size = q.size();
            long long stIdx = q.front().second;
            long long endIdx = q.back().second;

            maxWidth = max(maxWidth, endIdx - stIdx + 1);

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front().first;
                long long idx = q.front().second;
                q.pop();

                idx = idx - stIdx; // normalize

                if (node->left) q.push({node->left, 2*idx+1});
                if (node->right) q.push({node->right, 2*idx+2});
            }
        }

        return (int)maxWidth;
    }
};