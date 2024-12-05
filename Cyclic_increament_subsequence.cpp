//Make String a Subsequence Using Cyclic Increments
/*In an operation, you select a set of indices in str1, and for each index i in the set, increment str1[i] to the next character cyclically. That is 'a' becomes 'b', 'b' becomes 'c', and so on, and 'z' becomes 'a'.
Return true if it is possible to make str2 a subsequence of str1 by performing the operation at most once, and false otherwise.
Input: str1 = "abc", str2 = "ad"
Output: true
Explanation: Select index 2 in str1.
Increment str1[2] to become 'd'. 
*/
class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int i=0,j=0;
        while(i<str1.size() && j<str2.size()){
            if(str1[i]-'a'==str2[j]-'a' || (str1[i]-'a'+1)%26==str2[j]-'a')
                j++;
            if(j==str2.size())
                return true;
            i++;
        }
        return false;
    }
};
