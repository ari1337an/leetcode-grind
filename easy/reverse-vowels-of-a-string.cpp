// https://leetcode.com/problems/reverse-vowels-of-a-string/
// Difficulty: Easy
// Tags: Two Pointers, String
// Time Complexity: O(n), where n = s.size()
//   - One pass to collect vowels, one pass to reconstruct string
// Space Complexity: O(k), where k = number of vowels
// 
// Approach:
// - Traverse the input string and collect all vowels into a vector `ch`.
// - Reverse the collected vowels to prepare for replacement.
// - Create a copy of the original string `res`.
// - Traverse `s` again, and for each vowel position, replace it in `res` with the reversed vowel from `ch`.
// - Helper function `isVowel(char)` checks lowercase and uppercase vowels.
//
// Notes:
// - This approach avoids in-place swaps and keeps code simple and readable.
// - Uses extra space proportional to the number of vowels, which is acceptable for Easy problems.
// - Case-insensitive handling is done via `tolower()` inside `isVowel()`.

class Solution {
public:
    string reverseVowels(string s) {
        vector<char> ch;
		for(int i = 0; i < s.size(); i++) {
			if(isVowel(s[i])) {
				ch.push_back(s[i]);
			}
		}
		reverse(ch.begin(), ch.end());
		string res = s;
		int j = 0;
		for(int i = 0; i < s.size(); i++){
			if(isVowel(s[i])){
				res[i] = ch[j++];
			}
		}
		return res;
    }
	bool isVowel(char cc){
		char c = tolower(cc);
		return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
	}
};