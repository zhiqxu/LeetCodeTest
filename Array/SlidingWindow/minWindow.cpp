/*
 * 给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。
 *
 * 注意：
 * 对于 t 中重复字符，我们寻找的子字符串中该字符数量必须不少于 t 中该字符数量。
 * 如果 s 中存在这样的子串，我们保证它是唯一的答案。
 *
 * 示例 1：
 * 输入：s = "ADOBECODEBANC", t = "ABC"
 * 输出："BANC"
 * 解释：最小覆盖子串 "BANC" 包含来自字符串 t 的 'A'、'B' 和 'C'。
 *
 * 示例 2：
 * 输入：s = "a", t = "a"
 * 输出："a"
 * 解释：整个字符串 s 是最小覆盖子串。
 *
 * 示例 3:
 * 输入: s = "a", t = "aa"
 * 输出: ""
 * 解释: t 中两个字符 'a' 均应包含在 s 的子串中，因此没有符合条件的子字符串，返回空字符串。
 *
 * LeetCode NO.76 最小覆盖子串
 * 
 */ 

#include <iostream>
#include <string>
#include <unordered_map>
#include <climits>

using namespace std;

class Solution{
public:
    // 滑动窗口：
    // 在滑动窗口类型的问题中都会有两个指针，一个用于「延伸」现有窗口的 r 指针，和一个用于「收缩」窗口的 l 指针。
    // 在任意时刻，只有一个指针运动，而另一个保持静止。我们在 s 上滑动窗口，通过移动 r 指针不断扩张窗口。
    // 当窗口包含 t 全部所需的字符后，如果能收缩，我们就收缩窗口直到得到最小窗口。
    // 可以用一个哈希表表示 t 中所有的字符以及它们的个数，用一个哈希表动态维护窗口中所有的字符以及它们的个数，如果这个动态表中包含 t 的哈希表中的所有字符，
    // 并且对应的个数都不小于 t 的哈希表中各个字符的个数，那么当前的窗口是「可行」的。
    unordered_map<char, int> ori, cnt;

    bool check(){
        for(const auto &p: ori){
            if(cnt[p.first] < p.second){
                return false;
            }
        }
            return true;
    }
    string minWindow(string s, string t){
        for(const auto &c: t){
            ++ori[c];
        }

        int l = 0, r = -1;
        int len = INT_MAX, ansL = -1, ansR = -1;

        while(r < int(s.size())){
            if(ori.find(s[++r]) != ori.end()){
                ++cnt[s[r]];
            }
            while(check() && l <= r){
                if(r - l + 1 < len){
                    len = r - l + 1;
                    ansL = l;
                }
                if(ori.find(s[l]) != ori.end()){
                    --cnt[s[l]];
                }
                ++l;
            }
        }
        return ansL == -1 ? string() : s.substr(ansL, len);
    }
};
