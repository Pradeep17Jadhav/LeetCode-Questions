class Solution {
public:
    bool isHappy(int n) {
        int sum = n;
        int rem;
        unordered_set<int>hash;
        while(sum != 1)
        {
            int curr = 0;
            while(sum)
            {
                rem = sum % 10;
                curr += rem * rem;
                sum /= 10;
            }
            
            sum = curr;
            if(hash.find(sum) != hash.end())
                break;
            
            hash.insert(sum);
        }
        
        return sum == 1;
    }
};