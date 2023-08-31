class Node
{
public:
    int key, value, freq;
    Node *next;
    Node *prev;
    Node(int _key, int _value)
    {
        key = _key;
        value = _value;
        freq = 1;
    }
};
class List
{
public:
    int size;
    Node *head;
    Node *tail;
    List()
    {
        size = 0;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    void addNode(Node *node)
    {
        Node *temp = head->next;
        node->next = temp;
        temp->prev = node;
        head->next = node;
        node->prev = head;
        size++;
    }
    void removeNode(Node *node)
    {
        Node *prev = node->prev;
        Node *next = node->next;
        prev->next = next;
        next->prev = prev;
        size--;
    }
};
class LFUCache
{
public:
    unordered_map<int, Node *> keyMap;
    unordered_map<int, List *> freqMap;
    int capacity;
    int curSize;
    int minFreq;
    void updateFreqMap(Node *node)
    {
        keyMap.erase(node->key);
        freqMap[node->freq]->removeNode(node);
        if (node->freq == minFreq && freqMap[node->freq]->size == 0)
        {
            minFreq++;
        }
        if (freqMap.find(node->freq + 1) != freqMap.end())
        {
            freqMap[node->freq + 1]->addNode(node);
        }
        else
        {
            freqMap[node->freq + 1] = new List();
            freqMap[node->freq + 1]->addNode(node);
        }
        node->freq++;
        keyMap[node->key] = node;
    }

public:
    LFUCache(int capacity)
    {
        this->capacity = capacity;
        curSize = 0;
        minFreq = 0;
    }
    int get(int key)
    {
        if (keyMap.find(key) == keyMap.end())
        {
            return -1;
        }
        else
        {
            Node *keyNode = keyMap[key];
            int val = keyNode->value;
            updateFreqMap(keyNode);
            return val;
        }
    }

    void put(int key, int value)
    {
        if (capacity == 0)
        {
            return;
        }
        if (keyMap.find(key) != keyMap.end())
        {
            Node *keyNode = keyMap[key];
            keyNode->value = value;
            updateFreqMap(keyNode);
        }
        else
        {
            if (curSize == capacity)
            {
                List *minFreqList = freqMap[minFreq];
                Node *toBeRemoved = minFreqList->tail->prev;
                keyMap.erase(toBeRemoved->key);
                minFreqList->removeNode(toBeRemoved);
                curSize--;
            }
            curSize++;
            minFreq = 1;
            List *minFreqList = new List();
            if (freqMap.find(minFreq) != freqMap.end())
            {
                minFreqList = freqMap[minFreq];
            }
            Node *newNode = new Node(key, value);
            minFreqList->addNode(newNode);
            keyMap[key] = newNode;
            freqMap[minFreq] = minFreqList;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */