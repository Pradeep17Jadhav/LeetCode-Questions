class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0) return 1;
        vector<int>binary;
        int res = 0;
        while(n > 0)
        {
            binary.push_back(n%2^1);
            n = n/2;
        }
        
        cout << "size" << binary.size();
        int base = 1;
        int size = binary.size();
        for(int i = 0; i < size; i++)
        {
            res += binary[i] * base;
            base *= 2;
        }
        
        return res;
    }
};