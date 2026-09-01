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

class Solution {
public:
    map<ListNode*, bool> visited;
    bool hasCycle(ListNode* head) {
        if(!head || !head->next) return false;
        if(visited[head]) return true;
        visited[head] = true;
        return hasCycle(head->next);
    }
};
