class Solution {
public:
    bool isHappy(int n) {
        // return solutionHash(n);
        return solutionFloyedCycleDetection(n);
    }
    
    //find next sum of square of all digits
    int next(int n)
    {
        int sum = 0;
        int rem;
        while(n)
        {
            rem = n % 10;
            sum += rem * rem;
            n /= 10;
        }
        return sum;
    }
    
    //floyed cycle detection algorithm
    bool solutionFloyedCycleDetection(int &n) {
        int fast = n;
        int slow = n;

        do {
            slow = next(slow);
            fast = next(next(fast));
        }
        while(slow != fast);

        return fast == 1;
    }
    
    //using hash to store visited value. if value is repeated then its a cycle.
    bool solutionHash(int &n) {
        int sum = n;
        int rem;
        unordered_set<int>hash;
        while(sum != 1)
        {
            sum = next(sum);

            //check if value is repeated. break if repeated as it will then go in a loop.
            if(hash.find(sum) != hash.end())
                break;
            
            hash.insert(sum);
        }
        return sum == 1;
    }
};