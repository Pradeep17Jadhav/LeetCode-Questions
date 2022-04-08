class KthLargest {
public:
    // Note - 
    // Syntax to create a max heap (default of priority queue):
    // priority_queue<int> q;
    // here the top element will always be the greatest of the queue
    
    // Syntax to create a min heap:
    // priority_queue<int, vector<int>, greater<int>> q;
    // here the top element will always be the smallest of the queue
    
    priority_queue<int, vector<int>, greater<int>> q; //imp - syntax to create min heap
    int x;
    KthLargest(int k, vector<int>& nums) { 
        x = k;
        for(int &i : nums)
        {
            //keep adding all elements in queue
            q.push(i);
            
            //when queue size exeeds the K elements, the top element will always be the k+1st largest element.
            //since we do not need it, we just remove it so that the top element will always be our answer
            if(q.size() > x)
                q.pop();
        }
    }
    
    int add(int val) {
        q.push(val);
        if(q.size() > x) //again, add the new element in the queue and remove top element so that new top will always be the answer.
            q.pop();
        return q.top();
    }
	
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
