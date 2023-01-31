//
// Created by AILEE on 2023/1/31.
// 题目23：链表中环的入口
// 题目：如果一个链表中包含环，如何让找出环的入口节点。
//

#include "LinkedList.h"

#include <iostream>
#include <vector>

/**
 * @brief 利用快慢指针判断是否包含环。
 * @param pHead the head pointer of list
 * @return if have a loop in list return the meeting node, else return nullptr.
 */
ailee::ListNode *MeetingNode(ailee::ListNode *pHead) {

}

ailee::ListNode *EntryNodeInListLoop(ailee::ListNode *pHead) {
    // check input data.
    if (pHead == nullptr) {
        return nullptr;
    }

    ailee::ListNode *pNodeInLoop = MeetingNode(pHead);
}

void test(const char *testName, ailee::ListNode *pHead) {
    ;
}

/**
 * @brief 链表只有一个节点，无环。
 */
void test_01() {
    ailee::ListNode *pNode1 = ailee::LinkedList::CreateListNode(1);

    test("test 01", pNode1);
}

/**
 * @brief 链表只有一个节点，且自环。
 */
void test_02() {
    ailee::ListNode *pNode1 = ailee::LinkedList::CreateListNode(1);
    ailee::LinkedList::ConnectListNodes(pNode1, pNode1);

    test("test 02", pNode1);
}

/**
 * @brief 链表有多个节点，且首尾相连。
 */
void test_03() {
    ailee::ListNode *pNode1 = ailee::LinkedList::CreateListNode(1);
    ailee::ListNode *pNode2 = ailee::LinkedList::CreateListNode(2);
    ailee::ListNode *pNode3 = ailee::LinkedList::CreateListNode(3);
    ailee::ListNode *pNode4 = ailee::LinkedList::CreateListNode(4);
    ailee::ListNode *pNode5 = ailee::LinkedList::CreateListNode(5);

    ailee::LinkedList::ConnectListNodes(pNode1, pNode2);
    ailee::LinkedList::ConnectListNodes(pNode2, pNode3);
    ailee::LinkedList::ConnectListNodes(pNode3, pNode4);
    ailee::LinkedList::ConnectListNodes(pNode4, pNode5);
    ailee::LinkedList::ConnectListNodes(pNode5, pNode1);

    test("test 03", pNode1);
}

/**
 * @brief 链表有多个节点，有一个环。
 */
void test_04() {
    ailee::ListNode *pNode1 = ailee::LinkedList::CreateListNode(1);
    ailee::ListNode *pNode2 = ailee::LinkedList::CreateListNode(2);
    ailee::ListNode *pNode3 = ailee::LinkedList::CreateListNode(3);
    ailee::ListNode *pNode4 = ailee::LinkedList::CreateListNode(4);
    ailee::ListNode *pNode5 = ailee::LinkedList::CreateListNode(5);

    ailee::LinkedList::ConnectListNodes(pNode1, pNode2);
    ailee::LinkedList::ConnectListNodes(pNode2, pNode3);
    ailee::LinkedList::ConnectListNodes(pNode3, pNode4);
    ailee::LinkedList::ConnectListNodes(pNode4, pNode5);
    ailee::LinkedList::ConnectListNodes(pNode5, pNode3);

    test("test 04", pNode1);
}

/**
 * @brief 链表有多个节点，且尾节点自环。
 */
void test_05() {
    ailee::ListNode *pNode1 = ailee::LinkedList::CreateListNode(1);
    ailee::ListNode *pNode2 = ailee::LinkedList::CreateListNode(2);
    ailee::ListNode *pNode3 = ailee::LinkedList::CreateListNode(3);
    ailee::ListNode *pNode4 = ailee::LinkedList::CreateListNode(4);
    ailee::ListNode *pNode5 = ailee::LinkedList::CreateListNode(5);

    ailee::LinkedList::ConnectListNodes(pNode1, pNode2);
    ailee::LinkedList::ConnectListNodes(pNode2, pNode3);
    ailee::LinkedList::ConnectListNodes(pNode3, pNode4);
    ailee::LinkedList::ConnectListNodes(pNode4, pNode5);
    ailee::LinkedList::ConnectListNodes(pNode5, pNode5);

    test("test 05", pNode1);
}

/**
 * @brief 链表有多个节点，其无环。
 */
void test_06() {
    ailee::ListNode *pNode1 = ailee::LinkedList::CreateListNode(1);
    ailee::ListNode *pNode2 = ailee::LinkedList::CreateListNode(2);
    ailee::ListNode *pNode3 = ailee::LinkedList::CreateListNode(3);
    ailee::ListNode *pNode4 = ailee::LinkedList::CreateListNode(4);
    ailee::ListNode *pNode5 = ailee::LinkedList::CreateListNode(5);

    ailee::LinkedList::ConnectListNodes(pNode1, pNode2);
    ailee::LinkedList::ConnectListNodes(pNode2, pNode3);
    ailee::LinkedList::ConnectListNodes(pNode3, pNode4);
    ailee::LinkedList::ConnectListNodes(pNode4, pNode5);

    test("test 06", pNode1);
}

/**
 * @brief 空链表
 */
void test_07() {
    test("test 07", nullptr);
}

int main(int argc, char **argv) {
    return 0;
}
