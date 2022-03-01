//dividing a number by 2 == right shifting the number
//so the Least Significant Bit is removed

//Let number is X.
//for odd X, LSB is always 1 (ex 5 = 101, 13 = 1101)
//on diving odd X by 2, LSB 1 is removed, so the X/2 number must be having one less 1's bit.
//so in solution, if i is odd, the ans = (1's in (x/2)) + 1

//for even numbers, LSB is always 0 (ex 4 = 100, 12 = 1100)
//on diving even X by 2, LSB 0 is removed, so the X and X/2 must be equal 1's bit.
//so in solution, if i is odd, the ans = (1's in (x/2)) + 0,

//using this info, we can find 1's of a X by dividing it by 2 and using 1's of the X/2 number

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n + 1); //create array for 0 to n
        res[0] = 0; //since 0 has zero 1 bits

        for(int i = 1; i <= n; i++)
        {
            res[i] = res[i/2] + i%2;
        }
        return res;
    }
};