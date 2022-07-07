struct Node {
public:
    int key, val;
    Node* next;
    Node(int k, int v, Node* n) {
        key = k;
        val = v;
        next = n;
    }
};
class MyHashMap {
public:
    MyHashMap() {
        
    }
    
    const static int size = 19997;
    const static int mult = 12582917;
    Node* data[size] = {};
    int hash(int key) {
        return (int)((long)key * mult % size);
    }
    
    void put(int key, int value) {
        remove(key);
        int h = hash(key);
        Node* node = new Node(key, value, data[h]);//the new node who next is the head of the bucket
        data[h] = node;// now I am the new head
    }
    
    int get(int key) {
        int h = hash(key);
        Node* node = data[h];
        while(node)
        {
            if (node->key == key) 
                return node->val;
            
            node = node->next;
        }
        return -1;
    }
    
    void remove(int key) {
        int h = hash(key);
        Node* node = data[h];
        if (node == NULL) return;
        if (node->key == key) {// if the head itself is the key
            data[h] = node->next;
            delete node;
        } 
        else 
        {
            while (node->next)
            {
                if (node->next->key == key) {
                    Node* temp = node->next;// so that we can delete it
                    node->next = node->next->next;
                    delete temp;
                    return;
                    }
                
                node = node->next;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */