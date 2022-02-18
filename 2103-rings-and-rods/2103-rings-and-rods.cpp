class Solution {
    public:
    int countPoints(string rings) {
        int len = rings.size();
        vector<int>rod(10);
        for(int i = 0; i < len; i+=2)
        {
            //bitwise mask  using bitwise OR operator
            //the rod which has all three colors will have value 7
            char color = rings[i] == 'R' ? 1 : rings[i] == 'G' ? 2 : 4;
            rod[rings[i+1] - '0'] |= color;
        }
        
        return count(rod.begin(), rod.end(), 7);
    }
};