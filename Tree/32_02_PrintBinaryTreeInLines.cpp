//
// Created by AILEE on 2023/2/3.
// 题目32_02：分行从上到下打印二叉树
// 题目：从上到下按层打印二叉树，同一层的二叉树按照从左至右的顺序打印，每一层打印到一行。
//

#include "BinaryTree.h"

#include <iostream>
#include <deque>

using namespace std;

/**
 * @brief 利用队列先进先出的特点进行广度优先搜索，利用两个变量记录当前层节点数量和下一层节点数量。
 * @param pRoot 二叉树的根节点指针
 */
void PrintBinaryTreeInLines(ailee::BinaryTreeNode* pRoot) {
    if (pRoot == nullptr) {
        cout << "this tree is nullptr" <<endl;
        return;
    }

    deque<ailee::BinaryTreeNode*> binaryTreeNodeDeque;
    binaryTreeNodeDeque.push_back(pRoot);
    int nextLevelNum = 0;
    int numToBePrinted = 1;
    while (!binaryTreeNodeDeque.empty()) {
        ailee::BinaryTreeNode *pNode = binaryTreeNodeDeque.front();
        binaryTreeNodeDeque.pop_front();

        cout << pNode->m_nValue << " ";
        numToBePrinted--;

        if (pNode->m_pLeft != nullptr) {
            binaryTreeNodeDeque.push_back(pNode->m_pLeft);
            nextLevelNum++;
        }

        if (pNode->m_pRight != nullptr) {
            binaryTreeNodeDeque.push_back(pNode->m_pRight);
            nextLevelNum++;
        }

        if (numToBePrinted == 0) {
            numToBePrinted = nextLevelNum;
            nextLevelNum = 0;
            cout << endl;
        }
    }
}

void test(const char* testName, ailee::BinaryTreeNode* pRoot) {
    cout << testName << endl;

    PrintBinaryTreeInLines(pRoot);

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

/**
 * @brief 普通二叉树
 */
void test_06() {
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
    ailee::BinaryTree::ConnectBinaryNodes(pNode4, pNode8, nullptr);
    ailee::BinaryTree::ConnectBinaryNodes(pNode7, nullptr, pNode9);

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