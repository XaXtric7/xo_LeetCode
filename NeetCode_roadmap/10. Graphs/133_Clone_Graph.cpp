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

class Solution
{
private:
    Node *dfs(Node *node, unordered_map<Node *, Node *> &mp)
    {
        if (node == nullptr)
        {
            return nullptr;
        }

        // already cloned...
        if (mp.count(node))
        {
            return mp[node];
        }

        Node *clone = new Node(node->val);
        mp[node] = clone;

        // clone neighbors...
        for (Node *neighbor : node->neighbors)
        {
            clone->neighbors.push_back(dfs(neighbor, mp));
        }
        return clone;
    }

public:
    Node *cloneGraph(Node *node)
    {
        unordered_map<Node *, Node *> mp;
        return dfs(node, mp);
    }
};