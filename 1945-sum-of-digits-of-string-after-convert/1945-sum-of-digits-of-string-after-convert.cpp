class Solution {
public:
    int getLucky(string s, int k) {
        int sum = 0;
        for(char &c: s)
        {
            int val = c - 'a' + 1;
            sum += val / 10 + val % 10;
        }

        while(--k) 
        {
            int curr = 0;
            while(sum)
            {
                curr += sum % 10;
                sum /= 10;
            }
            sum = curr;
        }
        
        return sum;
    }
};