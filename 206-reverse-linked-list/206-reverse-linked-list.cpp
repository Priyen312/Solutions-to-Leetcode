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
    ListNode* reverseList(ListNode* head) {
        ListNode *node = head;
        ListNode *prev = nullptr;
        ListNode *a = nullptr;
        
        while(node != nullptr)
        {
               a = node->next;
 
            // Reverse current node's pointer
            node->next = prev;
 
            // Move pointers one position ahead.
            prev = node;
            node = a;
        }
        
        return prev;
    }
};