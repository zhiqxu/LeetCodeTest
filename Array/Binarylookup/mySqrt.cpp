/*
 * x的平方根 LeetCode NO.69
 *
 * 给你一个非负整数x，计算并返回x的算数平方根。
 * 由于返回类型是整数，结果只保留整数部分，小数部分将被舍去。
 *
 * 注意：不允许使用任何内置指数函数和算符，例如pow(x, 0.5)或者x ** 0.5。
 *
 * 示例1：
 * 输入：x = 4
 * 输出：2
 *
 * 示例2：
 * 输入：x = 8
 * 输出：2
 * 解释：8 的算术平方根是 2.82842..., 由于返回类型是整数，小数部分将被舍去。
 *
 */ 

// 二分查找
#include <iostream>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        // 不用申请数组，int类型计算后是取整
        int left = 0;
        int right = x;
        int middle;
        while(left <= right){
            middle = left + ((right - left)) / 2;
            if((long long)middle * middle > x){ // 需要进行类型转换，否则容易出现内存溢出
                right = middle - 1;
            }
            else if((long long)middle * middle < x){
                left = middle + 1;
            }
            else
                return middle;
        }

        return right;
    }
};
