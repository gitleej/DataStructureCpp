//
// Created by AILEE on 2023/2/3.
// 题目32_033：之字形打印二叉树
// 题目：请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左至右的顺序打印，第二行按照从右至左的顺序打印，第三行再按照从左至右的顺序打印，其他行以此类推。
//

#include "BinaryTree.h"

#include <iostream>
#include <stack>

using namespace std;

/**
 * @brief 按照之字形打印二叉树，利用两个栈分别存储当前层的节点和下一层的节点，然后用两个变量控制层级更新，奇数层从右到左入栈，偶数层从左到右入栈。
 * @param pRoot 二叉树根节点指针
 */
void PrintBinaryTreeInZigzag(ailee::BinaryTreeNode* pRoot) {
    if (pRoot == nullptr) {
        cout << "this tree is nullptr" << endl;
        return;
    }

    stack<ailee::BinaryTreeNode*> binaryTreeNodeStack[2];

    int current = 0;
    int next = 1;
    binaryTreeNodeStack[current].push(pRoot);
    while (!binaryTreeNodeStack[0].empty() || !binaryTreeNodeStack[1].empty()) {
        ailee::BinaryTreeNode *pNode = binaryTreeNodeStack[current].top();
        binaryTreeNodeStack[current].pop();

        cout << pNode->m_nValue << " ";

        if (current == 0) { // 奇数行处理，先压入左子节点，再压入右子节点
            if (pNode->m_pLeft != nullptr) {
                binaryTreeNodeStack[next].push(pNode->m_pLeft);
            }
            if (pNode->m_pRight != nullptr) {
                binaryTreeNodeStack[next].push(pNode->m_pRight);
            }
        } else { // 偶数行处理，先压入右子节点，再压入左子节点。
            if (pNode->m_pRight != nullptr) {
                binaryTreeNodeStack[next].push(pNode->m_pRight);
            }
            if (pNode->m_pLeft != nullptr) {
                binaryTreeNodeStack[next].push(pNode->m_pLeft);
            }
        }

        // 当一个栈空时，说明一行已经打印完成，交换两个栈的内容。
        if (binaryTreeNodeStack[current].empty()) {
            current = 1 - current;
            next = 1 - next;
            cout << endl;
        }
    }
}

void test(const char* testName, ailee::BinaryTreeNode* pRoot) {
    cout << testName << endl;

    PrintBinaryTreeInZigzag(pRoot);

    ailee::BinaryTree::DestroyBinaryTree(pRoot);
}

/**
 * @brief 空树
 */
void test_01() {
    test("test 01", nullptr);
}

/**
 * @brief 只有一个节点的树。
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
    ailee::BinaryTreeNode *pNode8 = ailee::BinaryTree::CreateBinaryTreeNode(8);
    ailee::BinaryTreeNode *pNode9 = ailee::BinaryTree::CreateBinaryTreeNode(9);
    ailee::BinaryTreeNode *pNode10 = ailee::BinaryTree::CreateBinaryTreeNode(10);
    ailee::BinaryTreeNode *pNode11 = ailee::BinaryTree::CreateBinaryTreeNode(11);
    ailee::BinaryTreeNode *pNode12 = ailee::BinaryTree::CreateBinaryTreeNode(12);
    ailee::BinaryTreeNode *pNode13 = ailee::BinaryTree::CreateBinaryTreeNode(13);
    ailee::BinaryTreeNode *pNode14 = ailee::BinaryTree::CreateBinaryTreeNode(14);
    ailee::BinaryTreeNode *pNode15 = ailee::BinaryTree::CreateBinaryTreeNode(15);

    ailee::BinaryTree::ConnectBinaryNodes(pNode1, pNode2, pNode3);
    ailee::BinaryTree::ConnectBinaryNodes(pNode2, pNode4, pNode5);
    ailee::BinaryTree::ConnectBinaryNodes(pNode3, pNode6, pNode7);
    ailee::BinaryTree::ConnectBinaryNodes(pNode4, pNode8, pNode9);
    ailee::BinaryTree::ConnectBinaryNodes(pNode5, pNode10, pNode11);
    ailee::BinaryTree::ConnectBinaryNodes(pNode6, pNode12, pNode13);
    ailee::BinaryTree::ConnectBinaryNodes(pNode7, pNode14, pNode15);

    test("test 03", pNode1);
}

/**
 * @brief 只有左子节点的树
 */
void test_04() {
    ailee::BinaryTreeNode *pNode1 = ailee::BinaryTree::CreateBinaryTreeNode(1);
    ailee::BinaryTreeNode *pNode2 = ailee::BinaryTree::CreateBinaryTreeNode(2);
    ailee::BinaryTreeNode *pNode3 = ailee::BinaryTree::CreateBinaryTreeNode(3);
    ailee::BinaryTreeNode *pNode4 = ailee::BinaryTree::CreateBinaryTreeNode(4);
    ailee::BinaryTreeNode *pNode5 = ailee::BinaryTree::CreateBinaryTreeNode(5);

    ailee::BinaryTree::ConnectBinaryNodes(pNode1, pNode2, nullptr);
    ailee::BinaryTree::ConnectBinaryNodes(pNode2, pNode3, nullptr);
    ailee::BinaryTree::ConnectBinaryNodes(pNode3, pNode4, nullptr);
    ailee::BinaryTree::ConnectBinaryNodes(pNode4, pNode5, nullptr);

    test("test 04", pNode1);
}

/**
 * @brief 只有右子节点的树
 */
void test_05() {ailee::BinaryTreeNode *pNode1 = ailee::BinaryTree::CreateBinaryTreeNode(1);
    ailee::BinaryTreeNode *pNode2 = ailee::BinaryTree::CreateBinaryTreeNode(2);
    ailee::BinaryTreeNode *pNode3 = ailee::BinaryTree::CreateBinaryTreeNode(3);
    ailee::BinaryTreeNode *pNode4 = ailee::BinaryTree::CreateBinaryTreeNode(4);
    ailee::BinaryTreeNode *pNode5 = ailee::BinaryTree::CreateBinaryTreeNode(5);

    ailee::BinaryTree::ConnectBinaryNodes(pNode1, nullptr, pNode2);
    ailee::BinaryTree::ConnectBinaryNodes(pNode2, nullptr, pNode3);
    ailee::BinaryTree::ConnectBinaryNodes(pNode3, nullptr, pNode4);
    ailee::BinaryTree::ConnectBinaryNodes(pNode4, nullptr, pNode5);

    test("test 05", pNode1);
}

int main(int argc, char** argv) {
    test_01();
    test_02();
    test_03();
    test_04();
    test_05();

    return 0;
}