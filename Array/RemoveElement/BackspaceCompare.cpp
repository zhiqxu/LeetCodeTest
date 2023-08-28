/*
 * LeetCode NO.844 比较含退格的字符串
 *
 * 给定 s 和 t 两个字符串，当它们分别被输入到空白的文本编辑器后，如果两者相等，返回 true 。# 代表退格字符。
 * 注意：如果对空文本输入退格字符，文本继续为空。
 *
 * 示例 1：
 * 输入：s = "ab#c", t = "ad#c"
 * 输出：true
 * 解释：s 和 t 都会变成 "ac"。
 *
 * 示例 2：
 * 输入：s = "ab##", t = "c#d#"
 * 输出：true
 * 解释：s 和 t 都会变成 ""。
 *
 * 示例 3：
 * 输入：s = "a#c", t = "b"
 * 输出：false
 * 解释：s 会变成 "c"，但 t 仍然是 "b"。
 *
 */ 

#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution{
public:
    // 自写————用栈实现，内存消耗大
    bool backspaceCompare(string s, string t){
        stack<char> temp1;
        stack<char> temp2;
        for(int i = 0; i < s.size(); i++){
            if(s[i] != '#'){
                temp1.push(s[i]);
            }else{
                if(temp1.size()>0)
                    temp1.pop();
            }
        }
        for(int i = 0; i < t.size(); i++){
            if(t[i] != '#'){
                temp2.push(t[i]);
            }else{
                if(temp2.size() > 0)
                    temp2.pop();
            }
        }
        if(temp1 == temp2) return true;
        else return false;
    }

    // 双指针————一个字符是否会被删掉，只取决于该字符后面的退格符，而与该字符前面的退格符无关。
    // 因此当我们逆序地遍历字符串，就可以立即确定当前字符是否会被删掉。
    bool backspaceCompare2(string s, string t){
        int ls = traverse(s);
        int lt = traverse(t);
        if(ls != lt) return false;
        return s.substr(0, ls) == t.substr(0, ls);    
    }
    int traverse(string &s){
        int left = 0, right = 0;
        int l = s.length();
        while(right < l){
            if(s[right] == '#'){
                left--;
            }else{
                s[left] = s[right];
                left++;
            }
            right++;
            if(left < 0) left = 0;
        }
        return left;
    }
};
