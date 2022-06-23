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
    ListNode* rotateRight(ListNode* head, int k) {
        
        ListNode *node = head;int n=1;
        if(!head || !head->next)
            return head;
        while(node->next)//get to the last node;
        {
            node = node->next;
            n++;
        }
        k = k%n; k = n - k;//to not rotate a list of length 5 a 1000 times 
        node->next = head;//connecting the node last to first
        node = node->next;
        
        ListNode *tail = head;
       
        while(k--)
        {
           tail = node;
            node = node->next;
        }
       
        tail->next = nullptr;
        
    
        if(k == 0)
            return head;
    
        return node;
    }
};