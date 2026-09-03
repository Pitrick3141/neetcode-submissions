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
    ListNode* front_ = nullptr;
    bool visited_ = false;
public:
    void reorderHelper(ListNode* current) {
        if(!current) return;
        reorderHelper(current->next);
        if(visited_) return;
        if(front_->next == current) {
            current->next = nullptr;
            visited_ = true;
            return;
        }
        else if(front_ == current) {
            front_->next = nullptr;
            visited_ = true;
            return;
        }
        ListNode* nextNode = front_->next;
        front_->next = current;
        current->next = nextNode;
        front_ = nextNode;
    }
    void reorderList(ListNode* head) {
        front_ = head;
        reorderHelper(head);
    }
};
