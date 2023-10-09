/**
 * LeetCode NO.1002 查找共用字符：简单
 * 给你一个字符串数组 words ，请你找出所有在 words 的每个字符串中都出现的共用字符（ 包括重复字符），并以数组形式返回。你可以按 任意顺序 返回答案。
 *
 * 示例 1：
 * 输入：words = ["bella","label","roller"]
 * 输出：["e","l","l"]
 *
 * 示例 2：
 * 输入：words = ["cool","lock","cook"]
 * 输出：["c","o"]
 *
 */ 

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> res;
        if(words.size() == 0){
            return res;
        }
        int hash[26] = {0};
        for(int i = 0; i < words[0].size(); ++i){
            hash[words[0][i] - 'a']++;
        }
        int hashotherstr[26] = {0};
        for(int i = 1; i < words.size(); ++i){
            memset(hashotherstr, 0, 26 * sizeof(int));
            for(int j = 0; j < words[i].size(); ++j){
                hashotherstr[words[i][j] - 'a']++;
            }
            for(int k = 0; k < 26; ++k){
                hash[k] = min(hash[k], hashotherstr[k]);
            }
        }
        for(int i = 0; i < 26; i++){
            while(hash[i] != 0){
                string s(1, i + 'a');
                res.push_back(s);
                hash[i]--;
            }
        }
        return res;
    }
};
