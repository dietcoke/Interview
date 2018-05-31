class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: An integer denotes the middle number of the array
     */
    int median(vector<int> &nums) {
        // write your code here
        if(nums.size()==0)
        {
            return -1;
        }
        
        if(nums.size()==1)
        {
            return nums[0];
        }
        
        int n = nums.size();
        int t = (n-1)/2;
        //less equal count = t+1
        
        return findMedian(nums, t+1, INT_MIN, INT_MAX);
    }
    
    int findMedian(vector<int> &nums, int count, long long left, long long right)
    {
        if(left==right)
        {
            return left;
        }
        
        long long guess = left + (right - left)/2;
        
        int maxNum = left;
        int actualCount = 0;
        for(auto num : nums)
        {
            if(num <= guess)
            {
                maxNum = max(maxNum, num);
                actualCount++;
            }
        }
        
        if(actualCount == count)
        {
            return maxNum;
        }
        
        if(actualCount < count)
        {
            return findMedian(nums, count,guess+1, right);
        }
        
        return findMedian(nums, count, left, maxNum);
    }
    
};
