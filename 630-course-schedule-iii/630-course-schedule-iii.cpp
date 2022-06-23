class Solution {
private:
    static bool compare(vector<int> &a, vector<int> &b) {return a[1] < b[1];}
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), compare); //sort by last date of completion
        priority_queue<int> pq;
        int timeTaken = 0;
        
        //keep adding current course. when the time exhausts, remove the completed course having highest time
        for(int i = 0; i < courses.size(); i++) {
			if(timeTaken + courses[i][0] <= courses[i][1])
            {
                pq.push(courses[i][0]);
                timeTaken += courses[i][0];
            }
            else if(!pq.empty() && courses[i][0] <= pq.top())
            {
                timeTaken = timeTaken - pq.top() + courses[i][0];
                pq.pop();
                pq.push(courses[i][0]);
            }
        }
        
        return pq.size();        
    }
};