// Given an array of integers arr, replace each element with its rank.

// The rank represents how large the element is. The rank has the following rules:

// Rank is an integer starting from 1.
// The larger the element, the larger the rank. If two elements are equal, their rank must be the same.
// Rank should be as small as possible.
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>cpy(arr.begin(),arr.end());
        sort(cpy.begin(),cpy.end());
        unordered_map<int,int>mp;int r=1;
        for(int i:cpy){
            if(!mp[i])
            mp[i]=r++;
        }
        for(int i=0;i<arr.size();i++){
            cpy[i]=mp[arr[i]];
        }
        return cpy;
    }
};
