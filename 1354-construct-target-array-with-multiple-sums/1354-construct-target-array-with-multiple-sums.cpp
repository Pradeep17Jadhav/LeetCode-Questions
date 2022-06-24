class Solution {
public:
    //We will try to reduce target to array of 1's
    bool isPossible(vector<int>& target) {        
        if(target.size() == 1) 
            return target[0] == 1;
        
        priority_queue<int> pq(target.begin(), target.end());

        //find sum of target array        
        long sum = 0;
        for(int i = 0; i < target.size(); i++)
            sum += target[i];
        
        //if top of heap becomes 1, loop terminates
        while(pq.top() != 1) 
        {
            // find largest and 2nd largest element 
            // 2nd largest will help us in finding multiplying factor
            long largest_1 = pq.top();
            pq.pop();
            long largest_2 = pq.top();

            // sum of rest of elm
            long restArrSum = sum - largest_1;

            // calculating multiplying factor 
            int n = max(1L, (largest_1 - largest_2) / restArrSum); // 1 because factor should be at least 1

            // updating largest elm
            largest_1 -= (restArrSum * n);

            pq.push(largest_1);
            sum = restArrSum + largest_1;

            // if largest becomes less than 1 we cant go back to arr with 1's
            if(largest_1 <1) 
                return false;
        }
        
        return true;
    }
};