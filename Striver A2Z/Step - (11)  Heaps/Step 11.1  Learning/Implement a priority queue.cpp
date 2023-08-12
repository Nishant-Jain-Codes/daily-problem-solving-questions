int pop(vector<int> &heap)
{
    // Write you code here.
    int n = heap.size();
    if(n==0)
    {
        return -1;
    }
    int ans = heap[0];
    swap(heap[0],heap[n-1]);
    heap.pop_back();
    //heapify
    int i = 0;
    while(i<heap.size()){
        int left = 2*i+1;
        int right = 2*i+2;
        int largest = i;
        if(left<heap.size() && heap[left]>heap[largest]){
            largest = left;
        }
        if(right<heap.size() && heap[right]>heap[largest]){
            largest = right;
        }
        if(largest==i){
            break;
        }
        swap(heap[i],heap[largest]);
        i = largest;
    }
    return ans;
}

// Code Snippet of the push function: 
//
//     void push(vector<int> &heap, int x)
//     {
//           heap.push_back(x);
//
//            // Posistion of the current inserted element.
//            int pos=heap.size()-1;
//
//            // Shifting the element up until it reaches the top most node if it is larger than its parent.
//            while(pos>0)
//            {
//                int parent = (pos-1)/2;
//                if(heap[pos] > heap[parent])
//                {
//                    swap(heap[parent],heap[pos]);
//                    pos=parent;
//               }
//              else
//              {
//                  // As parent is larger the element now is in its correct position. 
//                  break;
//              }
//          }
//      }