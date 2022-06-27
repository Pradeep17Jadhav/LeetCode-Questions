class Solution {
public:
    int minPartitions(string n) {
        //The answer is, just return the maximum digit in the string
        // 13524 <- this is an input
        // 11111
        // 01111
        // 01101
        // 00101
        // 00100
        //so the maximum digit decides the answer

        // return minPartitionsOneLiner(n);
        return minPartitionsManually(n);
    }

    int minPartitionsOneLiner(string &n) {
        return *max_element(begin(n), end(n)) - '0';
    }
    int minPartitionsManually(string &n) {
        int maxx = -1; //as number is +ve integer
        for(char &c: n)
        {
            maxx = max(maxx, c-'0');
            if(maxx == 9) break;
        }
        return maxx;
    }
};