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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int empty = 0;
        ListNode* sorted = nullptr;
        ListNode* current = nullptr;
        while(empty < lists.size()) {
            int minNum = 10010;
            for(int i = 0; i < lists.size(); i++) {
                if(!lists[i]) continue;
                if(lists[i]->val < minNum) {
                    minNum = lists[i]->val;
                }
            }
            if(minNum == 10010) break;
            for(int i = 0; i < lists.size(); i++) {
                if(!lists[i]) continue;
                while(lists[i]->val == minNum) {
                    if(!current) sorted = lists[i];
                    else current -> next = lists[i];
                    current = lists[i];
                    lists[i] = lists[i] -> next;
                    if(!lists[i]) {
                        empty++;
                        break;
                    }
                }
            }
            
        }
        return sorted;
    }
};
