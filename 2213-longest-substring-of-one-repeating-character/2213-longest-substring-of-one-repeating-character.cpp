struct Node {
    int max_len;
    int prefix_len;
    int suffix_len;
    char left_char;
    char right_char;
};

class SegmentTree {
private:
    int n;
    vector<Node> tree;

    Node merge(const Node& left, const Node& right, int left_size, int right_size) {
        Node parent;
        parent.left_char = left.left_char;
        parent.right_char = right.right_char;

        // Calculate Prefix Length
        parent.prefix_len = left.prefix_len;
        if (left.prefix_len == left_size && left.right_char == right.left_char) {
            parent.prefix_len += right.prefix_len;
        }

        // Calculate Suffix Length
        parent.suffix_len = right.suffix_len;
        if (right.suffix_len == right_size && right.left_char == left.right_char) {
            parent.suffix_len += left.suffix_len;
        }

        // Calculate Max Length
        parent.max_len = max(left.max_len, right.max_len);
        if (left.right_char == right.left_char) {
            parent.max_len = max(parent.max_len, left.suffix_len + right.prefix_len);
        }

        return parent;
    }

    void build(int node, int start, int end, const string& s) {
        if (start == end) {
            tree[node] = {1, 1, 1, s[start], s[start]};
            return;
        }
        int mid = start + (end - start) / 2;
        build(2 * node, start, mid, s);
        build(2 * node + 1, mid + 1, end, s);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1], mid - start + 1, end - mid);
    }

    void update(int node, int start, int end, int idx, char ch) {
        if (start == end) {
            tree[node] = {1, 1, 1, ch, ch};
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, ch);
        } else {
            update(2 * node + 1, mid + 1, end, idx, ch);
        }
        tree[node] = merge(tree[2 * node], tree[2 * node + 1], mid - start + 1, end - mid);
    }

public:
    SegmentTree(const string& s) {
        n = s.length();
        tree.resize(4 * n);
        build(1, 0, n - 1, s);
    }

    void update(int idx, char ch) {
        update(1, 0, n - 1, idx, ch);
    }

    int getMaxLen() const {
        return tree[1].max_len;
    }
};

class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        SegmentTree st(s);
        int k = queryIndices.size();
        vector<int> ans(k);

        for (int i = 0; i < k; ++i) {
            st.update(queryIndices[i], queryCharacters[i]);
            ans[i] = st.getMaxLen();
        }

        return ans;
    }
};