//
// Created by AILEE on 2023/1/31.
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
            if (pNodeA->m_nValue == pNodeB->m_nValue) {
                pCommonNode = pNodeA;
            }

            stackA.pop();
            stackB.pop();
        }
    } else {
        while (!stackA.empty()) {
            ailee::ListNode *pNodeA = stackA.top();
            ailee::ListNode *pNodeB = stackB.top();
            if (pNodeA->m_nValue == pNodeB->m_nValue) {
                pCommonNode = pHeadA;
            }

            stackA.pop();
            stackB.pop();
        }
    }

    return pCommonNode;
}

void test(const char *testName, ailee::ListNode *pHeadA, ailee::ListNode *pHeadB) {
    std::cout << testName << std::endl;

    ailee::ListNode *pCommonNode = FirstCommonNodeInLists_Stack(pHeadA, pHeadB);
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

int main(int argc, char **argv) {
    test_01();

    return 0;
}