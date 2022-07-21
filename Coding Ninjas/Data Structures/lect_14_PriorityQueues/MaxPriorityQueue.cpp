/*
Code : Max Priority Queue
Send Feedback
Implement the class for Max Priority Queue which includes following functions -
1. getSize -
Return the size of priority queue i.e. number of elements present in the priority queue.
2. isEmpty -
Check if priority queue is empty or not. Return true or false accordingly.
3. insert -
Given an element, insert that element in the priority queue at the correct position.
4. getMax -
Return the maximum element present in the priority queue without deleting. Return -Infinity if priority queue is empty.
5. removeMax -
Delete and return the maximum element present in the priority queue. Return -Infinity if priority queue is empty.
Note : main function is given for your reference which we are using internally to test the class.

*/

// solution 


#include<vector>
int INT_MIN= -2147483647 - 1;
class PriorityQueue // max priority Queue
{   
    vector<int> pq;
    public:
    PriorityQueue() {
        // Implement the constructor here
    }

    /**************** Implement all the public functions here ***************/
	int getSize() { 
        // Implement the getSize() function here
        return pq.size();
    }

    bool isEmpty() {
        // Implement the isEmpty() function here
        return pq.size()==0;
    }
    
    
    
    void insert(int element) {
        // Implement the insert() function here
        pq.push_back(element);
        int ci = pq.size()-1;
        
        while(ci>0)
        {	
            int pi= (ci-1)/2;
            if(pq[ci]>pq[pi])
            {
                swap(pq[ci],pq[pi]);
            }
            else 
                break;
            
            ci = pi;
            
        }
    }

    int getMax() {
        // Implement the getMax() function here
        if(isEmpty())
        {
            return INT_MIN;
        }
        else
        {
            return pq[0];
        }
    }

    int removeMax() {
        // Implement the removeMax() function here
        if(isEmpty())
        {
            return INT_MIN;
        }
        int ans = pq[0];
        pq[0]=pq[pq.size()-1];
        pq.pop_back();
        int pi = 0 ;
        int li = 2*pi +1;
        int ri = 2*pi +2;
        
        while(li<pq.size())
        {	
            int mi = pi;
            if(pq[mi]<pq[li])
            {
                mi=li;
            }
            if((ri<pq.size())&&(pq[mi]<pq[ri]))
            {
                mi=ri;
            }
            if(pi==mi)
                break;
            swap(pq[pi],pq[mi]);
            
            pi=mi;
            li = 2*pi +1;
            ri = 2*pi +2;
        }
        return ans;
    }

    
};
