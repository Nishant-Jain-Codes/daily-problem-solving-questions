/*

Code : Remove Min
Send Feedback
Implement the function RemoveMin for the min priority queue class.
For a minimum priority queue, write the function for removing the minimum element present. Remove and return the minimum element.
Note : main function is given for your reference which we are using internally to test the code.


*/

// solution 

#include <vector>
#define INT_MIN -2147483647 - 1
class PriorityQueue {
    vector<int> pq;

   public:
    bool isEmpty() { 
        return pq.size() == 0; 
    }

    int getSize() { 
        return pq.size(); 
    }

    int getMin() {
        if (isEmpty()) {
            return INT_MIN;
        }

        return pq[0];
    }

    void insert(int element) {
        pq.push_back(element);

        int childIndex = pq.size() - 1;

        while (childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;

            if (pq[childIndex] < pq[parentIndex]) {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            } else {
                break;
            }

            childIndex = parentIndex;
        }
    }

     int removeMin()
    {
        if(isEmpty())
        {
            return INT_MIN;
        }
        int ans = pq[0];
        pq[0]=pq[pq.size()-1];
         pq.pop_back();
        // sown heapify
        int pI=0;
        
        int lcI = 2*pI + 1;
        int rcI = 2*pI + 2;
        
        while(lcI<pq.size())
        {
            int mI = pI;
            if(pq[mI]>pq[lcI])
            {
                mI=lcI;
            }
            if(rcI<pq.size()&&(pq[rcI]<pq[mI]))
            {
                mI=rcI;
            }
            if(mI==pI)
            {
                break;
            }
            swap(pq[pI],pq[mI]);
            pI=mI;
            lcI = 2*pI + 1;
            rcI = 2*pI + 2;
        }
        return ans;
    }
    
};
