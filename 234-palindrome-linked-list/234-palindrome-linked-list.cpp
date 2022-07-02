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
    ListNode* middleNode(ListNode* head) {
        ListNode *fast = head;
        ListNode *slow = head;

        
        if(!head and !head->next)
        {
            return head;
        }
     
        while(fast!=nullptr && fast->next!=nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        return slow;
        
    }
    
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
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next)
            return head;
        
        
        ListNode *mid = middleNode(head);
        ListNode* reverse = reverseList(mid);
  
        
        
        ListNode *node1 = head, *node2 = reverse;
        while(node1!=mid && node2!=nullptr)
        {
            if(node1->val == node2->val)
            {
                node1 = node1->next;
                node2 = node2->next;
            }
            else
                return false;
           
        }
        
        return true;
        
        
    }
};