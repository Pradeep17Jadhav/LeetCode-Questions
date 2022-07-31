class NumArray {
public:
    vector<int> arr;
    int sum = 0;
    
    NumArray(vector<int>& nums) {
        for(int &n: nums) {
            arr.push_back(n);
            sum += n;
        }
    }
    
    void update(int index, int val) {
        sum += val - arr[index];
        arr[index] = val;
    }
    
    int sumRange(int left, int right) {
        int ans = 0;
        int mid = arr.size()/2;
        int arrDiff = right - left;
        if(arrDiff < mid)
            ans = accumulate(arr.begin() + left, arr.begin() + right + 1, 0);
        else
            ans = sum - accumulate(arr.begin(), arr.begin()+left, 0) - accumulate(arr.begin()+right+1, arr.end(), 0);

        return ans;
    }
};