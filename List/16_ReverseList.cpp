//
// Created by AILEE on 2023/1/30.
// 题目16：反转链表
// 题目：定义一个链表，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。
//

#include "LinkedList.h"

#include <iostream>
#include <vector>

/**
 * @brief reverse list
 * @param pHead the input list head pointer
 * @return the head pointer of reversed lit
 */
ailee::ListNode *ReverseList(ailee::ListNode *pHead) {
    ailee::ListNode *pReverseListHead = new ailee::ListNode();

    ailee::ListNode *pNode = pHead;
    ailee::ListNode *pPrevNode = nullptr;
    while (pNode != nullptr) {
        ailee::ListNode *pNext = pNode->m_pNext;

        if (pNode->m_pNext == nullptr) {
            pReverseListHead = pNode;
        }

        pNode->m_pNext = pPrevNode;
        pPrevNode = pNode;
        pNode = pNext;
    }

    return pReverseListHead;
}

/**
 * @brief create linked list from console input.
 * @return linked list head pointer.
 */
ailee::ListNode* createLinkedList() {
    std::vector<int> array;
    for (int i = 0; std::cin>>i;) {
        array.push_back(i);
        if (std::cin.get() == '\n') {
            break;
        }
    }

    ailee::ListNode *pHead = new ailee::ListNode();
    pHead = nullptr;
    for (auto &it : array) {
        ailee::LinkedList::Add2Tail(&pHead, it);
    }

    return pHead;
}

void test_01() {
    ailee::ListNode *pHead = createLinkedList();
    ailee::ListNode *reverseListHead = ReverseList(pHead);
    ailee::LinkedList::PrintListNode(reverseListHead);
    ailee::LinkedList::PrintList(reverseListHead);
}

void test_02() {
    ailee::ListNode *pHead = nullptr;
    ailee::ListNode *reverseListHead = ReverseList(pHead);
    ailee::LinkedList::PrintListNode(reverseListHead);
    ailee::LinkedList::PrintList(reverseListHead);
}

int main(int argc, char** argv) {
    test_01();
    test_02();

    return 0;
}