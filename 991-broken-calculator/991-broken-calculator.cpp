class Solution {
public:
    int brokenCalc(int startValue, int target) {
        //instead of working on startValue, we will work on target
        //we will keep on dividing the target by 2 until startValue < target, BUT,
        //If target is even, target = target / 2 ---> (1 operation)
        //If target is odd, target = (target + 1) / 2 ---> (2 operations)
        
        int operations = 0;
        while(startValue < target)
        {
            if(target % 2 == 0)
                target /= 2;
            else
                target++;

            operations++;
        }
        return operations + startValue - target;
    }
};