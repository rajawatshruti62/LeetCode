// //Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), 
// return the next greater number for every element in nums.

//503. Next Greater Element II
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> s;
        for (int i = 2 * n - 1; i >= 0; i--) {
            int idx = i % n;
            while (!s.empty() && s.top() <= nums[idx]) {
                s.pop();
            }
            if (!s.empty()) {
                ans[idx] = s.top();
            }

            s.push(nums[idx]);
        }
        return ans;
    }
};
