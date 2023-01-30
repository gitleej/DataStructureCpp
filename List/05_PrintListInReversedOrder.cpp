//
// Created by AILEE on 2023/1/30.
// 题目6：从尾到头打印链表
// 题目：输入一个链表的头节点，从尾到头打印出每一个节点的值。
//

#include "LinkedList.h"
#include <stack>
#include <iostream>
#include <vector>

/**
 * @brief 利用栈先入后出的特性，通过循环实现逆序，可以有效应对长链表的序列。
 * @param pHead 链表头指针
 */
void PrintListInReversedOrder_Iteratively(ailee::ListNode* pHead){
    // check input data
    if (pHead == nullptr) {
        std::cout << "the head pointer is nullptr." << std::endl;
        return;
    }

    std::stack<ailee::ListNode*> nodes;
    ailee::ListNode *pNode = pHead;
    while (pNode != nullptr) {
        nodes.push(pNode);
        pNode = pNode->m_pNext;
    }

    while (!nodes.empty()) {
        pNode = nodes.top();
        std::cout << pNode->m_nValue << " ";
        nodes.pop();
    }
    std::cout << std::endl;
}

/**
 * @brief 利用递归实现逆序。递归层次过深，容易导致栈内存溢出。
 * @param pHead 链表头指针
 */
void PrintListInReversedOrder_Recursively(ailee::ListNode* pHead) {
    if (pHead != nullptr) {
        if (pHead->m_pNext != nullptr) {
            PrintListInReversedOrder_Recursively(pHead->m_pNext);
        }
    }

    std::cout << pHead->m_nValue << " ";
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

void test_01() {
    ailee::ListNode *pHead = createLinkedList();
    PrintListInReversedOrder_Iteratively(pHead);
    PrintListInReversedOrder_Recursively(pHead);
}

void test_02() {
    ailee::ListNode *pHead = nullptr;
    PrintListInReversedOrder_Iteratively(pHead);
    PrintListInReversedOrder_Recursively(pHead);
}

int main(int argc, char** argv) {
    test_01();
    test_02();

    return 0;
}