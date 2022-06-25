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

    ListNode* merge2Lists(ListNode* list1, ListNode* list2) {
        ListNode *node = new ListNode();
        ListNode* merge = node;
        
        while(list1 && list2)
        {
            if(list1->val<list2->val)
            {
                merge->next = list1;        
                list1 = list1->next;
            }
            else 
            {
                merge->next = list2;
                list2 = list2->next;
            }
            
            merge = merge->next;
        }
        
        merge->next = (list1!=nullptr) ? list1: list2;
        
        return node->next;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {//O(nlogk), O(1)
        int num = lists.size();
        int interval = 1;
        
        while(interval < num)
        {
            for(int i = 0; i < num - interval; i += interval * 2)
            {
                lists[i] = merge2Lists(lists[i], lists[i + interval]);
                
            }
            
            interval *=2;
        }
        
        if(num > 0)
            return lists[0];
        else
            return nullptr;
    }
//     ListNode* mergeKLists(vector<ListNode*>& lists)
//     {
//         if(lists.empty())
//         {
//         return nullptr;
//         }
        
//         while(lists.size() > 1)
//         {
//             lists.push_back(merge2Lists(lists[0], lists[1]));
//             lists.erase(lists.begin());
//             lists.erase(lists.begin());
//         }
//         return lists.front();
//     }

//     ListNode* mergeKLists(vector<ListNode*>& lists) {
//         //Convert merge k lists problem to merge 2 lists (k-1) times.
//         //O(kn), O(1)
//         int i =0;
//         if(lists.size()==0 ){
//             return nullptr;
//         }
            
//         while(lists.size()>1)
//         {
            
//             vector<ListNode*> v;
//             for(int i = 0; i <= lists.size() - 1; i += 2)
//             {
//                 ListNode *a = lists[i];
//                 ListNode *b = i+1<=lists.size()-1 ? lists[i+1]:nullptr;
//                 v.push_back(mergeList(a,b));
//             }
         
//          lists = v;
            
            
          
//         }
        
//         return lists[0];
//     }
    
   
    

    
    
};