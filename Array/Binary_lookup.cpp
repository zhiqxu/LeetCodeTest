/*
 * 给定一个n个元素有序的（升序）整型数组nums和一个目标值target，
 * 写一个函数搜索nums中的target，如果目标存在返回下标，否则返回-1.
 *
 * 示例：
 * 输入：nums = [-1, 0, 3, 5, 9, 12], target = 9
 * 输出: 4
 * 解释: 9 出现在 nums 中并且下标为 4
 *
 * 提示：
 * 你可以假设 nums 中的所有元素是不重复的。
 * n 将在 [1, 10000]之间。
 * nums 的每个元素都将在 [-9999, 9999]之间。
 *
 * LeetCode:704
 *
 */

//版本一：左闭右闭区间
#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int search(vector<int> &nums, int target){
        int left = 0;
        int right = nums.size() - 1; // 定义target在左闭右闭的区间里，[left,right] 

        while(left <= right){ // 当left==right，区间[left, right]依然有效，所以用<=
            int middle = left + ((right - left) / 2); // 防止溢出 等同于(left + right) / 2
            if(nums[middle] > target)
                right = middle - 1; // target在左区间，所以[left, middle - 1]
            else if(nums[middle] < target)
                left = middle + 1; // target在右区间，所以[middle + 1, right]
            else // nums[middle] == target 
                return middle; // 数组中找到目标值，直接返回下标
        }
        // 未找到目标值
        return -1;
    }
};

//版本二：左闭右开区间

class Solution2{
public:
    int search(vector<int> &nums, int target){
        int left = 0;
        int right = nums.size(); // 定义target在左闭右开的区间里，[left,right) 

        while(left < right){ // 因为left == right的时候，在[left, right)是无效的空间，所以使用<
            int middle = left + ((right - left) / 2); // 防止溢出 等同于(left + right) / 2
            if(nums[middle] > target)
                right = middle - 1; // target在左区间，所以[left, middle)
            else if(nums[middle] < target)
                left = middle + 1; // target在右区间，所以[middle + 1, right)
            else // nums[middle] == target 
                return middle; // 数组中找到目标值，直接返回下标
        }
        // 未找到目标值
        return -1;
    }
};
