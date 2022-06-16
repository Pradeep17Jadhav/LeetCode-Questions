class Solution {
public:
    //Reference: https://www.youtube.com/watch?v=UflHuQj6MVA
    //DP Solution
    //Create a matrix of n*n
    //Each cell (start, end) of matrix defines that the substring starting at index 'start' and ending at index 'end' is palindrome(1) or not(0)
    //Then we will iterate over the string with two pointers specifying start and end position of current substring
    //Start with 1 letter and after completing each cycle, increase the size of substring to 2,3,4...,n
    //First manually mark the (0,0),(1,1),(2,2),....(n,n) to 1 as all chars of a string are palindrome
    //Then again check for substring of size 2 chars that both chars are same (palindrome) or not 
    //Now after this, use the data stored in dp[] to find all next palindromes
    //on finding new palindrome, mark its start and end index as new longest substring bcz we are increasing the size after each iteration
    string longestPalindrome(string s) {
        int len = s.size();
        if(len == 1)
            return s;

        vector<vector<int>> dp(len, vector<int>(len, 0)); //n*n matrix
        
        int maxStart = 0; // start index of latest longest substring
        int maxEnd = 0; // end index of latest longest substring
        int blockSize = 1; //size of subarray during current iteration. keep increasing it after each iteration
        int start = 0;
        int end = start + blockSize - 1;
        
        //using loop to manually mark palindromes (without using dp) for 1 and 2 sized substrings
        while(end < len && blockSize <= 2) {
            if(s[start] == s[end]) {
                dp[start][end] = 1;
                maxStart = start;
                maxEnd = end;
            }
            start++;
            end++;
            
            if(end == len) {
                blockSize++;
                start = 0;
                end = start + blockSize - 1;
            }
        }
        
        //looping string again to find all remaining substrings of size 3 to n using dp
        for(blockSize = 3; blockSize <= s.size(); blockSize++) {
            start = 0;
            end = start + blockSize - 1;
            while(end < len) {
                //check if curr substring is a palindrome
                //condition 1 - both the starting and ending char should be same
                //condition 2 - the substring between start and end ptrs should also be palindrome. use dp[] to find it out
                if(s[start] == s[end] && dp[start+1][end-1]) {
                    dp[start][end] = 1;
                    maxStart = start;
                    maxEnd = end;
                }
                start++;
                end++;
            }
        }
        
        return s.substr(maxStart, maxEnd-maxStart+1);
    }
};