/**
 * LeetCode NO.19 删除链表的倒数第N个节点：中等
 *
 * 给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
 *
 * 示例 1：
 * 输入：head = [1,2,3,4,5], n = 2
 * 输出：[1,2,3,5]
 *
 * 示例 2：
 * 输入：head = [1], n = 1
 * 输出：[]
 *
 * 示例 3：
 * 输入：head = [1,2], n = 1
 * 输出：[1]
 *
 */ 

#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr){}
    ListNode(int val): val(val), next(nullptr){}
    ListNode(int val, ListNode *next): val(val), next(nullptr){}
};

class Solution{
    ListNode * removeNthFromEnd(ListNode *head, int n){
        ListNode *dummyHead = new ListNode();
        dummyHead->next = head;
        ListNode *slow = dummyHead;
        ListNode *fast = dummyHead;

        while(n-- && fast != nullptr){
            fast = fast->next;
        }
        fast = fast->next; // fast再往前走一步，因为需要让slow指向删除节点的上一个节点
        while(fast != nullptr){
            fast = fast->next;
            slow = slow->next;
        }

        ListNode *tmp = slow->next;
        slow->next = tmp->next;
        delete tmp;

        return dummyHead->next;
    }
};
