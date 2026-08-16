class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        unordered_set<Node*> st = {p};

        while(p->parent) p = p->parent, st.insert(p);

        if(st.count(q)) return q;

        while(q->parent) {
            q = q->parent;
            if(st.count(q)) return q;
        }

        return nullptr;
    }
};

// --- alternate solution ---

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/
