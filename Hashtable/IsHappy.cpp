/**
 * LeetCode NO.202 快乐数：简单
 *
 * 编写一个算法来判断一个数 n 是不是快乐数。
 * 「快乐数」 定义为：
 * 对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
 * 然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
 * 如果这个过程 结果为 1，那么这个数就是快乐数。
 * 如果 n 是 快乐数 就返回 true ；不是，则返回 false 。
 *
 * 示例 1：
 * 输入：n = 19
 * 输出：true
 * 解释：
 * 1^2 + 9^2 = 82
 * 8^2 + 2^2 = 68
 * 6^2 + 8^2 = 100
 * 1^2 + 0^2 + 0^2 = 1
 *
 * 示例 2：
 * 输入：n = 2
 * 输出：false
 * 
 * 题目中说了会 无限循环，那么也就是说求和的过程中，sum会重复出现，这对解题很重要！
 * 当我们遇到了要快速判断一个元素是否出现集合里的时候，就要考虑哈希法了。
 * 这道题目使用哈希法，来判断这个sum是否重复出现，如果重复了就是return false， 否则一直找到sum为1为止。
 * 判断sum是否重复出现就可以使用unordered_set。
 *
 */ 

#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int getSum(int n){
        int sum = 0;
        while(n){
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int> set;
        while(1){
            int sum = getSum(n);
            if(sum == 1){
                return true;
            }
            if(set.find(sum) != set.end()){
                return false;
            }else{
                set.emplace(sum);
            }
            n = sum;
        }
    }
};
