class Solution {
public:
    int numberOfSteps(int num) {
        int steps = 0;
        while(num) {
            // num = num%2 == 0 ? num / 2 : num-1;
            num = num%2 == 0 ? num >> 1 : num-1; // num=num>>1 right shift num is equivalent to num=num/2
            steps++;
        }
        
        return steps;
    }
};