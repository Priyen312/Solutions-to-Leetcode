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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0,v2 = 0,v1 = 0;
        ListNode* node = new ListNode();
        ListNode* curr = node;
        
        
            while(l1 || l2 || carry)
        {
            
                if(l1)
                {v1 = l1->val;
                 l1 = l1->next;}
                    else v1 = 0;
                    if(l2)
                    {v2=l2->val;
                     l2 = l2->next;}
                else v2 = 0;
            
            int v = v1 + v2 + carry;
            
            carry = v/10;
v = v%10;
            
                curr->next = new ListNode(v);
                
                curr = curr->next;
            
                
            
        }
        
        return node->next;
    }
};