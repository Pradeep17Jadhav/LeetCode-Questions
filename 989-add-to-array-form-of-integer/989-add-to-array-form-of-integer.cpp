class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int carry = k;//take k as carry

        for(int i = num.size() - 1; i >= 0; i--)
        {
            int sum = num[i] + carry%10; //add current element and last digit of carry
            num[i] = sum%10; //store remainder
            carry = carry/10 + sum/10; //add quotiant of sum in carry
        }

        //handle cases where k > value of num
        while(carry)
        {
            num.insert(num.begin(), carry%10);
            carry = carry/10;
        }       
        return num;
    }
};