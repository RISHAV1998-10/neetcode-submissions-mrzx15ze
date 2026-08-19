class LRUCache {
private:
    struct Node{
        int val;
        int key;
        Node* prev;
        Node* next;

        Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
    };
    int cap;
    Node* head;
    Node* tail;
    unordered_map<int, Node*> hash;

    void insertAfterHead(Node* node){
        Node* temp = head->next;

        head->next = node;
        node->prev = head;

        node->next = temp;
        temp->prev = node;
    }

    void deleteNode(Node* node){
        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        hash.clear();
        
        head = new Node(0,0);
        tail = new Node(0,0);

        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(hash.find(key)==hash.end())
            return -1;

        Node* node = hash[key];
        deleteNode(node);
        insertAfterHead(node);

        return node->val;        
    }
    
    void put(int key, int value) {
        if(hash.find(key) != hash.end()){
            Node* node = hash[key];
            node->val = value;
            deleteNode(node);
            insertAfterHead(node);
            hash[key] = node;
        }
        else{
            if(hash.size() == cap){
                Node* lru = tail->prev;
                hash.erase(lru->key);
                deleteNode(lru);
                delete lru;
            }

            Node* node = new Node(key, value);
            insertAfterHead(node);
            hash[key] = node;
        }
        
    }
};
