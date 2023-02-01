//
// Created by AILEE on 2023/2/1.
// 题目18_2：删除链表中重复的节点
// 题目：在一个排序链表中，删除所有重复的节点。
//

#include "LinkedList.h"

#include <iostream>

/**
 * @brief 删除链表中重复的节点
 * @param pHead 链表头指针的指针，当头指针重复时，头指针也会被删除，所以需要传入指针的指针。
 */
void DeleteDuplication(ailee::ListNode **pHead) {
    // check input data
    if (pHead == nullptr || *pHead == nullptr) {
        return;
    }

    ailee::ListNode *pNode = *pHead;
    ailee::ListNode *pPrevNode = nullptr;
    while (pNode != nullptr) {
        ailee::ListNode *pNext = pNode->m_pNext;
        bool deleteFlag = false;
        if (pNext != nullptr && pNode->m_nValue == pNext->m_nValue) {
            deleteFlag = true;
        }

        if (!deleteFlag) {
            pPrevNode = pNode;
            pNode = pNode->m_pNext;
        } else {
            int value = pNode->m_nValue;
            ailee::ListNode *toBeDelete = pNode;
            while (toBeDelete != nullptr && toBeDelete->m_nValue == value) {
                pNext = toBeDelete->m_pNext;

                delete toBeDelete;
                toBeDelete = nullptr;
                toBeDelete = pNext;
            }
            // 头指针被删
            if (pPrevNode == nullptr) {
                *pHead = pNext;
            } else {
                pPrevNode->m_pNext = pNext;
            }

            pNode = pNext;
        }
    }
}

void test(const char *testName, ailee::ListNode **pHead) {
    std::cout << testName << std::endl;

    DeleteDuplication(pHead);
    ailee::ListNode *pNode = *pHead;
    ailee::LinkedList::PrintList(*pHead);
}

/**
 * @brief 空链表
 */
void test_01() {
    ailee::ListNode *pHead = nullptr;

    test("test 01", &pHead);
}

/**
 * @brief 从控制台输入进行各种链表测试
 */
void test_02() {
    ailee::ListNode *pHead = ailee::LinkedList::CreateLinkedList();

    test("test 02", &pHead);
}

int main(int argc, char** argv) {
    test_01();
    test_02();

    return 0;
}