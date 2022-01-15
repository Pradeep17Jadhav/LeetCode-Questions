class Solution {
public:
    bool squareIsWhite(string coordinates) {
        
        int x = (coordinates[0] - 'a' + 1) % 2;
        int y = (coordinates[1] - '0') % 2;
        
        if(x == 0)
            return y == 1;
        else
            return y != 1;
    }
};