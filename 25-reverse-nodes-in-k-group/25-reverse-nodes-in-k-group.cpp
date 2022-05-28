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
    ListNode* reverseKGroup(ListNode* root, int k) {
        
        ListNode* curr = root;
        int total_nodes = 0;
        
        while(curr and total_nodes < k)
        {
            curr = curr->next;
            total_nodes++;
        }
        
        if(total_nodes < k)// return the list as it is from the start if current is a null(meaning nodes < k)
        {
            return root;
        }
        
        ListNode* ahead = nullptr;
        ListNode* behind = nullptr;
        
        curr = root;
        total_nodes = 0;
        while(total_nodes < k)
        {
            ahead = curr->next;
            curr->next = behind;
            behind = curr;
            curr = ahead;
            total_nodes++;
        }
        
        root->next = reverseKGroup(ahead, k);
        
        return behind;
        
    }
};