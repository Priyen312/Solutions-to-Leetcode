/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* detectCycle(ListNode *list) {
    unordered_map<ListNode*, int> visitedNodes;
	ListNode* currentNode = list;
	while(currentNode != NULL) {
		if (visitedNodes[currentNode] == 0) {
			visitedNodes[currentNode] = 1;
		} else {
            cout<<currentNode->val;
			return currentNode;
		}
		currentNode = currentNode->next;
	}
	return nullptr;
        
    }
    int len(ListNode *head)
    {
        int length = 0;
        ListNode *s = head,*f = head;
        if(head==nullptr || head->next == nullptr)
            return 0;
        while(f!=nullptr && f->next!=nullptr)
        {
            s = s->next;f = f->next->next;
            
            if(s==f)
            {
                ListNode *temp = s;
                 
                 do{
                     temp = temp->next;
                     length++;
                     
                     
                 }while(temp!=s);
            
                return length;
      
            }
        }
        return 0;
    }
    
//     ListNode *detectCycle(ListNode *head) {
//         if(!len(head))
//         {
//             return nullptr;
//         }
        
//         int l = len(head);
//         ListNode *move = head;
//         while(l>0)
//         {
//             move = move->next;
//             l--;
//         }
        
//         ListNode *first = head;
     
        
//         while(first!=move)
//         {
//             first=first->next;
//             move=move->next;
//         }
        
//         return first;
//     }
   
};