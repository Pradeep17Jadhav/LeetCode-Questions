class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(k > s.size())
            return false;

        unordered_set<string> hash;
        
        //insert all the substrings of size k in a set
        for(int i = 0; i <= s.size() - k; i++)
            hash.insert(s.substr(i, k));
        
//         //we have to match all the binary code of length k
//         //let k=1, so binary codes can be - 0, 1
//         //let k=2, so binary codes can be - 00, 01, 10, 11
//         //let k=3, so binary codes can be - 000, 100, 010, 001, 110, 101, 011, 111
//         //let k=4, so binary codes can be - 0000, 1000, 0100, 0010, 0001, 1100, 1010, 1001, 0011, 0101 and so on...
//         //we observe than for each k, the binary codes which can be formed are 2^k as for each digit there can either be 0 or 1
//         //so after adding all substrings to the set, if the size of set equals to 2^k,
//         //then we can say that binary string containts all substring of size k
//         return hash.size() == pow(2, k);
        


//             //Insertion into the set
//             for(int i =0;i<= s.size()-k;i++)
//                 hash.insert(s.substr(i,k));

            //Comparing res with 2^k
            return hash.size() == pow(2,k);
    }
};