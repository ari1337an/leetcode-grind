// https://leetcode.com/problems/reverse-words-in-a-string/
// Difficulty: Medium
// Tags: String, Stack
// Time Complexity: O(L), where L = total length of the string
//   - Each character is visited once while parsing and once while building result
// Space Complexity: O(W), where W = number of words
//   - The stack stores each word separately, and result string takes up additional space
// Approach:
//   - Use a stringstream to split the input string `s` into words, skipping extra spaces
//   - Push each word onto a stack
//   - Pop words from the stack and join them with spaces to get the reversed sentence
//   - Ensures trimmed result with single spaces between words

class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        stack<string> sss;
        string word;

        // Split the string into words and push onto stack
        while (ss >> word) {
            sss.push(word);
        }

        // Build the reversed string
        string result = "";
        while (!sss.empty()) {
            result += sss.top();
            sss.pop();
            if (!sss.empty()) result += " ";
        }

        return result;
    }
};
