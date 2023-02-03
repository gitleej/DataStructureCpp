//
// Created by AILEE on 2023/2/3.
// 题目27：二叉树的镜像
// 题目：请完成一个函数，输入一颗二叉树，该函数输出它的镜像。
//

#include "BinaryTree.h"

#include <iostream>
#include <stack>

using namespace std;

/**
 * @brief 用递归方式实现二叉树镜像，遍历方式采用先序遍历
 * @param pRoot 二叉树的根节点
 */
void MirrorOfBinaryTreeRecursively(ailee::BinaryTreeNode* pRoot) {
    if (pRoot == nullptr) {
        return;
    }

    // 到达叶子节点时，跳出递归
    if (pRoot->m_pLeft == nullptr && pRoot->m_pRight == nullptr) {
        return;
    }

    ailee::BinaryTreeNode *pTemp = pRoot->m_pLeft;
    pRoot->m_pLeft = pRoot->m_pRight;
    pRoot->m_pRight = pTemp;

    // 处理左子树
    if (pRoot->m_pLeft != nullptr) {
        MirrorOfBinaryTreeRecursively(pRoot->m_pLeft);
    }
    // 处理右子树
    if (pRoot->m_pRight != nullptr) {
        MirrorOfBinaryTreeRecursively(pRoot->m_pRight);
    }
}

/**
 * @brief 用栈加循环方式实现二叉树镜像，遍历方式采用先序遍历
 * @param pRoot 二叉树的根节点
 */
void MirrorOfBinaryTreeIteratively(ailee::BinaryTreeNode* pRoot) {
    if (pRoot == nullptr) {
        return;
    }

    stack<ailee::BinaryTreeNode* > binaryTreeNodeStack;
    binaryTreeNodeStack.push(pRoot);
    while (!binaryTreeNodeStack.empty()) {
        ailee::BinaryTreeNode *pNode = binaryTreeNodeStack.top();
        binaryTreeNodeStack.pop();
        if (pNode->m_pLeft != nullptr || pNode->m_pRight != nullptr) {
            ailee::BinaryTreeNode *pTemp = pNode->m_pLeft;
            pNode->m_pLeft = pNode->m_pRight;
            pNode->m_pRight = pTemp;
        }

        // 处理左子树
        if (pNode->m_pLeft != nullptr) {
            binaryTreeNodeStack.push(pNode->m_pLeft);
        }

        // 处理右子树
        if (pNode->m_pRight != nullptr) {
            binaryTreeNodeStack.push(pNode->m_pRight);
        }
    }
}

void test(const char* testName, ailee::BinaryTreeNode* pRoot) {
    cout << testName << endl;

    MirrorOfBinaryTreeRecursively(pRoot);
    cout << "Recursively" << endl;
    ailee::BinaryTree::PrintBinaryTree(pRoot);
    MirrorOfBinaryTreeIteratively(pRoot);
    cout << "Iteratively" << endl;
    ailee::BinaryTree::PrintBinaryTree(pRoot);

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
 * @brief 只有左节点的树
 */
void test_03() {
    ailee::BinaryTreeNode *pNode1 = ailee::BinaryTree::CreateBinaryTreeNode(1);
    ailee::BinaryTreeNode *pNode2 = ailee::BinaryTree::CreateBinaryTreeNode(2);
    ailee::BinaryTreeNode *pNode3 = ailee::BinaryTree::CreateBinaryTreeNode(3);
    ailee::BinaryTreeNode *pNode4 = ailee::BinaryTree::CreateBinaryTreeNode(4);
    ailee::BinaryTreeNode *pNode5 = ailee::BinaryTree::CreateBinaryTreeNode(5);

    ailee::BinaryTree::ConnectBinaryNodes(pNode1, pNode2, nullptr);
    ailee::BinaryTree::ConnectBinaryNodes(pNode2, pNode3, nullptr);
    ailee::BinaryTree::ConnectBinaryNodes(pNode3, pNode4, nullptr);
    ailee::BinaryTree::ConnectBinaryNodes(pNode4, pNode5, nullptr);

    test("test 03", pNode1);
}

/**
 * @brief 只有右节点的树
 */
void test_04() {
    ailee::BinaryTreeNode *pNode1 = ailee::BinaryTree::CreateBinaryTreeNode(1);
    ailee::BinaryTreeNode *pNode2 = ailee::BinaryTree::CreateBinaryTreeNode(2);
    ailee::BinaryTreeNode *pNode3 = ailee::BinaryTree::CreateBinaryTreeNode(3);
    ailee::BinaryTreeNode *pNode4 = ailee::BinaryTree::CreateBinaryTreeNode(4);
    ailee::BinaryTreeNode *pNode5 = ailee::BinaryTree::CreateBinaryTreeNode(5);

    ailee::BinaryTree::ConnectBinaryNodes(pNode1, nullptr, pNode2);
    ailee::BinaryTree::ConnectBinaryNodes(pNode2, nullptr, pNode3);
    ailee::BinaryTree::ConnectBinaryNodes(pNode3, nullptr, pNode4);
    ailee::BinaryTree::ConnectBinaryNodes(pNode4, nullptr, pNode5);

    test("test 04", pNode1);
}

/**
 * @brief 完全二叉树
 */
void test_05() {
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