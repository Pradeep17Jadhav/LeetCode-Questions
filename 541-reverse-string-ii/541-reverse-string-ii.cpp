class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();
        int i = 0;
        while(i < n)
        {
            int index = i + k;
            if(index > n) 
                index = n; 
            
            reverse(s.begin() + i, s.begin() + index);
            i += 2 * k;
        }
        return s;
    }
};