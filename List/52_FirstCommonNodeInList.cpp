//
// Created by AILEE on 2023/1/31.
// 题目52：两个链表中的第一个公共节点
// 题目：输入两个链表，找出这两个链表中的第一个公共节点
//

#include "LinkedList.h"

#include <iostream>
#include <vector>
#include <stack>

/**
 * @brief 借助栈作辅助空间，实现两个链表中第一个公共节点的查询。时间复杂度O(n+m)，空间复杂度O(n+m)
 * @param pHeadA the head pointer of first list.
 * @param pHeadB the head pointer of second list.
 * @return the common node pointer.
 */
ailee::ListNode *FirstCommonNodeInLists_Stack(ailee::ListNode *pHeadA, ailee::ListNode *pHeadB) {
    ailee::ListNode *pCommonNode = new ailee::ListNode();
    if (pHeadA == nullptr || pHeadB == nullptr) {
        pCommonNode = nullptr;
        return pCommonNode;
    }

    int lengthA = 0;
    std::stack<ailee::ListNode*> stackA;
    ailee::ListNode *pNode = pHeadA;
    while (pNode != nullptr) {
        stackA.push(pNode);
        pNode = pNode->m_pNext;
        lengthA++;
    }

    int lengthB = 0;
    std::stack<ailee::ListNode*> stackB;
    pNode = pHeadB;
    while (pNode != nullptr) {
        stackB.push(pNode);
        pNode = pNode->m_pNext;
        lengthB++;
    }

    if (lengthA > lengthB) {
        while (!stackB.empty()) {
            ailee::ListNode *pNodeA = stackA.top();
            ailee::ListNode *pNodeB = stackB.top();
            if (pNodeA->m_nValue != pNodeB->m_nValue) {
                break;
            }
            pCommonNode = pNodeA;

            stackA.pop();
            stackB.pop();
        }
    } else {
        while (!stackA.empty()) {
            ailee::ListNode *pNodeA = stackA.top();
            ailee::ListNode *pNodeB = stackB.top();
            if (pNodeA->m_nValue == pNodeB->m_nValue) {
                pCommonNode = pNodeA;
            }

            stackA.pop();
            stackB.pop();
        }
    }

    return pCommonNode;
}

/**
 * @brief 先遍历一次，获取链表长度，根据相同部分长度相同，长链表先向前走(n-m)步，然后一起遍历。时间复杂度O(n+m)，无需额外空间。
 * @param pHeadA the head pointer of first list.
 * @param pHeadB the head pointer of second list.
 * @return the common node pointer.
 */
ailee::ListNode *FirstCommonNodeInLists_Best(ailee::ListNode *pHeadA, ailee::ListNode *pHeadB) {
    ailee::ListNode *pCommonNode = new ailee::ListNode();
    // check input data
    if (pHeadA == nullptr || pHeadB == nullptr) {
        pCommonNode = nullptr;
    }

    ailee::ListNode *pNodeA = pHeadA;
    int lengthA = 0;
    while (pNodeA != nullptr) {
        lengthA++;
        pNodeA = pNodeA->m_pNext;
    }

    ailee::ListNode *pNodeB = pHeadB;
    int lengthB = 0;
    while (pNodeB != nullptr) {
        lengthB++;
        pNodeB = pNodeB->m_pNext;
    }

    if (lengthA > lengthB) {
        pNodeA = pHeadA;
        pNodeB = pHeadB;
        for (int i = 0; i < lengthA - lengthB; i++) {
            pNodeA = pNodeA->m_pNext;
        }
    } else {
        pNodeA = pHeadA;
        pNodeB = pHeadB;
        for (int i = 0; i < lengthB - lengthA; i++) {
            pNodeB = pNodeB->m_pNext;
        }
    }
    while (pNodeA != nullptr) {
        if (pNodeA->m_nValue == pNodeB->m_nValue) {
            pCommonNode = pNodeA;
            break;
        }
        pNodeA = pNodeA->m_pNext;
        pNodeB = pNodeB->m_pNext;
    }

    return pCommonNode;
}

void test(const char *testName, ailee::ListNode *pHeadA, ailee::ListNode *pHeadB) {
    std::cout << testName << std::endl;

    std::cout << "stack" << std::endl;
    ailee::ListNode *pCommonNode = FirstCommonNodeInLists_Stack(pHeadA, pHeadB);
    ailee::LinkedList::PrintListNode(pCommonNode);

    std::cout << "best" << std::endl;
    pCommonNode = FirstCommonNodeInLists_Best(pHeadA, pHeadB);
    ailee::LinkedList::PrintListNode(pCommonNode);
}

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

void addCommonNode2List(ailee::ListNode *pHead, std::vector<int> &commonArray) {
    for (auto &it : commonArray) {
        ailee::LinkedList::Add2Tail(&pHead, it);
    }
}

/**
 * @brief 普通情况测试
 */
void test_01() {
    ailee::ListNode *pHeadA = createLinkedList();
    ailee::ListNode *pHeadB = createLinkedList();

    // get common node
    std::vector<int> array;
    for (int i = 0; std::cin>>i;) {
        array.push_back(i);
        if (std::cin.get() == '\n') {
            break;
        }
    }

    addCommonNode2List(pHeadA, array);
    addCommonNode2List(pHeadB, array);

    test("test 01", pHeadA, pHeadB);
}

/**
 * @brief 没有公共节点
 */
void test_02() {
    ailee::ListNode *pHeadA = createLinkedList();
    ailee::ListNode *pHeadB = createLinkedList();

    test("test 02", pHeadA, pHeadB);
}

/**
 * @brief 空指针
 */
void test_03() {
    test("test 03", nullptr, nullptr);
}

int main(int argc, char **argv) {
    test_01();
    test_02();
    test_03();

    return 0;
}