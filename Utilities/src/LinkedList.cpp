//
// Created by AILEE on 2023/1/29.
//

#include "LinkedList.h"

#include <iostream>

ailee::ListNode *ailee::LinkedList::CreateListNode(int value) {
    ailee::ListNode *pNode = new ListNode();
    pNode->m_nValue = value;
    pNode->m_pNext = nullptr;
    return pNode;
}

void ailee::LinkedList::ConnectListNodes(ailee::ListNode *pCurrent, ailee::ListNode *pNext) {
    if(pCurrent == nullptr) {
        std::cout << "ERROR: error to connect two nodes." << std::endl;
        exit(1);
    }

    pCurrent->m_pNext = pNext;
}

void ailee::LinkedList::PrintListNode(ailee::ListNode *pNode) {
    if(pNode == nullptr) {
        std::cout << "INFO: this node is nullptr." << std::endl;
    } else {
        std::cout << "the key in node is " << pNode->m_nValue << std::endl;
    }
}

void ailee::LinkedList::PrintList(ailee::ListNode *pHead) {
    ListNode *pNode = pHead;

    while (pNode != nullptr) {
        std::cout << pNode->m_nValue << "\t";
        pNode = pNode->m_pNext;
    }

    std::cout << std::endl;
}

void ailee::LinkedList::DestroyList(ailee::ListNode *pHead) {
    ListNode *pNode = pHead;

    while (pNode != nullptr) {
        pHead = pHead->m_pNext;
        delete pNode;
        pNode = pHead;
    }
}

void ailee::LinkedList::Add2Tail(ailee::ListNode **pHead, int value) {
    ListNode *pNew = new ListNode();

    pNew->m_nValue = value;
    pNew->m_pNext = nullptr;

    if (*pHead == nullptr) {
        *pHead = pNew;
    } else {
        ListNode *pNode = *pHead;
        while (pNode != nullptr) {
            pNode = pNode->m_pNext;
        }

        pNode->m_pNext = pNew;
    }
}

void ailee::LinkedList::RemoveNode(ailee::ListNode **pHead, int value) {
    if (pHead == nullptr || *pHead == nullptr) {
        return;
    }

    ListNode *pToBeDeleted = nullptr;
    if ((*pHead)->m_nValue == value) {
        pToBeDeleted = *pHead;
        *pHead = (*pHead)->m_pNext;
    } else {
        ListNode *pNode = *pHead;
        while (pNode->m_pNext != nullptr && pNode->m_pNext->m_nValue != value) {
            pNode = pNode->m_pNext;
        }
    }


}
