/*
Given a sentence that consists of some words separated by a single space, and a searchWord, check if searchWord is a prefix of any word in sentence.

Return the index of the word in sentence (1-indexed) where searchWord is a prefix of this word. If searchWord is a prefix of more than one word, return the index of the first word (minimum index). If there is no such word return -1.

A prefix of a string s is any leading contiguous substring of s.
*/
class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int idx = 1; 
        int flag = 0; 
        for (int i = 0; i < sentence.size(); i++) {
            if (i == 0 || sentence[i - 1] == ' ') {
                flag = 0; 
                int j = 0; 
                for (; j < searchWord.size(); j++) {
                    if (i + j >= sentence.size() || sentence[i + j] == ' ' || sentence[i + j] != searchWord[j]) {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0 && j == searchWord.size()) {
                    return idx; 
                }
                idx++; 
            }
        }
        return -1;
    }
};
