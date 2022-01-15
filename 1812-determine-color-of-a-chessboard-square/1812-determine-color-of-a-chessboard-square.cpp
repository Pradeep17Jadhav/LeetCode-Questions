class Solution {
public:
    bool squareIsWhite(string coord) {
        // return isWhite(coord);
        return isWhiteOneLiner(coord);
    }
    
    //logic 1 with explaination
    bool isWhite(string &coord)
    {
        //convert x and y in 0 and 1
        //first convert a,b,c,d,... to 1,2,3,4... and then convert to 0 for white, 1 for black
        int x = (coord[0] - 'a' + 1) % 2;
        
        //convert y coordinate to 0 for white, 1 for black
        int y = (coord[1] - '0') % 2;

        if(x == 0)
            return y == 1;
        else
            return y != 1;
    }
    
    //logic 2 with explaination
    bool isWhiteOneLiner(string &coord)
    {
        //coord[0] will start from 97 (for a)
        //coord[1] will start from 49 (for 1)
        //mod2 of their addition gives 0 for black and 1 for white
        //example - for "d3" -> 151%2=1 which is white box
        return (coord[0] + coord[1]) % 2;
    }
};