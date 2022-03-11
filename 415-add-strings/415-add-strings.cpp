class Solution {
public:
    string addStrings(string a, string b) {

        if(b.size() > a.size())
        {
            string temp = a;
            a = b;
            b = temp;
        }
        int m = a.size();
        int n = b.size();
        int carry = 0;
        while(m)
        {
            m--;
            n--;
            int sum = 0;
            sum += carry + a[m] - '0';
            
            if(n >= 0) 
                sum += b[n] - '0';
            
            a[m] = sum%10 + '0';
            carry = sum/10;

        }

        if(carry)
            return (char)(carry + '0') + a;
        
        return a;
    }
};