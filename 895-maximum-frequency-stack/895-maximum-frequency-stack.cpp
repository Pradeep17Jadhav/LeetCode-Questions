class FreqStack {
public:
    unordered_map<int, int>freq;
    unordered_map<int, stack<int>>groups;
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
        int res;
        res = groups[maxFreq].top();
        groups[maxFreq].pop();
        if(!groups[freq[res]--].size())
            maxFreq--;
        return res;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */