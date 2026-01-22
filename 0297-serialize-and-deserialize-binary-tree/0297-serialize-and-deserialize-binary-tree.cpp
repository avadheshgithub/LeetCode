class Codec {
public:
    void RecSerialize(TreeNode* root, string &str) {
        if (root == NULL) {
            str += "NULL,";
            return;
        }
        str += to_string(root->val) + ",";
        RecSerialize(root->left, str);
        RecSerialize(root->right, str);
    }

    string serialize(TreeNode* root) {
        string str = "";
        RecSerialize(root, str);
        return str;
    }

    TreeNode* RecDeSerialize(queue<string> &q) {
        if (q.front() == "NULL") {
            q.pop();
            return NULL;
        }

        TreeNode* root = new TreeNode(stoi(q.front()));
        q.pop();

        root->left = RecDeSerialize(q);
        root->right = RecDeSerialize(q);

        return root;
    }

    TreeNode* deserialize(string data) {
        queue<string> q;
        string token = "";

        for (char ch : data) {
            if (ch == ',') {
                q.push(token);
                token = "";
            } else {
                token += ch;
            }
        }

        return RecDeSerialize(q);
    }
        
};
