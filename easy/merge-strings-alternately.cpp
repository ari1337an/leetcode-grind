// https://leetcode.com/problems/merge-strings-alternately/
// Difficulty: Easy
// Tags: Two Pointers, String
// Time Complexity: O(n + m), where n = word1's length and m = word2's length
// Space Complexity: O(n + m)
// Approach:
//   - Iterate both strings character by character
//   - Add one character from each string alternately
//   - Append remaining characters from the longer string
//
// Personal note: I need to improve myself by not only relying on for loops. 
// I also need to refresh my memories of using substr instead of looping over
// it myself to append the strings.

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result = "";
        int i = 0;

        // Merge characters alternately
        while (i < word1.size() && i < word2.size()) {
            result += word1[i];
            result += word2[i];
            i++;
        }

        // Append remaining characters from the longer string
        result += word1.substr(i);
        result += word2.substr(i);

        return result;
    }
};
