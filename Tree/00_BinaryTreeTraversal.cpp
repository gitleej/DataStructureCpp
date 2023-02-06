//
// Created by AILEE on 2023/2/6.
// 题目00：二叉树的遍历
// 题目：用递归和非递归方式实现二叉树的先序、中序、后序和广度优先遍历。
//

#include "BinaryTree.h"

#include <iostream>
#include <stack>
#include <deque>

using namespace std;

void BinaryTreePreOrderRecursively(ailee::BinaryTreeNode* pRoot) {
    if (pRoot == nullptr) {
        return;
    }

    cout << pRoot->m_nValue << " ";
    BinaryTreePreOrderRecursively(pRoot->m_pLeft);
    BinaryTreePreOrderRecursively(pRoot->m_pRight);
}

void BinaryTreePreOrderIteratively(ailee::BinaryTreeNode* pRoot) {
    if (pRoot == nullptr) {
        return;
    }

    stack<ailee::BinaryTreeNode*> binaryTreeNodeStack;
    ailee::BinaryTreeNode *pNode = pRoot;
    while (pNode != nullptr || !binaryTreeNodeStack.empty()) {
        if (pNode != nullptr) {
            cout << pNode->m_nValue << " ";
            binaryTreeNodeStack.push(pNode);
            pNode = pNode->m_pLeft;
        } else {
            pNode = binaryTreeNodeStack.top()->m_pRight;
            binaryTreeNodeStack.pop();
        }
    }

    cout << endl;
}

void BinaryTreeInOrderRecursively(ailee::BinaryTreeNode* pRoot) {
    if (pRoot == nullptr) {
        return;
    }

    BinaryTreeInOrderRecursively(pRoot->m_pLeft);
    cout << pRoot->m_nValue << " ";
    BinaryTreeInOrderRecursively(pRoot->m_pRight);
}

void BinaryTreeInOrderIteratively(ailee::BinaryTreeNode* pRoot) {
    if (pRoot == nullptr) {
        return;
    }

    stack<ailee::BinaryTreeNode*> binaryTreeNodeStack;
    ailee::BinaryTreeNode *pNode = pRoot;
    while (pNode != nullptr || !binaryTreeNodeStack.empty()) {
        if (pNode != nullptr) {
            binaryTreeNodeStack.push(pNode);
            pNode = pNode->m_pLeft;
        } else {
            pNode = binaryTreeNodeStack.top();
            binaryTreeNodeStack.pop();
            cout << pNode->m_nValue << " ";
            pNode = pNode->m_pRight;
        }
    }

    cout << endl;
}

void BinaryTreePostOrderRecursively(ailee::BinaryTreeNode* pRoot) {
    if (pRoot == nullptr) {
        return;
    }

    BinaryTreePostOrderRecursively(pRoot->m_pLeft);
    BinaryTreePostOrderRecursively(pRoot->m_pRight);
    cout << pRoot->m_nValue << " ";
}

void BinaryTreePostOrderIteratively(ailee::BinaryTreeNode* pRoot) {
    if (pRoot == nullptr) {
        return;
    }

    stack<ailee::BinaryTreeNode *> binaryTreeNodeStack;
    ailee::BinaryTreeNode *pNode = pRoot;
    ailee::BinaryTreeNode *pVisited = nullptr;
    while (pNode != nullptr || !binaryTreeNodeStack.empty()) {
        if (pNode != nullptr) {
            binaryTreeNodeStack.push(pNode);
            pNode = pNode->m_pLeft;
        } else {
            pNode = binaryTreeNodeStack.top();
            // 如果到达叶子节点
            if (pNode->m_pRight == nullptr || pNode->m_pRight == pVisited) {
                binaryTreeNodeStack.pop();
                cout << pNode->m_nValue << " ";
                pVisited = pNode;
                pNode = nullptr;
            } else {
                binaryTreeNodeStack.push(binaryTreeNodeStack.top()->m_pRight);
                pNode = binaryTreeNodeStack.top()->m_pLeft;
            }
        }
    }

    cout << endl;
}

void BinaryTreeLevelOrder(ailee::BinaryTreeNode *pRoot) {
    if (pRoot == nullptr) {
        return;
    }

    deque<ailee::BinaryTreeNode*> binaryTreeNodeDeque;
    ailee::BinaryTreeNode *pNode = pRoot;
    binaryTreeNodeDeque.push_back(pNode);
    while (!binaryTreeNodeDeque.empty()) {
        pNode = binaryTreeNodeDeque.front();
        binaryTreeNodeDeque.pop_front();

        cout << pNode->m_nValue << " ";

        if (pNode->m_pLeft != nullptr) {
            binaryTreeNodeDeque.push_back(pNode->m_pLeft);
        }
        if (pNode->m_pRight != nullptr) {
            binaryTreeNodeDeque.push_back(pNode->m_pRight);
        }
    }

    cout << endl;
}

void test(const char* testName, ailee::BinaryTreeNode* pRoot) {
    cout << testName << endl;

    cout << "Recursively" << endl;
    BinaryTreePreOrderRecursively(pRoot);
    cout << endl;
    BinaryTreeInOrderRecursively(pRoot);
    cout << endl;
    BinaryTreePostOrderRecursively(pRoot);
    cout << endl;

    cout << "Iteratively" << endl;
    BinaryTreePreOrderIteratively(pRoot);
    BinaryTreeInOrderIteratively(pRoot);
    BinaryTreePostOrderIteratively(pRoot);

    cout << "Level Order" << endl;
    BinaryTreeLevelOrder(pRoot);

    ailee::BinaryTree::DestroyBinaryTree(pRoot);
}

/**
 * @brief 空树
 */
void test_01() {
    test("test 01", nullptr);
}

/**
 * @brief 只有一个节点的树
 */
void test_02() {
    ailee::BinaryTreeNode *pNode1 = ailee::BinaryTree::CreateBinaryTreeNode(1);

    test("test 02", pNode1);
}

/**
 * @brief 完全二叉树
 */
void test_03() {
    ailee::BinaryTreeNode *pNode1 = ailee::BinaryTree::CreateBinaryTreeNode(1);
    ailee::BinaryTreeNode *pNode2 = ailee::BinaryTree::CreateBinaryTreeNode(2);
    ailee::BinaryTreeNode *pNode3 = ailee::BinaryTree::CreateBinaryTreeNode(3);
    ailee::BinaryTreeNode *pNode4 = ailee::BinaryTree::CreateBinaryTreeNode(4);
    ailee::BinaryTreeNode *pNode5 = ailee::BinaryTree::CreateBinaryTreeNode(5);
    ailee::BinaryTreeNode *pNode6 = ailee::BinaryTree::CreateBinaryTreeNode(6);
    ailee::BinaryTreeNode *pNode7 = ailee::BinaryTree::CreateBinaryTreeNode(7);

    ailee::BinaryTree::ConnectBinaryNodes(pNode1, pNode2, pNode3);
    ailee::BinaryTree::ConnectBinaryNodes(pNode2, pNode4, pNode5);
    ailee::BinaryTree::ConnectBinaryNodes(pNode3, pNode6, pNode7);

    test("test 03", pNode1);
}

/**
 * @brief 普通二叉树
 */
void test_04() {
    ailee::BinaryTreeNode *pNode1 = ailee::BinaryTree::CreateBinaryTreeNode(1);
    ailee::BinaryTreeNode *pNode2 = ailee::BinaryTree::CreateBinaryTreeNode(2);
    ailee::BinaryTreeNode *pNode3 = ailee::BinaryTree::CreateBinaryTreeNode(3);
    ailee::BinaryTreeNode *pNode4 = ailee::BinaryTree::CreateBinaryTreeNode(4);
    ailee::BinaryTreeNode *pNode5 = ailee::BinaryTree::CreateBinaryTreeNode(5);
    ailee::BinaryTreeNode *pNode6 = ailee::BinaryTree::CreateBinaryTreeNode(6);
    ailee::BinaryTreeNode *pNode7 = ailee::BinaryTree::CreateBinaryTreeNode(7);
    ailee::BinaryTreeNode *pNode8 = ailee::BinaryTree::CreateBinaryTreeNode(8);
    ailee::BinaryTreeNode *pNode9 = ailee::BinaryTree::CreateBinaryTreeNode(9);

    ailee::BinaryTree::ConnectBinaryNodes(pNode1, pNode2, pNode3);
    ailee::BinaryTree::ConnectBinaryNodes(pNode2, pNode4, pNode5);
    ailee::BinaryTree::ConnectBinaryNodes(pNode3, pNode6, pNode7);
    ailee::BinaryTree::ConnectBinaryNodes(pNode6, pNode8, nullptr);
    ailee::BinaryTree::ConnectBinaryNodes(pNode7, nullptr, pNode9);

    test("test 04", pNode1);
}

/**
 * @brief 只有左子节点的树
 */
void test_05() {
    ailee::BinaryTreeNode *pNode1 = ailee::BinaryTree::CreateBinaryTreeNode(1);
    ailee::BinaryTreeNode *pNode2 = ailee::BinaryTree::CreateBinaryTreeNode(2);
    ailee::BinaryTreeNode *pNode3 = ailee::BinaryTree::CreateBinaryTreeNode(3);
    ailee::BinaryTreeNode *pNode4 = ailee::BinaryTree::CreateBinaryTreeNode(4);
    ailee::BinaryTreeNode *pNode5 = ailee::BinaryTree::CreateBinaryTreeNode(5);

    ailee::BinaryTree::ConnectBinaryNodes(pNode1, pNode2, nullptr);
    ailee::BinaryTree::ConnectBinaryNodes(pNode2, pNode3, nullptr);
    ailee::BinaryTree::ConnectBinaryNodes(pNode3, pNode4, nullptr);
    ailee::BinaryTree::ConnectBinaryNodes(pNode4, pNode5, nullptr);

    test("test 05", pNode1);
}

/**
 * @brief 只有右子节点的树
 */
void test_06() {ailee::BinaryTreeNode *pNode1 = ailee::BinaryTree::CreateBinaryTreeNode(1);
    ailee::BinaryTreeNode *pNode2 = ailee::BinaryTree::CreateBinaryTreeNode(2);
    ailee::BinaryTreeNode *pNode3 = ailee::BinaryTree::CreateBinaryTreeNode(3);
    ailee::BinaryTreeNode *pNode4 = ailee::BinaryTree::CreateBinaryTreeNode(4);
    ailee::BinaryTreeNode *pNode5 = ailee::BinaryTree::CreateBinaryTreeNode(5);

    ailee::BinaryTree::ConnectBinaryNodes(pNode1, nullptr, pNode2);
    ailee::BinaryTree::ConnectBinaryNodes(pNode2, nullptr, pNode3);
    ailee::BinaryTree::ConnectBinaryNodes(pNode3, nullptr, pNode4);
    ailee::BinaryTree::ConnectBinaryNodes(pNode4, nullptr, pNode5);

    test("test 06", pNode1);
}

int main(int argc, char** argv) {
    test_01();
    test_02();
    test_03();
    test_04();
    test_05();
    test_06();

    return 0;
}