/*
 * LeetCode NO.283 移动零
 *
 * 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
 * 请注意 ，必须在不复制数组的情况下原地对数组进行操作。
 *
 * 示例 1:
 * 输入: nums = [0,1,0,3,12]
 * 输出: [1,3,12,0,0]
 *
 * 示例 2:
 * 输入: nums = [0]
 * 输出: [0]
 *
 */ 

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    void moveZeroes(vector<int>& nums){
        int n = nums.size();
        int slow = 0;
        for(int fast = 0; fast < n; fast++){
            if(0 != nums[fast]){
                swap(nums[slow], nums[fast]); //不能使用异或的方式交换，当两个变量值相同时，异或运算后就全变为0了
                slow++;
            }
        }    
    }
};
