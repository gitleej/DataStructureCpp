//
// Created by AILEE on 2023/2/3.
// 题目32_01：从上到下打印二叉树
// 题目：从上到下打印二叉树的每一个节点，同一层的节点按照从左至右的顺序打印。
//

#include "BinaryTree.h"

#include <iostream>
#include <deque>

using namespace std;

/**
 * @brief 利用队列的先进先出特性，进行广度有限搜索。
 * @param pRoot 二叉树的根节点指针
 */
void PrintBinaryTreeFromTop2Bottom(ailee::BinaryTreeNode* pRoot) {
    if (pRoot == nullptr) {
        cout << "this tree is nullptr." << endl;
        return;
    }

    deque<ailee::BinaryTreeNode*> binaryTreeNodeDeque;
    binaryTreeNodeDeque.push_back(pRoot);
    while (!binaryTreeNodeDeque.empty()) {
        ailee::BinaryTreeNode *pNode = binaryTreeNodeDeque.front();
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

    PrintBinaryTreeFromTop2Bottom(pRoot);

    ailee::BinaryTree::DestroyBinaryTree(pRoot);
}

/**
 * @brief 空树
 */
void test_01() {
    test("test 01", nullptr);
}

/**
 * @brief 只有一个根节点的树
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
 * @brief 只有左节点的二叉树
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
 * @brief 只有右节点的二叉树
 */
void test_05() {
    ailee::BinaryTreeNode *pNode1 = ailee::BinaryTree::CreateBinaryTreeNode(1);
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