/**
 * LeetCode NO.349 两个数组的交集：简单
 *
 * 给定两个数组 nums1 和 nums2 ，返回 它们的交集 。输出结果中的每个元素一定是 唯一 的。我们可以 不考虑输出结果的顺序 。
 *
 * 示例 1：
 * 输入：nums1 = [1,2,2,1], nums2 = [2,2]输入：nums1 = [1,2,2,1], nums2 = [2,2]
 * 输出：[2]
 *
 * 示例 2：
 * 输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * 输出：[9,4]
 * 解释：[4,9] 也是可通过的
 *
 */ 

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution{
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2){
        unordered_set<int> res;
        unordered_set<int> numset(nums1.begin(), nums1.end());
        for(int num : nums2){
            if(numset.find(num) != numset.end()){
                res.emplace(num);
            }
        }
        return vector<int>(res.begin(), res.end());
    }
};
