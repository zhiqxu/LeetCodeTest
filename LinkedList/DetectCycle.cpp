/**
 * LeetCode NO.142 环形链表：中等
 *
 * 给定一个链表的头节点  head ，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
 *
 */ 

#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(nullptr){}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
            // 快慢指针相遇，此时从head和相遇点，同时查找直至相遇
            if(slow == fast){
                ListNode *index1 = fast;
                ListNode *index2 = head;
                while(index1 != index2){
                    index1 = index1->next;
                    index2 = index2->next;
                }
                return index2; // 返回环的入口
            }
        }
        return nullptr;
    }
};
