class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> correct;
        string curr = "";
        bool valid = true;
        for(string i:emails)
        {
            for(int j = 0; j < i.size(); j++)
            {
                if(i[j] == '@')
                {
                    correct.insert(curr + '@' + i.substr(j + 1));
                    break;
                }
                
                if(i[j] == '+')
                    valid = false;
                
                if(i[j] != '.' and valid)
                    curr += i[j];
                
            }
            curr = "";
            valid = true;
        }
        
        for(string i : correct)
            cout << i << endl;
        return correct.size();
    }
};