/*
 * 在排序数组中查找元素的第一个和最后一个位置
 *
 * 给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。请你找出给定目标值在数组中的开始位置和结束位置。
 * 如果数组中不存在目标值 target，返回 [-1, -1]。
 * 你必须设计并实现时间复杂度为 O(log n) 的算法解决此问题。
 *
 * 示例1：
 * 输入：nums = [5,7,7,8,8,10], target = 8
 * 输出：[3,4]
 *
 * 示例2：
 * 输入：nums = [5,7,7,8,8,10], target = 6
 * 输出：[-1,-1]
 *
 * 示例3：
 * 输入：nums = [], target = 0
 * 输出：[-1,-1]
 *
 * LeetCode NO.34
 *
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    // 情况一：target在数组范围的右边或左边，例如数组[3,4,5]，target为2，或者数组[3,4,5]，target为6，此时应该返回{-1,-1}
    // 情况二：target在数组范围中，且数组中不存在target，例如数组[3,6,7]，target为5，此时应该返回{-1,-1}
    // 情况三：target在数组范围中，且数组存在target，例如数组[3,6,7]，target为6，此时应该返回{1,1}
    vector<int> searchRange(vector<int> &nums, int target){
        int leftborder = getLeftborder(nums, target);
        int rightborder = getRightborder(nums, target);

        // 情况一
        if(leftborder == -2 || rightborder == -2) return {-1, -1};
        // 情况三
        if(rightborder - leftborder > 1) return {leftborder + 1, rightborder - 1};
        // 情况二
        return {-1, -1};
    }
private:
    // 处理左边界
    // 二分查找，寻找target的左边界leftborder（不包括target）
    // 如果leftborder没有被赋值（即target在数组范围的右边，例如[3,3]，target为4，为了处理情况一）
    int getLeftborder(vector<int> &nums, int target){
        int left = 0;
        int right = nums.size() - 1;
        int leftborder = -2; // 记录一下leftborder没有被赋值的情况

        while(left <= right){
            int middle = left + ((right - left)) / 2;
            if(nums[middle] >= target){ // 寻找左边界，就要在nums[middle] == target的时候更新right
                right = middle - 1;
                leftborder = right;
            }else{
                left = middle + 1;
            }
        }
        return leftborder;
    }

    // 寻找右边界
    // 二分查找，寻找target的右边界（不包括target）
    // 如果rightborder没有被赋值（即target在数组范围的左边，例如数组[3,3]，target为2），为了处理情况一
    int getRightborder(vector<int> &nums, int target){
        int left = 0;
        int right = nums.size() - 1;
        int rightborder = -2; // 记录一下rightborder没有被赋值的情况

        while(left <= right){
            int middle = left + ((right - left)) / 2;
            if(nums[middle] > target){
                right = middle - 1; // target在左区间，所以[left, middle - 1]
            }else{ // 当nums[middle] == target的时候，更新left，这样才能得到target的右边界
                left = middle + 1;
                rightborder = left;
            }
        }
        return rightborder;
    }
};
