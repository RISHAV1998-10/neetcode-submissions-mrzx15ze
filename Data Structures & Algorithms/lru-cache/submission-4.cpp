class LRUCache {
private:
    struct NodeDLL{
        int val;
        int key;
        NodeDLL* prev;
        NodeDLL* next;

        NodeDLL(int k, int v): val(v), key(k), prev(NULL), next(NULL) {};
    };

    int cap;
    NodeDLL* head = new NodeDLL(0,0);
    NodeDLL* tail = new NodeDLL(0,0);
    unordered_map<int, NodeDLL*> hash;

    void deleteNode(NodeDLL* node){
        NodeDLL* prevNode = node->prev;
        NodeDLL* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    void insertAfterHead(NodeDLL* node){
        auto temp = head->next;
        head->next = node;
        node->prev = head;

        node->next = temp;
        temp->prev = node;
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        hash.clear();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(hash.find(key) == hash.end())
            return -1;

        NodeDLL* node = hash[key];
        deleteNode(node);
        insertAfterHead(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(hash.find(key) != hash.end()){
            NodeDLL* node = hash[key];
            node->val = value;
            deleteNode(node);
            insertAfterHead(node);
        }
        else{
            if(hash.size() == cap){
                NodeDLL* lru = tail->prev;
                deleteNode(lru);
                hash.erase(lru->key);
                delete lru;
            }
            NodeDLL* node = new NodeDLL(key, value);
            insertAfterHead(node);
            hash[key] = node;
        }
    }
};
