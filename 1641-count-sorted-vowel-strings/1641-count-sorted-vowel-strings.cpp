class Solution {
public:
    string chars = "aeiou";
    int res = 0;
    int countVowelStrings(int n) {
        return countVowelStrings_1(n); 
    }
    
    
    int countVowelStrings_1(int n) {
        //traverse for required chars
        for (int i = 0; i <= n; i++) {
            int sum = 0;
            
            //Available chars:
            //for a -> [a,e,i,o,u]
            //for e -> [e,i,o,u]
            //for i -> [i,o,u]
            //for o -> [o,u]
            //for u -> [u]
            for (int j = 0; j <= i; j++) {
                sum += j + 1;
                res += sum;
            }
        }
        return res;
    }

    int countVowelStrings_2(int n) {
        char temp = '#';
        find(n, temp);
        return res;
    }
    
    void find(int n, char &temp) {
        if(!n) {
            res++;
            return;
        }
        
        for(char &c: chars) {
            if(temp > c)
                continue;
            temp = c;
            find(n-1, temp);
            temp = '#';
        }
    }
};