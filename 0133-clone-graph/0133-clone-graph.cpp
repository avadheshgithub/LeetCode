/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*>mp;

    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;

        if(mp.count(node)) return mp[node]; // in map --> return node

        Node* copy = new Node(node->val); // not in map --> create node & insert into mp
        mp.insert({node,copy}); 

        for(Node* nei: node->neighbors){ // for all neighbors
            copy->neighbors.push_back(cloneGraph(nei)); 
        }

        return copy;
    }
};