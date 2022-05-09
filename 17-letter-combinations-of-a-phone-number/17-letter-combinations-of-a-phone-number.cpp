class Solution {
public:
    //Iterative approach
    vector<string> letterCombinations(string digits) {
        if(digits == "") 
            return {};
        vector<string> mappings{"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans{""};

        for(auto digit : digits) //take all digits one by one. 
        {
            vector<string> extendCombination;
            for(auto& currentCombination : ans) //use existing answer array and append the chars to create new answer
            {
                for(auto newChar : mappings[digit - '2']) // append the digits
                {
                    extendCombination.push_back(currentCombination + newChar);                            
                }
            }
            // ans = move(extendCombination); // same as ans = extendCombination, just avoids copying each value. 
            swap(ans, extendCombination); // we can also use swap instead of move
        }
        return ans;
    }
};