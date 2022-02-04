class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int>mp; 
        mp[0] = -1; //as sum starts with 0, we need to use -1 index so that it starts counting from 0,1,2.. 
        int res = 0;
        int sum = 0;
        
        //for each element, if it is 1 -> add 1 in sum
        //if it is 0 -> subtract 1 from sum
        //If at any index, sum becomes zero, it means that we have encountered equal number of 
        //zeros and ones from the beginning till the current index.
        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i] == 1 ?: -1;
            
            //if map already has value for sum, it means there are equal 0's and 1's between value of
            //map[sum] and current index. so we take max of current max and current diff.
            if(mp.find(sum) != mp.end())
                res = max(res, i - mp[sum]);
            else
                mp[sum] = i;
        }
        cout << sum;
        return res;
    }
};