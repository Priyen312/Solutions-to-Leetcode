
class LRUCache {
public:
    struct ListNode
	{
		int key;
		int value;
		ListNode* next;
		ListNode* prev;
	};
	int capacity;
	
	ListNode *head = new ListNode();
	ListNode *tail = new ListNode();
	
	map<int,ListNode*> cache;
	
    LRUCache(int capacity) {
		this->capacity = capacity;
		head->next = tail;
		tail->prev = head;
    }
    void addNode(ListNode *node)
	{
		ListNode *t = head->next;
        node->next = t;
        node->prev = head;
		head->next = node;
        t->prev = node;
        
		
			
	}
	
	void deleteNode(ListNode *node)
	{
		ListNode *tp = node->prev;
        ListNode *tn = node->next;
        tn->prev = tp;
		tp->next = tn;
		
		
	}
	
    int get(int key) {
        
        
        int result = -1;
		if(cache.find(key)!=cache.end())
		{
            ListNode *node = cache[key];
			result = node->value;
			cache.erase(key);
			deleteNode(node);
			addNode(node);
            cache[key]=node;
            return result;
			
			
		}
		return -1;
    }
    
    void put(int key, int value) {
		
		
		if(cache.find(key)!=cache.end())
        {
			
			ListNode *node = cache[key];
			cache.erase(key);
			deleteNode(node);
            node->value = value;
			addNode(node);
            
			cache[key] = head->next;
		}
		else
		{
			if(cache.size() == capacity)
			{
				cache.erase(tail->prev->key);
				deleteNode(tail->prev);	
			}
			
					ListNode *root = new ListNode();
					root->key = key;
					root->value = value;
					addNode(root);
                    cache[key] = head->next;
			
		}
    }
};


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* cache = new LRUCache(capacity);
 * int value = cache->get(key);
 * cache->add(key, value);
 */

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */