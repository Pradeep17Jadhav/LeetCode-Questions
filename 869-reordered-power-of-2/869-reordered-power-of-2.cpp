class Solution {
public:
    bool reorderedPowerOf2(int N) {
        string str = sorted(N);
        for (int i = 0; i < 32; i++)
            if (str == sorted(1 << i)) 
                return true;
        return false;
    }
    
    string sorted(int n) {
        string res = to_string(n);
        sort(res.begin(), res.end());
        return res;
    }
};