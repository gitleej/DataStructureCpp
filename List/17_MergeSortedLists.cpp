//
// Created by AILEE on 2023/1/30.
// 题目17：合并两个排序的链表
// 题目：输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是按照递增排序的。
//

#include "LinkedList.h"

#include <vector>
#include <iostream>

/**
 * @brief merge two sorted list.
 * @param pHeadA the first sorted list.
 * @param pHeadB the second sorted list.
 * @return the merged sorted list.
 */
ailee::ListNode *MergeSortedLists(ailee::ListNode *pHeadA, ailee::ListNode *pHeadB) {
    // check input data
    if (pHeadA == nullptr) {
        return pHeadB;
    } else if (pHeadB == nullptr) {
        return pHeadA;
    }

    ailee::ListNode *pMergedHead = nullptr;
    if (pHeadA->m_nValue > pHeadB->m_nValue) {
        pMergedHead = pHeadB;
        pMergedHead->m_pNext = MergeSortedLists(pHeadA, pHeadB->m_pNext);
    } else {
        pMergedHead = pHeadA;
        pMergedHead->m_pNext = MergeSortedLists(pHeadA->m_pNext, pHeadB);
    }

    return pMergedHead;
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
    std::cout << "test 01" << std::endl;
    ailee::ListNode *pHeadA = createLinkedList();
    ailee::ListNode *pHeadB = createLinkedList();
    ailee::ListNode *pMergeHead = MergeSortedLists(pHeadA, pHeadB);
    ailee::LinkedList::PrintList(pMergeHead);
}

void test_02() {
    std::cout << "test 02" << std::endl;
    ailee::ListNode *pHeadA = nullptr;
    ailee::ListNode *pHeadB = createLinkedList();
    ailee::ListNode *pMergeHead = MergeSortedLists(pHeadA, pHeadB);
    ailee::LinkedList::PrintList(pMergeHead);
}

void test_03() {
    std::cout << "test 03" << std::endl;
    ailee::ListNode *pHeadA = createLinkedList();
    ailee::ListNode *pHeadB = nullptr;
    ailee::ListNode *pMergeHead = MergeSortedLists(pHeadA, pHeadB);
    ailee::LinkedList::PrintList(pMergeHead);
}

void test_04() {
    std::cout << "test 04" << std::endl;
    ailee::ListNode *pHeadA = nullptr;
    ailee::ListNode *pHeadB = nullptr;
    ailee::ListNode *pMergeHead = MergeSortedLists(pHeadA, pHeadB);
    ailee::LinkedList::PrintList(pMergeHead);
}

int main(int argc, char** argv) {
    test_01();
    test_02();
    test_03();
    test_04();

    return 0;
}