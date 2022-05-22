class Solution {
public:
    //Method 1 - Bruteforce
    //In bruteforce, 
    //we will have to go to each ith letter, then keep on increasing the range on right - O(N),
    //then check if curr range is palindrome - O(N)
    //Then repeat the same process by starting at next ith position - O(N)
    //So total TC - O(N)
    
    //Method 2 - Optimized method
    //Here, we will start with ith letter, and keep on increase range in both left and right - O(N)
    //on each range change, we can check if extreme ends match to prove that it still a palindrome - O(N)
    //this way we will find all the palindromes in string whose center is at ith index - total TC: O(N^2)
    //But this will find only the palindromes having odd length, i.e. 1,3,5,7,... etc
    //To find even ranges, repeat the above steps, but this time we will start with a pair {ith, (i+1)th},
    //and then keep on increasing range on left and right. 
    //This way we will find palindromes of lengths 2,4,6,8,... Here also the total TC: O(N^2) 
    //So the total TC: O(N^2) + O(N^2)  =  O(2N^2) =  O(N^2) 
    
    int countSubstrings(string s) {
        int res = 0;
        int n = s.size();
        
        for(int i = 0; i < n; i++) {
            res += findPalindromes(s, i, i); //find all odd length palindromes having ith index as center
            res += findPalindromes(s, i, i+1); //find all even length palindromes having center pair {i, i+1}
        }
        
        return res;
    }
    
    int findPalindromes(string &s, int l, int r) {
        int res = 0;
        
        //check out of bound index and match current extreme ends of range
        while(l >= 0 && r < s.size() && s[l] == s[r]) {
            res++;
            l--;
            r++;
        }
        return res;
    }
};