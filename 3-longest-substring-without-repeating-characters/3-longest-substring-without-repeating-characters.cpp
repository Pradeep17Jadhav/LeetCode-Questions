class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        return lengthOfLongestSubstring_2(s);
    }
    
    //Solution 1
    //TC: O(2N)
    //SC: O(N)
    int lengthOfLongestSubstring_1(string s) {
        unordered_set<char>set;
        int i = 0;
        int j = 0;
        int n = s.size();
        int maxx = 0;
        
        while(i < n and j < n)
        {
            //if char is not in the set, it is not repeated.
            //so insert it in the set and update max
            if(set.find(s[j]) == set.end())
            {
                set.insert(s[j]);
                maxx = max(maxx, j - i + 1);
                j++;
            }
            //if char is in set, it is repeated.
            //remove it from set and increament i pointer.
            else
            {
                set.erase(s[i]);
                i++;
            }
        }
        return maxx;
    }
    
    
    //Solution 2 - Optimization of Solution 1 (similar to solution 1)
    //Instead of moving left ptr one index at a time, we make it jump by multiple index
    //TC: O(N)
    //SC: O(N)
    int lengthOfLongestSubstring_2(string s) {
        unordered_map<char, int> map;
        int left = 0;
        int right = 0;
        int res = 0;
        int n = s.size();
        
        while(right < n) {
            //if char is already in map and its index is >= left, move left ptr ahead of its index
            if(map.find(s[right]) != map.end() && left <= map[s[right]])
                left = map[s[right]] + 1;

            map[s[right]] = right;
            res = max(res, right-left+1);
            right++;
        }

        return res;
    }
};