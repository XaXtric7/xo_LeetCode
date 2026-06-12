/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    void reorderList(ListNode *head)
    {
        vector<int> original;
        ListNode *curr = head;
        while (curr != NULL)
        {
            original.push_back(curr->val);
            curr = curr->next;
        }
        vector<int> reOrdered;
        int left = 0;
        int right = original.size() - 1;

        while (left < right)
        {
            reOrdered.push_back(original[left]);
            reOrdered.push_back(original[right]);
            left++;
            right--;
        }
        if (left == right)
        {
            reOrdered.push_back(original[left]);
        }
        curr = head;
        for (int val : reOrdered)
        {
            curr->val = val;
            curr = curr->next;
        }
    }
};