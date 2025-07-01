// https://leetcode.com/problems/string-compression/
// Difficulty: Medium
// Tags: Two Pointers, String
// Time Complexity: O(n), where n = chars.size()
//   - Each character is processed once
// Space Complexity: O(1) extra (ignoring output written in-place)
// 
// Approach:
// - Append a sentinel character (`'\0'`) at the end to simplify group detection.
// - Traverse the input with a single pass, grouping identical characters.
// - For each group:
//     - Write the character once to the `chars` array
//     - If the group length > 1, convert the count to string and write each digit.
// - Handle both single and multi-digit counts explicitly.
// - Use `j` to write compressed output in-place from the start of the array.
// - Finally, truncate the `chars` array to size `j` and return the new length.
//
// Notes:
// - The use of sentinel eliminates edge-case handling for the last group.
// - Manual ASCII conversion via `char(groupLength + 48)` is optimized for groupLength < 10.
// - This approach satisfies the problem constraint: in-place modification with O(1) space.

class Solution {
public:
    int compress(vector<char>& chars) {
		chars.push_back('\0');
		char curGroup = chars[0];
		int groupLength = 1;
		int j = 0;
		string conv;
		for(int i = 1; i < chars.size(); i++){
			if(chars[i] == curGroup){
				groupLength++;
			}else{
				chars[j++] = curGroup;
				if(groupLength != 1) {
					if(groupLength >= 10){
						conv = to_string(groupLength);
						for(char c: conv) chars[j++] = c;
					}else chars[j++] = char(groupLength+48);
				}
				groupLength = 1;
				curGroup = chars[i];
			}
		}
		while(chars.size() > j){
			chars.pop_back();
		}
		return chars.size();
    }
};