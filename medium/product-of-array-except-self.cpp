// https://leetcode.com/problems/product-of-array-except-self/
// Difficulty: Medium
// Tags: Array, Prefix Product
// Time Complexity: O(n), where n = nums.size()
// Space Complexity: O(n) for the result vector, ignoring output space it's O(1)
// 
// Approach:
// - Calculate the product of all elements (p) and count zeros in the array (cnt0).
// - Track position of the single zero (lastPos) and product of all non-zero elements (p0).
// - If there are no zeros (cnt0 == 0):
//     - For each index, answer is total product divided by nums[i].
// - If there is exactly one zero:
//     - Result is zero everywhere except at the zero's position, where the product is p0.
// - If there are more than one zero:
//     - Result is all zeros since any product excluding an element includes at least one zero.
//
// Note:
// - This approach uses division which is acceptable here because constraints guarantee no division by zero except handled by zero count logic.
// - For division-free solution, prefix and suffix products can be used instead.

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int p = 1, cnt0 = 0, lastPos = -1, p0 = 1;
		for(int i = 0; i < nums.size(); i++){
			p *= nums[i];
			cnt0 += (nums[i] == 0);
			if(nums[i] == 0)lastPos = i;
			p0 = (nums[i] == 0) ? p0*1 : p0*nums[i];
		}
		if(cnt0 == 0){
			vector<int> result;
			for(int i = 0; i < nums.size(); i++) {
				result.push_back(p/nums[i]);
			}
			return result;
		}else if(cnt0 == 1){
			vector<int> result(nums.size(), 0);
			result[lastPos] = p0;
			return result;
		}else{
			return vector<int>(nums.size(), 0);
		}
    }
};