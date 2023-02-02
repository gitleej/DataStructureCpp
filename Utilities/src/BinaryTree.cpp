//
// Created by AILEE on 2023/2/2.
//

#include "BinaryTree.h"
#include <iostream>

using namespace std;

ailee::BinaryTreeNode *ailee::BinaryTree::CreateBinaryTreeNode(int value) {
    BinaryTreeNode *pNode = new BinaryTreeNode();
    pNode->m_nValue = value;
    pNode->m_pLeft = nullptr;
    pNode->m_pRight = nullptr;

    return pNode;
}

void ailee::BinaryTree::ConnectBinaryNodes(ailee::BinaryTreeNode *pParent, ailee::BinaryTreeNode *pLeft,
                                           ailee::BinaryTreeNode *pRight) {
    if (pParent != nullptr) {
        pParent->m_pLeft = pLeft;
        pParent->m_pRight = pRight;
    }
}

void ailee::BinaryTree::PrintBinaryTreeNode(const ailee::BinaryTreeNode *pNode) {
    if (pNode != nullptr) {
        cout << "the value of this node is: " << pNode->m_nValue << endl;
        if (pNode->m_pLeft != nullptr) {
            cout << "the value of its left node is: " << pNode->m_pLeft->m_nValue << endl;
        } else {
            cout << "its left node is nullptr." << endl;
        }
        if (pNode->m_pRight != nullptr) {
            cout << "the value of its right node is: " << pNode->m_pRight->m_nValue << endl;
        } else {
            cout << "its right node is nullptr." << endl;
        }
    } else {
        cout << "this node is nullptr." << endl;
    }
}

void ailee::BinaryTree::PrintBinaryTree(const ailee::BinaryTreeNode *pRoot) {
    PrintBinaryTreeNode(pRoot);

    if (pRoot != nullptr) {
        if (pRoot->m_pLeft != nullptr) {
            PrintBinaryTree(pRoot->m_pLeft);
        }

        if (pRoot->m_pRight != nullptr) {
            PrintBinaryTree(pRoot->m_pRight);
        }
    }
}

void ailee::BinaryTree::DestroyBinaryTree(ailee::BinaryTreeNode *pRoot) {
    if (pRoot != nullptr) {
        BinaryTreeNode *pLeft = pRoot->m_pLeft;
        BinaryTreeNode *pRight = pRoot->m_pRight;

        delete pRoot;

        DestroyBinaryTree(pLeft);
        DestroyBinaryTree(pRight);
    }
}
