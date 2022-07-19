class FreqStack {
public:
    //example - [5],[7],[5],[7],[4],[5]
    //store frequency of each number. ex- 5-3, 7-2, 4-1
    unordered_map<int, int>freq;
    
    //keep order of the elements of each frequency. used for case of tie of maxfreq elements
    //ex, 1-[5,7,4], 2-[5,7], 3-[5]
    unordered_map<int, stack<int>>groups;
    
    //remember current maximum frequency to use pointer for map
    int maxFreq = 0;
    
    FreqStack() {
        //refer - https://www.youtube.com/watch?v=MJN1-T0oils
    }
    
    void push(int val) {
        freq[val]++;
        maxFreq = max(maxFreq, freq[val]);
        groups[freq[val]].push(val);
    }
    
    int pop() {
        int res = groups[maxFreq].top();
        groups[maxFreq].pop();
        freq[res]--;
        if(!groups[maxFreq].size())
            maxFreq--;
        return res;
    }
};