/*
 * LeetCode NO.977 有序数组的平方
 *
 * 给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。
 *
 * 示例 1：
 * 输入：nums = [-4,-1,0,3,10]
 * 输出：[0,1,9,16,100]
 * 解释：平方后，数组变为 [16,1,0,9,100]
 * 排序后，数组变为 [0,1,9,16,100]
 *
 * 示例 2：
 * 输入：nums = [-7,-3,2,3,11]
 * 输出：[4,9,9,49,121]
 *
 */ 

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    // 方法一：直接排序，将数组nums中的数平方后直接排序
    vector<int> sortedSquares(vector<int> &nums){
        vector<int> ans;
        for(int num : nums){
            ans.push_back(num*num);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }

    // 方法二：双指针
    // 找出分界线，分为两个子数组，一个升序，一个降序，最后使用归并排序
    vector<int> sortedSquares2(vector<int> &nums){
        int n = nums.size();
        int negative = -1;
        for(int i = 0; i < n; i++){
            if(nums[i] < 0){
                negative = i;
            }else{
                break;
            }
        }

        vector<int> ans;
        int i = negative, j = negative + 1;
        while(i >= 0 || j < n){
            if(i < 0){
                ans.push_back(nums[j] * nums[j]);
                ++j;
            }
            else if(j == n){
                ans.push_back(nums[i] * nums[i]);
                --i;
            }
            else if(nums[i] * nums[i] < nums[j] * nums[j]){
                ans.push_back(nums[i] * nums[i]);
                --i;
            }
            else{
                ans.push_back(nums[j] * nums[j]);
                ++j;
            }
        }
        return ans;
    }

    // 方法三：双指针
    // 同样地，我们可以使用两个指针分别指向位置 0 和 n−1，每次比较两个指针对应的数，选择较大的那个逆序放入答案并移动指针。
    // 这种方法无需处理某一指针移动至边界的情况。
    vector<int> sortedSquares3(vector<int> &nums){
        int n = nums.size();
        int l = 0, r = n - 1, pos = n - 1;

        vector<int> ans(n);
        while(l <= r){
            if(nums[l] * nums[l] < nums[r] * nums[r]){
                ans[pos] = nums[r] * nums[r];
                r--;
            }else{
                ans[pos] = nums[l] * nums[l];
                l++;
            }
            pos--;
        }
        return ans;

    }
};
