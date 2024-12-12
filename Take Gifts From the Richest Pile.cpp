//You are given an integer array gifts denoting the number of gifts in various piles. Every second, you do the following:

// Choose the pile with the maximum number of gifts.
// If there is more than one pile with the maximum number of gifts, choose any.
// Leave behind the floor of the square root of the number of gifts in the pile. Take the rest of the gifts.
// Return the number of gifts remaining after k seconds.
class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        while(k--){
            sort(gifts.rbegin(),gifts.rend());
            int pile=gifts[0];
            gifts.erase(gifts.begin());
            gifts.push_back(sqrt(pile));
        }
        long long ans=0;
        for(int i:gifts)ans+=i;
        return ans;
    }
};
