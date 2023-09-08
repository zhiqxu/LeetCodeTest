/**
 * LeetCode NO.203 移除链表元素 ：简单
 *
 * 给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点
 *
 * 示例 1：
 * 输入：head = [1,2,6,3,4,5,6], val = 6
 * 输出：[1,2,3,4,5]
 *
 * 示例 2：
 * 输入：head = [], val = 1
 * 输出：[]
 *
 * 示例 3：
 * 输入：head = [7,7,7,7], val = 7
 * 输出：[]
 *
 */ 

#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){}
    ListNode(int x) : val(x), next(nullptr){}
    ListNode(int x, ListNode *next) : val(x), next(next){}
};

class Solution{
public:
    ListNode * removeElements(ListNode *head, int val){
        // 第一种：设置虚拟头节点，保证对头节点与其他非头节点的操作逻辑相同，但最后返回时要记得返回虚拟头节点后一个节点
        ListNode *dummyHead = new ListNode(0, head);
        ListNode *cur = dummyHead;
        while(cur->next != nullptr){
            if(cur->next->val == val){
                ListNode *tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            }else{
                cur = cur->next;
            }
        }
        head = dummyHead->next;
        delete dummyHead;
        return head;
    }

    ListNode * removeElements2(ListNode *head, int val){
        // 不设置虚拟头节点，直接使用原来的链表来进行移除节点操作
        
        // 删除头节点
        while(head != nullptr && head->val == val){// 注意这里不是if
            ListNode *tmp = head;
            head = head->next;
            delete tmp;
        }

        // 删除非头节点
        ListNode *cur = head;
        while(cur != nullptr && cur->next != nullptr){
            if(cur->next->val == val){
                ListNode *tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            }else{
                cur = cur->next;
            }
        }
        return head;
    }
};
