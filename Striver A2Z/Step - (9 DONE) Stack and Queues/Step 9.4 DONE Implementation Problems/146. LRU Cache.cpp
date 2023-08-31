class LRUCache
{
private:
    class Node
    {
    public:
        int key;
        int value;
        Node *next;
        Node *prev;
        Node(int key, int value) : key(key), value(value), next(NULL), prev(NULL) {}
    };

    int capacity;
    Node *head;
    Node *tail;
    unordered_map<int, Node *> map;

    void moveToHead(Node *node)
    {
        deleteNode(node);
        addNode(node);
    }

    void addNode(Node *node)
    {
        Node *temp = head->next;
        head->next = node;
        node->next = temp;
        node->prev = head;
        temp->prev = node;
    }

    void deleteNode(Node *node)
    {
        Node *prev = node->prev;
        Node *next = node->next;
        prev->next = next;
        next->prev = prev;
    }

public:
    LRUCache(int capacity)
    {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
        this->capacity = capacity;
    }

    int get(int key)
    {
        if (map.find(key) != map.end())
        {
            Node *node = map[key];
            int value = node->value;
            moveToHead(node);
            return value;
        }
        else
        {
            return -1;
        }
    }

    void put(int key, int value)
    {
        if (map.find(key) != map.end())
        {
            Node *node = map[key];
            node->value = value;
            moveToHead(node);
        }
        else
        {
            if (map.size() == capacity)
            {
                Node *nodeToRemove = tail->prev;
                deleteNode(nodeToRemove);
                map.erase(nodeToRemove->key);
                delete nodeToRemove;
            }
            Node *newNode = new Node(key, value);
            addNode(newNode);
            map[key] = newNode;
        }
    }
};
