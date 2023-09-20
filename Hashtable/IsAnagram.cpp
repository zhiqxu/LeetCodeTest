/**
 * LeetCode NO.242 有效的字母异位词：简单
 *
 * 给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
 * 注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词。
 *
 * 示例 1:
 * 输入: s = "anagram", t = "nagaram"
 * 输出: true
 * 
 * 示例 2:
 * 输入: s = "rat", t = "car"
 * 输出: false
 * 
 */ 

#include <iostream>
#include <string>

using namespace std;

class Solution{
public:
    bool isAnagram(string s, string t){
        int record[26] = {0};
        for(int i = 0; i < s.size(); i++){
            // 并不需要记住a的ASCII码，只要求出一个相对值就可以了
            record[s[i] - 'a']++;
        }
        for(int i = 0; i < t.size(); i++){
            record[t[i] - 'a']--;
        }
        for(int i = 0; i < 26; i++){
            if(record[i] != 0){
                // record数组如果有的元素不为零，说明字符串s和t一定是谁多了字符或谁少了字符
                return false;
            }
        }
        return true;
    }
};
