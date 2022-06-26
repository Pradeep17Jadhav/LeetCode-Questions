class Solution {
public:
    //sliding window solution
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int windowSum = accumulate(cardPoints.begin(), cardPoints.begin() + k, 0); //sum of first k elements of cardPoints
        int maxScore = windowSum;
        
        //initialize window of size k
        //keep reducing the window from right and adding the window from end of array
        //check maximum sum at each window
        while(k) {
            windowSum -= cardPoints[k-1]; //
            windowSum += cardPoints[n-1];
            k--;
            n--;
            maxScore = max(maxScore, windowSum);
        }
        
        return maxScore;
    }
};