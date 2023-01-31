//
// Created by AILEE on 2023/1/31.
// 题目26：复杂链表的复制
// 题目：请实现函数ComplexListNode* Clone(ComplexListNode* pHead)，复制一个复杂链表。在复杂链表中，每个节点除了有一个m_pNext指针指向下
// 一个节点外，还有一个m_pSibling指向链表中的任意节点或者NULL。
//

#include "LinkedList.h"

#include <vector>
#include <iostream>

/**
 * @brief copy nodes
 * @param pHead the head pointer of complex list.
 */
void cloneNodes(ailee::ComplexListNode *pHead) {
    ailee::ComplexListNode *pNode = pHead;
    while (pNode != nullptr) {
        ailee::ComplexListNode *pCloned = new ailee::ComplexListNode();
        pCloned->m_nValue = pNode->m_nValue;
        pCloned->m_pNext = pNode->m_pNext;
        pCloned->m_pSibling = nullptr;
        pNode->m_pNext = pCloned;

        pNode = pCloned->m_pNext;
    }
}

/**
 * @brief set sibling node to copied nodes,
 * @param pHead the head pointer of complex list.
 */
void setSiblingNode(ailee::ComplexListNode *pHead) {
    ailee::ComplexListNode *pNode = pHead;
    while (pNode != nullptr) {
        // 只有当前节点存在Sibling节点才需要设置
        if (pNode->m_pSibling != nullptr) {
            pNode->m_pNext->m_pSibling = pNode->m_pSibling->m_pNext;
        }

        pNode = pNode->m_pNext->m_pNext;
    }
}

/**
 * @brief split complex list to original list and cloned list.
 * @param pHead the head pointer of complex list.
 * @return the cloned list head pointer.
 */
ailee::ComplexListNode *splitList(ailee::ComplexListNode *pHead) {
    ailee::ComplexListNode *pNode = pHead;
    ailee::ComplexListNode *pCloneHead = nullptr;
    ailee::ComplexListNode *pCloneNode = nullptr;

    if (pNode != nullptr) {
        pCloneHead = pNode->m_pNext;
        pCloneNode = pCloneHead;
        pNode->m_pNext = pCloneNode->m_pNext;
        pNode = pNode->m_pNext;
    }

    while (pNode != nullptr) {
        pCloneNode->m_pNext = pNode->m_pNext;
        pCloneNode = pCloneNode->m_pNext;

        pNode->m_pNext = pCloneNode->m_pNext;
        pNode = pNode->m_pNext;
    }

    return pCloneHead;
}
/**
 * @brief clone complex list. three steps
 * 1. clone all nodes.
 * 2. set sibling node to cloned nodes.
 * 3. split list to original list and cloned list.
 * @param pHead the head pointer of complex list.
 * @return the cloned list head point.
 */
ailee::ComplexListNode *Clone(ailee::ComplexListNode *pHead) {
    cloneNodes(pHead);
    setSiblingNode(pHead);
    return splitList(pHead);
}

void test(const char *testName, ailee::ComplexListNode *pHead) {
    std::cout << testName << std::endl;

    ailee::ComplexListNode *pClonedHead = Clone(pHead);
    std::cout << "the original list: " << std::endl;
    ailee::ComplexList::PrintComplexList(pHead);

    std::cout << "the cloned list: " << std::endl;
    ailee::ComplexList::PrintComplexList(pClonedHead);
}

/**
 * @brief 普通情况
 */
void test_01() {
    ailee::ComplexListNode *pNode1 = ailee::ComplexList::CreateComplexListNode(1);
    ailee::ComplexListNode *pNode2 = ailee::ComplexList::CreateComplexListNode(2);
    ailee::ComplexListNode *pNode3 = ailee::ComplexList::CreateComplexListNode(3);
    ailee::ComplexListNode *pNode4 = ailee::ComplexList::CreateComplexListNode(4);
    ailee::ComplexListNode *pNode5 = ailee::ComplexList::CreateComplexListNode(5);

    ailee::ComplexList::ConnectComplexListNode(pNode1, pNode2, pNode3);
    ailee::ComplexList::ConnectComplexListNode(pNode2, pNode3, pNode5);
    ailee::ComplexList::ConnectComplexListNode(pNode3, pNode4, nullptr);
    ailee::ComplexList::ConnectComplexListNode(pNode4, pNode5, pNode2);

    test("test_01", pNode1);
}

/**
 * @brief 节点自循环
 */
void test_02() {
    ailee::ComplexListNode *pNode1 = ailee::ComplexList::CreateComplexListNode(1);
    ailee::ComplexListNode *pNode2 = ailee::ComplexList::CreateComplexListNode(2);
    ailee::ComplexListNode *pNode3 = ailee::ComplexList::CreateComplexListNode(3);
    ailee::ComplexListNode *pNode4 = ailee::ComplexList::CreateComplexListNode(4);
    ailee::ComplexListNode *pNode5 = ailee::ComplexList::CreateComplexListNode(5);

    ailee::ComplexList::ConnectComplexListNode(pNode1, pNode2, pNode3);
    ailee::ComplexList::ConnectComplexListNode(pNode2, pNode3, pNode5);
    ailee::ComplexList::ConnectComplexListNode(pNode3, pNode4, pNode3);
    ailee::ComplexList::ConnectComplexListNode(pNode4, pNode5, pNode2);

    test("test_02", pNode1);
}

/**
 * @brief 多节点内循环
 */
void test_03() {
    ailee::ComplexListNode *pNode1 = ailee::ComplexList::CreateComplexListNode(1);
    ailee::ComplexListNode *pNode2 = ailee::ComplexList::CreateComplexListNode(2);
    ailee::ComplexListNode *pNode3 = ailee::ComplexList::CreateComplexListNode(3);
    ailee::ComplexListNode *pNode4 = ailee::ComplexList::CreateComplexListNode(4);
    ailee::ComplexListNode *pNode5 = ailee::ComplexList::CreateComplexListNode(5);

    ailee::ComplexList::ConnectComplexListNode(pNode1, pNode2, pNode3);
    ailee::ComplexList::ConnectComplexListNode(pNode2, pNode3, pNode4);
    ailee::ComplexList::ConnectComplexListNode(pNode3, pNode4, nullptr);
    ailee::ComplexList::ConnectComplexListNode(pNode4, pNode5, pNode2);

    test("test_03", pNode1);
}

/**
 * @brief 只有一个节点
 */
void test_04() {
    ailee::ComplexListNode *pNode1 = ailee::ComplexList::CreateComplexListNode(1);

    ailee::ComplexList::ConnectComplexListNode(pNode1, nullptr, pNode1);

    test("test_04", pNode1);
}

/**
 * @brief 空链表
 */
void test_05() {
    test("test_05", nullptr);
}

int main(int argc, char **argv) {
    test_01();
    test_02();
    test_03();
    test_04();
    test_05();

    return 0;
}