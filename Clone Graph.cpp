class Solution {
public:
    unordered_map<Node*,Node*>m;
    Node* cloneGraph(Node* node) {
        if(!node)
            return nullptr;
        if(m.count(node))
            return m[node];
        m[node]=new Node(node->val);
        for(auto &e:node->neighbors){
            m[node]->neighbors.push_back(cloneGraph(e));
        }
        return m[node];
    }
};
