//
// Created by AILEE on 2023/1/31.
// 题目23：链表中环的入口
// 题目：如果一个链表中包含环，如何让找出环的入口节点。
//

#include "LinkedList.h"

#include <iostream>
#include <vector>

/**
 * @brief 利用快慢指针判断是否包含环。当两个指针没有相遇时，链表没有包含环。
 * @param pHead the head pointer of list
 * @return if have a loop in list return the meeting node, else return nullptr.
 */
ailee::ListNode *MeetingNode(ailee::ListNode *pHead) {
    ailee::ListNode *pNodeStride1 = pHead->m_pNext;
    // 单节点无环
    if (pNodeStride1 == nullptr) {
        return nullptr;
    }

    ailee::ListNode *pNodeStride2 = pNodeStride1->m_pNext;
    while (pNodeStride1 != nullptr && pNodeStride2 != nullptr) {
        if (pNodeStride1->m_nValue == pNodeStride2->m_nValue) {
            return pNodeStride1;
        }

        pNodeStride1 = pNodeStride1->m_pNext;
        pNodeStride2 = pNodeStride2->m_pNext;
        if (pNodeStride2 != nullptr) {
            pNodeStride2 = pNodeStride2->m_pNext;
        }
    }
}

/**
 * @brief 统计环中包含的节点数量，当指针再次到达相同节点时，即为遍历一次环。
 * @param pNode the node pointer in list loop.
 * @return the number of node in list loop.
 */
int CounterNodeNumInLoop(ailee::ListNode *pNode) {
    ailee::ListNode *beginNode = pNode;
    int num = 1;
    ailee::ListNode *pLoopNode = pNode->m_pNext;
    while (pLoopNode->m_nValue != beginNode->m_nValue) {
        pLoopNode = pLoopNode->m_pNext;
        num++;
    }

    return num;
}

/**
 * @brief 利用快慢节点，指针1先走个节点，然后指针2从头开始遍历，与此同时指针1也遍历，直到两个指针相遇，相遇节点即为环的入口节点。
 * @param loopNodeNum the number of node in list loop.
 * @param pHead the head pointer of list.
 * @return the entry node of loop in list.
 */
ailee::ListNode *FindEntryNodeInListLoop(int loopNodeNum, ailee::ListNode *pHead) {
    ailee::ListNode *pNode1 = pHead;
    for (int i = 0; i < loopNodeNum; i++) {
        pNode1 = pNode1->m_pNext;
    }

    ailee::ListNode *pNode2 = pHead;
    while (pNode1->m_nValue != pNode2->m_nValue) {
        pNode1 = pNode1->m_pNext;
        pNode2 = pNode2->m_pNext;
    }

    return pNode1;
}

/**
 * @brief 找链表中环的入口节点，分为三步
 * 1、 确定是否有环，利用快慢节点思想；
 * 2、 统计环中的节点数量n；
 * 3、 利用快慢节点，指针1先走个节点，然后指针2从头开始遍历，与此同时指针1也遍历，直到两个指针相遇，相遇节点即为环的入口节点。
 * @param pHead the head pointer of list.
 * @return the entry node of loop in list.
 */
ailee::ListNode *EntryNodeInListLoop(ailee::ListNode *pHead) {
    // check input data.
    if (pHead == nullptr) {
        return nullptr;
    }

    ailee::ListNode *pNodeInLoop = MeetingNode(pHead);

    if (pNodeInLoop == nullptr) {
        return nullptr;
    }

    // 统计环中包含的节点数量
    int loopNodeNum = CounterNodeNumInLoop(pNodeInLoop);
    std::cout << loopNodeNum << std::endl;

    // 找环入口节点
    return FindEntryNodeInListLoop(loopNodeNum, pHead);
}

void test(const char *testName, ailee::ListNode *pHead) {
    std::cout << testName << std::endl;

    ailee::ListNode *pEntryNode = EntryNodeInListLoop(pHead);
    ailee::LinkedList::PrintListNode(pEntryNode);
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
    test_01();
    test_02();
    test_03();
    test_04();
    test_05();
    test_06();
    test_07();

    return 0;
}
