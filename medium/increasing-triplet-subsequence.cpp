// https://leetcode.com/problems/increasing-triplet-subsequence/
// Difficulty: Medium
// Tags: Array, Greedy, Prefix Min, Suffix Max
// Time Complexity: O(n), where n = nums.size()
// Space Complexity: O(n) for prefix/suffix arrays
//
// Approach:
// - The goal is to find any increasing triplet (i < j < k) such that nums[i] < nums[j] < nums[k].
// - We build two auxiliary arrays:
//     - mins[i]: the minimum value in nums[0..i]
//     - maxs[i]: the maximum value in nums[i..n-1]
// - In one pass from both ends, fill mins[] and maxs[] using current min and max.
// - Then iterate through each index `j` as the middle of a triplet,
//     and check if there exists a valid `i < j < k` with nums[i] < nums[j] < nums[k].
// - If any such `j` satisfies the condition, return true; otherwise, return false.
// 
// Notes:
// - This is not the most space-optimal solution (there exists O(1) space variant), 
//   but it's clear, correct, and runs in linear time.
// - Using prefix and suffix arrays provides strong intuition around subarray constraints.

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> mins(nums.size(), INT_MAX); // prefix min, this will select the a[i]
		vector<int> maxs(nums.size(), INT_MIN); // suffix max, this will select the a[k];
		int curMin = INT_MAX, curMax = INT_MIN;
		for(int i = 0, j = nums.size()-1; i < nums.size(); i++, j--){ // O(N)
			curMin = min(curMin, nums[i]);
			curMax = max(curMax, nums[j]);
			mins[i] = curMin, maxs[j] = curMax;
		}

		// for each a[j] iteration, find left minimum and right maximum and check the invariant of the problem
		for(int jI = 1; jI < nums.size()-1; jI++){ // O(N)
			int i = mins[jI-1];
			int j = nums[jI];
			int k = maxs[jI+1];
			if(i < j && j < k) return true;
		}
		return false;
    }
};