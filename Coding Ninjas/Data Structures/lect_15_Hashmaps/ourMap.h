/*
our own hashmap
*/
#include<string>
using namespace std;
template<typename T>
class mapNode{
    string key;
    T value; 
    mapNode* next;
    mapNode(string key,T value)
    {
        this->key = key;
        this->value = value;
        next=NULL;
    }
    ~mapNode()
    {
        delete next;
    }
    friend class ourmap;
}
template<typename T>
class ourmap{
    mapNode<T>** buckets;
    int count;
    int numBuckets;
    public:
    outmap() // constructor
    {
        size=0;
        numBucktes=5;
        buckets = new mapNode<T>* [numBuckets];
        for(int i =0;i<numBuckets;i++)
            buckets[i]=NULL;
    }
    ~ourmap()   // distructor
    {
        for(int i =0;i<numBuckets;i++)
            delete buckets[i];
        delete [] buckets;
    }
    int size()
    {
        return count;
    }
    private:
    
    int getBucketIndex(string key)
    {
        int hashCode;
        int currCoeff =1;
        for(int i = key.length()-1,i>=0;i--)
        {
            hashCode+= key[i]*currCoeff;
            hashCode%=numBuckets;
            currCoeff*=37;
            currCoeff%=numBuckets;
        }
        return hashCode%numBuckets;
    }
    
    void rehash()
    {
        mapNode<T>** temp = buckets;
        bucktes = new mapNode<T>*[2*numbuckets];
        for(int i =0;i<2*numbuckets;i++)
            bucktes[i]=NULL;
        int oldBucketCount=numbuckets;
        numbuckets*=2;
        count=0;
        for(int i =0;i<oldBucketCount;i++)
        {
          mapNode<V>* head=temp[i];
          while(head!=NULL)
          {
            string key = head->key;
            T value = head->value;
            insert(key,value);
            head=head->next;
          }  
        }
        for(int i =0;i<oldBucketCount;i++)
        {
            mapNode<V>* head=temp[i];
            delete head;
        }
        delete []temp;
    }
    public:
    void insert(string key,T value)
    {
        int bucketIndex=getBucketIndex(key);
        mapNode<V>* head=buckets[bucketIndex];
            while(head!=NULL)
            {
                if(head->key==key)
                {
                    head->value=value;
                    return ;
                }
                head=head->next;
            }
        head=buckets[bucketIndex];
        mapNode<V>* node = new mapNode<V>* (key,value);
        node->next=head;
        buckets[bucketIndex]=node;
        count++;
        double loadfactor = (1.0*count)/numBuckets;
        if(loadfactor>0.7)
            rehash();
    }
    T getvalue(string key)
    {
       int bucketIndex=getBucketIndex(key);
        mapNode<V>* head=buckets[bucketIndex]; 
        while(head!=NULL)
            {
                if(head->key==key)
                {
                    return head->value;
                }
                head=head->next;
            }
        return 0;
    }
    T remove(string key)
    {
        int bucketIndex=getBucketIndex(key);
        mapNode<V>* head=buckets[bucketIndex];
        mapNode<V>* prev=NULL;
        
        while(head!=NULL)
        {
            if(head->key==key)
            {
                if(prev!=NULL)
                {
                 prev->next=head->next;   
                }
                else
                {
                   buckets[bucketIndex]=head->next;
                }
                head->next=NULL;
                T value = head->value;
                delete head;
                count--;
                return value;
                
            }
            prev=head;
            head=head->next;
        }
        return 0;
    }
};
