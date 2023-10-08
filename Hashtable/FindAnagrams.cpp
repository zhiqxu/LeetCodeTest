/**
 * LeetCode NO.438 找到字符中所有字母异位词：中等
 *
 * 给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。
 * 异位词 指由相同字母重排列形成的字符串（包括相同的字符串）。
 *
 * 示例 1:
 * 输入: s = "cbaebabacd", p = "abc"
 * 输出: [0,6]
 * 解释:
 * 起始索引等于 0 的子串是 "cba", 它是 "abc" 的异位词。
 * 起始索引等于 6 的子串是 "bac", 它是 "abc" 的异位词。
 *
 * 示例 2:
 * 输入: s = "abab", p = "ab"
 * 输出: [0,1,2]
 * 解释:
 * 起始索引等于 0 的子串是 "ab", 它是 "ab" 的异位词。
 * 起始索引等于 1 的子串是 "ba", 它是 "ab" 的异位词。
 * 起始索引等于 2 的子串是 "ab", 它是 "ab" 的异位词。
 *
 */ 

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    vector<int> findAnagrams(string s, string p){
        int sLen = s.size(), pLen = p.size();

        if(sLen < pLen){
            return vector<int>();
        }

        vector<int> ans;
        vector<int> sCount(26);
        vector<int> pCount(26);

        for(int i = 0; i < pLen; ++i){
            ++sCount[s[i] - 'a'];
            ++pCount[p[i] - 'a'];
        }
        if(sCount == pCount){
            ans.emplace_back(0);
        }

        for(int i = 0; i < sLen - pLen; ++i){
            --sCount[s[i] - 'a'];
            ++sCount[s[i + pLen] - 'a'];

            if(sCount == pCount){
                ans.emplace_back(i + 1);
            }
        }

        return ans;
    }
};
