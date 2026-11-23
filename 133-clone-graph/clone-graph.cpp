
class Solution {
public:
    unordered_map<Node*, Node*> mp;

    Node* cloneGraph(Node* node) {
        if (node == nullptr)
            return nullptr;

        // If node is already cloned, return its clone
        if (mp.find(node) != mp.end())
            return mp[node];

        // Create a new node
        Node* clone = new Node(node->val);

        // Store original node and its clone
        mp[node] = clone;

        // Clone all neighbors
        for (Node* neighbor : node->neighbors) {
            clone->neighbors.push_back(cloneGraph(neighbor));
        }

        return clone;
    }
};
