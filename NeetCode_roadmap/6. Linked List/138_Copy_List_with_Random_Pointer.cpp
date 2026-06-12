/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        // Using HashMap...
        unordered_map<Node *, Node *> mp;
        // Creating the copy of each node
        Node *curr = head;
        while (curr != NULL)
        {
            mp[curr] = new Node(curr->val);
            curr = curr->next;
        }

        // Connecting next to random pointers(Deep copy)
        curr = head;
        while (curr != NULL)
        {
            mp[curr]->next = mp[curr->next];
            mp[curr]->random = mp[curr->random];
            curr = curr->next;
        }
        return mp[head];
    }
};