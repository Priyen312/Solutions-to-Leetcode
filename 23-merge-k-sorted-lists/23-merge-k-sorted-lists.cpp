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
       ListNode* mergeList(ListNode* list1, ListNode* list2) {
        ListNode *node = new ListNode();
        ListNode* merge = node;
        
        while(list1 && list2)
        {
            if(list1->val<list2->val)
            {merge->next = list1;list1 = list1->next;
            }
            else 
            {merge->next = list2;list2 = list2->next;
          }
            
            merge = merge->next;
        }
        
        merge->next = (list1!=nullptr) ? list1: list2;
        return node->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int i =0;
        if(lists.size()==0 ){
            return nullptr;
        }
            
        while(lists.size()>1)
        {vector<ListNode*> v;
            for(int i =0;i<=lists.size()-1;i+=2)
            {
                ListNode *n = lists[i];
                ListNode *l = i+1<=lists.size()-1 ? lists[i+1]:nullptr;
                v.push_back(mergeList(n,l));
            }
         
         lists = v;
            
            
          
        }
        
        return lists[0];
    }
    
    
};