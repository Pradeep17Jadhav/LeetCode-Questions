class PeekingIterator : public Iterator {
    int nextVal; //store the 'next value' for use in peek function
    bool iterHasNext; //store the 'has next value'
    
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        iterHasNext=Iterator::hasNext(); //current has_next value
	    if(iterHasNext)
            nextVal = Iterator::next(); //"nextVal" for "future" use in "peek" function
	}
	
	int peek()
    {
        return nextVal; //current nextVal
	}
	
	int next()
    {
	    int curNext = nextVal; //store current next for returning
        
        iterHasNext=Iterator::hasNext(); //change iterHasNext
	    if(iterHasNext) 
            nextVal = Iterator::next(); //change nextVal and move iterator to next position
        
	    return curNext; //return previously stored current next
	}
	
	bool hasNext() const
    {
	    return iterHasNext; //return current iter_hashnext value
	}
};