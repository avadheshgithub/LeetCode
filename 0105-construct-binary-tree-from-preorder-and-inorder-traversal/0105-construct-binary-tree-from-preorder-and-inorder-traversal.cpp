class Solution {
public:
    int preIdx=0;
    unordered_map<int, int> mp;

    TreeNode* build(vector<int>& pre,int st,int end) {
        if (st > end) return NULL;

        int rootVal = pre[preIdx++];
        TreeNode* root = new TreeNode(rootVal);
        int mid = mp[rootVal];

        root->left = build(pre, st, mid-1);
        root->right = build(pre, mid+1, end);

        return root;
    } 

    TreeNode* buildTree(vector<int>& pre, vector<int>& In) {
    
        for(int i=0; i<In.size(); i++) {
            mp[In[i]] = i;
        }
        
        return build(pre,0,In.size()-1);
    }   
};