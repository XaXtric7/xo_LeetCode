class LRUCache
{
private:
    class Node
    {
    public:
        int key;
        int value;
        Node *prev;
        Node *next;

        Node(int k, int v)
        {
            key = k;
            value = v;
            prev = next = nullptr;
        }
    };

    int capacity;
    unordered_map<int, Node *> cache;

    Node *head;
    Node *tail;

    void remove(Node *node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insert(Node *node)
    {
        node->prev = tail->prev;
        node->next = tail;

        tail->prev->next = node;
        tail->prev = node;
    }

public:
    LRUCache(int capacity)
    {
        this->capacity = capacity;
        head = new Node(0, 0);
        tail = new Node(0, 0);

        head->next = tail;
        tail->prev = head;
    }

    int get(int key)
    {
        if (cache.count(key) == 0)
        {
            return -1;
        }
        Node *node = cache[key];
        remove(node);
        insert(node);

        return node->value;
    }

    void put(int key, int value)
    {
        if (cache.count(key))
        {
            Node *node = cache[key];
            node->value = value;

            remove(node);
            insert(node);
            return;
        }
        if (cache.size() == capacity)
        {
            Node *lru = head->next;
            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }
        Node *node = new Node(key, value);

        insert(node);
        cache[key] = node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */