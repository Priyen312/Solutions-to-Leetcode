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
    
    ListNode* swapPairs(ListNode* head) {
        
        if(head == nullptr or head->next == nullptr)
            return head;
        
        ListNode* ahead = nullptr;
        ListNode* behind = nullptr;
        
        ListNode* curr = head;
        int n = 2;
        while(n--){
            ahead = curr->next;
            curr->next = behind;
            behind = curr;
            curr = ahead;
            
        }
       
        
        head->next = swapPairs(ahead);
        
        return behind;
        
    }
    
//     ListNode* swapPairs(ListNode* head) {
        
//         if(head == nullptr or head->next == nullptr) 
//             return head;
        
//         ListNode* tmp = head->next;// 2
        
//         head->next = swapPairs(head->next->next);// 2 -> 1 -> 4 -> 3 -> nullptr
        
//         tmp->next = head;
        
//         return tmp;
        
        
//     }
};