//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// design the class in the most optimal way

class LRUCache
{
private:
    class Node
    {
    public:
        int key, value;
        Node *next, *prev;
        Node(int key, int value) : key(key), value(value), next(NULL), prev(NULL) {}
    };
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
    // Constructor for initializing the cache capacity with the given value.
    int capacity;
    Node *head;
    Node *tail;
    unordered_map<int, Node *> map;
    LRUCache(int cap)
    {
        // code here
        capacity = cap;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    // Function to return value corresponding to the key.
    int GET(int key)
    {
        // your code here
        if (map.find(key) != map.end())
        {
            Node *node = map[key];
            int value = node->value;
            moveToHead(node);
            return value;
        }
        else
            return -1;
    }

    // Function for storing key-value pair.
    void SET(int key, int value)
    {
        // your code here
        if (map.find(key) != map.end())
        {
            Node *node = map[key];
            node->value = value;
            moveToHead(node);
        }
        else
        {
            if (capacity == map.size())
            {
                Node *node = tail->prev;
                deleteNode(node);
                map.erase(node->key);
            }
            Node *newNode = new Node(key, value);
            map[key] = newNode;
            addNode(newNode);
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);

        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->SET(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->GET(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends