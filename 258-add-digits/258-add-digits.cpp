class Solution {
public:
    int addDigits(int num) {
        int sum = num;
        while(sum > 9)
        {
            int curr = 0;
            int num = sum;
            while(num)
            {
                curr += num % 10;
                num /= 10;
            }
            sum = curr;
        }
        return sum;
    }
};