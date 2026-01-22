/*
LeetCode Daily Challenge
Date: 22 Jan 2026
Problem: 3507. Minimum Pair Removal to Sort Array I

Problem Summary:
You can repeatedly merge the adjacent pair with the minimum sum.
If multiple pairs have the same minimum sum, choose the leftmost one.
Each merge replaces the pair with their sum.

Goal:
Return the minimum number of operations required to make the array non-decreasing.

Approach:
- While the array is not non-decreasing:
    1. Find the adjacent pair with the minimum sum
    2. Merge that pair
    3. Count the operation
- Stop once the array becomes sorted

Why this works:
The problem strictly defines which pair must be chosen at every step
(minimum adjacent sum, leftmost if tie), so simulation is sufficient.

Time Complexity:
O(n^2)
- At most n merges
- Each merge scans the array

Space Complexity:
O(1) extra space (in-place modifications)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getMinPairIndex(vector<int>& nums) {
        int minSum = INT_MAX;
        int index = 0;

        for (int i = 0; i < nums.size() - 1; i++) {
            int currSum = nums[i] + nums[i + 1];
            if (currSum < minSum) {
                minSum = currSum;
                index = i;
            }
        }
        return index;
    }

    int minimumPairRemoval(vector<int>& nums) {
        int operations = 0;

        while (!is_sorted(nums.begin(), nums.end())) {
            int idx = getMinPairIndex(nums);

            nums[idx] = nums[idx] + nums[idx + 1];
            nums.erase(nums.begin() + idx + 1);

            operations++;
        }

        return operations;
    }
};
