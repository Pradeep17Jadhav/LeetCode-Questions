class Solution {
public:
    int addDigits(int num) {
        return method1(num);
        // return method2(num);
    }
        
    int method1(int &num)
    {
        // if(!num) return 0;
        // return num % 9 == 0 ? 9 : num % 9;
        // edge case for 0 can be handled using next method
        // subtract 1 from original num, so remainder of 0 becomes 8
        // then add 1 in result. this trick works correctly for all nos.
        return (num - 1) % 9 + 1; 
    }

    int method2(int &num)
    {
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