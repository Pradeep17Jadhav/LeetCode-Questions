class Solution {
public:
    //Let x = 2, n = 10 i.e. 2^10
    //2^10 = (2*2)^5 = 4^5
    //4^5 = 4*(4^4) [ans = ans * x = 1*4 = 4].. (here 4 from 4*(x^x) is the ans)
    //4^4 = (4*4)^2 = 16^2
    //16^2 = (16*16)^1 = 256^1
    //256^1 = 256*256^0 = 256 [ans = ans * x = 4*256 = 1024].. (here 256 from 256*(x^x) is the ans)
    //Return the values back to get ans 1024
    //So for even power, we multiple the x by x and make n half
    //for odd power, we multiply ans by ans and subtract 1 from power
    
    //TC: O(logN)
    //SC: O(1)
    double myPow(double x, int n) {
        if(n == 0) return 1; //any number to the power of 0 is 1
        if(x == 1) return 1; //1 raise to anything is 1
        if(x == 0) return 0; //0 raise to anything is 0
        if (x == -1) {
            if (n % 2 == 0) return 1;
            else return -1;
        }
        
        long nn = n;
        double ans = 1.0;
        if(nn < 0)
            nn = -nn;
        
        while(nn > 0) {
            if(nn % 2 == 0) //even power
            {
                x *= x;
                nn /= 2;
            }
            else //odd power
            {
                ans *= x;
                nn--;
            }
        }
        
        if(n < 0)
            ans = (double)1.0 / (double)ans;
        
        return ans;
    }
};