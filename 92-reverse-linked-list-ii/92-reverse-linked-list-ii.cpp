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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        ListNode *current_node = head;
        ListNode* prev = nullptr;
        ListNode* ne = head;
        while(left>1)
        {
            prev = current_node;           //prev = 1
            current_node = current_node->next;//curr_node = 2
            left--;
            right--;
        }
        
        ListNode* connect = prev;
        ListNode* tail = current_node;
        while(right>0)
        {
            ne =  current_node->next;      //1       <-2<-3<-4          5
            current_node->next = prev;
            prev = current_node;
            current_node = ne;
            right--;
        }
        
        if(connect!=nullptr)
        connect->next = prev;
        else
            head  = prev;
        
        tail->next = current_node;
        
        return head;
        
        
        
    }
};