//
// Created by AILEE on 2023/1/30.
// 题目15：链表中倒数第K个节点
// 题目：输入一个链表，输出该链表中倒数第K个节点。
//

#include "LinkedList.h"

#include <vector>
#include <iostream>

/**
 * @brief find the Kth node to tail of linked list.
 * @param pHead the head pointer of linked list.
 * @param k the k value
 */
void FindKthNode2Tail(ailee::ListNode *pHead, unsigned int k) {
    // check input data
    if (pHead == nullptr || k == 0) {
        std::cout << "ERROR: The input data is not standardized." << std::endl;
        return;
    }

    // if k is greater linked size.
    ailee::ListNode *pHead_1 = pHead;
    for (int i = 0; i < k - 1; i++) {
        if (pHead_1->m_pNext != nullptr) {
            pHead_1 = pHead_1->m_pNext;
        } else {
            std::cout << "ERROR: k is greater linked size." << std::endl;
            return;
        }
    }

    ailee::ListNode *pTargetNode = pHead;
    while (pHead_1->m_pNext != nullptr) {
        pHead_1 = pHead_1->m_pNext;
        pTargetNode = pTargetNode->m_pNext;
    }

    std::cout << pTargetNode->m_nValue << std::endl;
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
    int k;
    std::cin >> k;
    FindKthNode2Tail(pHead, k);
}

void test_02() {
    ailee::ListNode *pHead = nullptr;
    int k;
    std::cin >> k;
    FindKthNode2Tail(pHead, k);
}

int main(int argc, char** argv) {
    test_01();
    test_02();

    return 0;
}