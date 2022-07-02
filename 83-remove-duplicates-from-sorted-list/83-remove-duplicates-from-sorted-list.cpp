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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *curr = head, *p = curr;
        
        if(curr == nullptr or curr->next == nullptr)
            return curr;
        
        while(curr and curr->next != nullptr) {
            while(curr->next != nullptr and curr->val == curr->next->val) {
                curr = curr->next;
            }
            
            curr = curr->next;
            p->next = curr;
            p = p->next;
        }
        
        return head;
    }
};