/**
 * LeetCode 面试题02.07. 链表相交：简单
 *
 * 给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表没有交点，返回 null 。
 *
 */ 
#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(nullptr){}
};

class Solution{
public:
    ListNode * getIntersectionNode(ListNode *headA, ListNode *headB){
        ListNode *curA = headA;
        ListNode *curB = headB;
        int lenA = 0, lenB = 0;
        while(curA != nullptr){
            // 求链表A的长度
            lenA++;
            curA = curA->next;
        }
        while(curB != nullptr){
            // 求链表B的长度
            lenB++;
            curB = curB->next;
        }
        curA = headA;
        curB = headB;
        // 让curA为最长链表的头，lenA为其长度
        if(lenB > lenA){
            swap(lenA, lenB);
            swap(curA, curB);
        }
        int gap = lenA - lenB;
        // 让curA与curB在同一起点上（末尾位置对齐）
        while(gap--){
            curA = curA->next;
        }
        // 遍历curA和curB，遇到相同值则直接返回
        while(curA != nullptr){
            if(curA == curB){
                return curA;
            }
            curA = curA->next;
            curB = curB->next;
        }
        return nullptr;
    }
};
