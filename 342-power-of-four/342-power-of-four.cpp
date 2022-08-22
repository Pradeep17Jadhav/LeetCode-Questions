class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num < 0)
            return false;
        
        // a<<1 = 2
        // a<<2 = 4
        // a<<3 = 16
        // a<<4 = 16
        // a<<5 = 32
        // a<<6 = 64
        // a<<7 = 128
        // a<<8 = 256
        // a<<9 = 512
        // a<<10 = 1024
        // a<<11 = 2048
        // a<<12 = 4096
        // a<<13 = 8192
        // a<<14 = 16384
        // a<<15 = 32768
        for(int i = 0;i < 32;i += 2)
            if(num == 1 << i) //it returns power of 2s
                return true;
        return false;
    }
};