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
    int returnLeft_ = 0;
public:
    ListNode* removeHelper(ListNode* current) {
        if(!current) return current;
        ListNode* nextNode = removeHelper(current -> next);
        returnLeft_ --;
        if(returnLeft_ == 0) {
            return current;
        }
        if(returnLeft_ == -1) {
            current -> next = nextNode -> next;
            delete nextNode;
        }
        return current;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        returnLeft_ = n;
        ListNode* nextNode = removeHelper(head);
        if(returnLeft_ == 0) {
            ListNode* tmp = nextNode->next;
            delete nextNode;
            return tmp;
        }
        return nextNode;
    }
};
