class Solution {
public:
//     For checking if two words have a letter in common, we can directly hash the words into an integer and then 
//     compare each bit of integer obtained after hashing. 
//     If there's no common set bit in the hash of both words, then we can be sure that there exists no common letter between those words.

//     An 32-bit integer can be used for this purpose. The 26 bits in the hashed integer (from the right)
//     would denote occurence of each letter a,b,...,z, 1 denoting that a letter occurs and 0 denoting that a letter doesn't occur. 
//     We just need to ensure that same bit in hash of both words are not set
    
//     Consider word1 = "abex", word2 = "acdx"
//     hash1 = (11001000000000000000000100) in binary
//     hash2 = (10110000000000000000000100) in binary
//            ------------------------------------
//            & 10000000000000000000000100    ==>   common letters are present

    int maxProduct(vector<string>& words) {
        int n = words.size();
        int res = 0;
        vector<int> mask(n);
        
        for(int i = 0; i < n; i++) {
            for(auto& ch : words[i]) {
                //left shift 1 to [0-25] places
                //Lets find position of 'c'
                //Binary of 1 = 00000000001
                //Number of shifts= ('c' -'a') = (99-97) = 2
                //After shifting by 2 places - 00000000001 -> 00000000100
                //so starting from right, position of c (which is present in word) is marked as 1.
                //More examples - 
                //'f' = (102-97) = 5. So  00000000001 -> 000000100000 (5th place from right is marked as 1)
                //'z' = (122-97) = 25 ->
                //So 00000000000000000000000000000001 -> 10000000000000000000000000000000 (25th place from right is marked as 1)
                int shifted = 1 << (ch - 'a');
                
                //bitwise or the whole word mask with current letter so that previous marked char positions are preserved and curr char is added
                //suppose we already checked 'bdf' (0000101010) and curr char is 'g' (0001000000)
                //so the new mask value will be 0000101010 | 0001000000 = 0001101010
                mask[i] |= shifted;
            }  

            for(int j = 0; j < i; j++) {
                if((mask[i] & mask[j]) == 0) // Bitwise AND - check if no common set bit in the hash of words[i] and words[j]
                    res = max(res, int(words[i].size() * words[j].size()));
            }
        }

        return res;
    }
};