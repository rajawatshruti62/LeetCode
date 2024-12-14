// Given an array of integers arr[] representing a permutation, implement the next permutation that rearranges the numbers into the lexicographically next greater permutation. If no such permutation exists, rearrange the numbers into the lowest possible order (i.e., sorted in ascending order). 
// Input: arr = [2, 4, 1, 7, 5, 0]
// Output: [2, 4, 5, 0, 1, 7]
// Explanation: The next permutation of the given array is {2, 4, 5, 0, 1, 7}.
class Solution {
  public:
    void nextPermutation(vector<int>& arr) {
        int idx=-1;
        for(int i=arr.size()-2;i>=0;i--){
            if(arr[i]<arr[i+1]){
            idx=i;break;}
        }
        if(idx==-1){
            reverse(arr.begin(),arr.end());
            return;
        }
        for(int i=arr.size()-1;i>=idx;i--){
            if(arr[i]>arr[idx]){
                swap(arr[i],arr[idx]);
                break;
            }
        }
        reverse(arr.begin()+idx+1,arr.end());
        // code here
    }
};
