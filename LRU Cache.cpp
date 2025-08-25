
class LRUCache {
   public:
    struct Node {
        int key;
        int data;
        Node* next;
        Node* prev;

       public:
        Node(int key, int val) {
            this->key = key;
            data = val;
            next = nullptr;
            prev = nullptr;
        }
        Node(int key, int val, Node* next, Node* prev) {
            this->key = key;
            data = val;
            this->next = next;
            this->prev = prev;
        }
    };

    map<int, Node*> mp;
    int capacity;
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    void deleteNode(Node* node) {
        if (node == nullptr) return;

        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insertAtHead(Node* node) {
        if (node == nullptr) return;

        node->next = head->next;
        head->next = node;
        node->prev = head;
        node->next->prev = node;
    }

    LRUCache(int capacity) {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;

        Node* start = mp[key];
        deleteNode(start);
        insertAtHead(start);

        return start->data;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            node->data = value;
            deleteNode(node);
            insertAtHead(node);
        } else {
            Node* node = new Node(key, value);
            if (mp.size() == capacity) {
                mp.erase(tail->prev->key);
                deleteNode(tail->prev);
                insertAtHead(node);
                mp[key] = head->next;
            } else {
                insertAtHead(node);
                mp[key] = head->next;
            }
        }
    }
};
