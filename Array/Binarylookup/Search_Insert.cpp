/*
 * 搜索插入位置：LeetCode 35
 *
 * 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。
 * 如果目标值不存在数组中，返回它将会被按顺序插入的位置。
 *
 * 必须使用时间复杂度为O(logn)的算法。
 *
 * 示例1：
 * 输入：nums = [1,3,5,6], target = 5
 * 输出：2
 *
 * 示例2：
 * 输入: nums = [1,3,5,6], target = 2
 * 输出: 1
 *
 * 示例3：
 * 输入：nums = [1,3,5,6], target = 7
 * 输出: 4
 *
 */ 

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    // 第一种：暴力解法
    // 时间复杂度O(n)，空间复杂度O(1)
    int searchInsert1(vector<int> &nums, int target){
        for(int i = 0; i < nums.size(); i++){
            // 分别处理如下三种情况
            // 目标值比所有元素都小
            // 目标值等于数组中某一元素
            // 目标值插入数组中的位置
            if(nums[i] >= target){
                return i; // 一旦发现大于或等于target的nums[i]，那么i就是我们要的结果
            }
        }
        // 目标值比所有元素都大的情况
        return nums.size(); // 如果target是最大的，或者nums为空，则返回nums的长度
    }
    // 第二种：二分法（左闭右闭）
    // 时间复杂度O(logn)，空间复杂度O(1)
    int searchInsert2(vector<int> &nums, int target){
        int left = 0;
        int right = nums.size() - 1;
        int middle;
        while(left <= right){
            middle = left + ((right - left)) / 2;
            if(nums[middle] > target)
                right = middle - 1;
            else if(nums[middle] < target)
                left = middle + 1;
            else 
                return middle;
        }
        /* 原来自己写的
        if(middle == left && middle == 0)
            return 0;
        else if(middle == right)
            return middle + 1;
        else
            return middle;
        */ 

        // 分别处理如下四种情况
        // 目标值比所有元素都小 [0, -1]
        // 目标值等于数组中的某一元素 return middle
        // 目标值插入数组中的位置[left, right]，return right + 1
        // 目标值比数组所有元素都大，因为是右闭区间，所以return right + 1
        return right + 1;
    }

    // 第三种：二分法（左闭右开）
    // 复杂度同上
    int searchInsert3(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n; // 定义target在左闭右开的区间里，[left, right)  target
        while (left < right) { // 因为left == right的时候，在[left, right)是无效的空间
            int middle = left + ((right - left) >> 1);
            if (nums[middle] > target) {
                right = middle; // target 在左区间，在[left, middle)中
            } else if (nums[middle] < target) {
                left = middle + 1; // target 在右区间，在 [middle+1, right)中
            } else { // nums[middle] == target
                return middle; // 数组中找到目标值的情况，直接返回下标
            }
        }
        // 分别处理如下四种情况
        // 目标值在数组所有元素之前 [0,0)
        // 目标值等于数组中某一个元素 return middle
        // 目标值插入数组中的位置 [left, right) ，return right 即可
        // 目标值在数组所有元素之后的情况 [left, right)，因为是右开区间，所以 return right
        return right;
    }
};
