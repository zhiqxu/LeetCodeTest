/*
 * LeetCode NO.209 长度最小的子数组
 *
 * 给定一个含有 n 个正整数的数组和一个正整数 target 。
 * 找出该数组中满足其和 ≥ target 的长度最小的 连续子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。
 *
 * 示例 1：
 * 输入：target = 7, nums = [2,3,1,2,4,3]
 * 输出：2
 * 解释：子数组 [4,3] 是该条件下的长度最小的子数组。
 *
 * 示例 2：
 * 输入：target = 4, nums = [1,4,4]
 * 输出：1
 *
 * 示例 3：
 * 输入：target = 11, nums = [1,1,1,1,1,1,1,1]
 * 输出：0
 *
 */ 

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    // 滑动窗口：通过不断地调节子序列的起始位置和终止位置，从而得出我们想要的结果。
    int minSubArrayLen(int target, vector<int> &nums){
        int n = nums.size();
        int val = 0; // 滑动窗口数值之和
        int subLen = 0; // 滑动窗口的长度
        int minLen = INT32_MAX;
        for(int i = 0, j = 0; j < n; j++){
            val += nums[j];
            // 注意这里使用while，每次更新 i（起始位置），并不断比较子序列是否符合条件
            while(val >= target){
                subLen = j - i + 1; // 取子序列的长度
                minLen = minLen < subLen ? minLen : subLen;
                val -= nums[i++]; // 这里体现出滑动窗口的精髓之处，不断变更i（子序列的起始位置）
            }
        }
        // 如果result没有被赋值的话，就返回0，说明没有符合条件的子序列
        return minLen == INT32_MAX ? 0 : minLen;
    }
};
