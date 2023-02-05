//
// Created by AILEE on 2023/2/5.
// 题目55_01：二叉树的深度
// 题目：输入一棵二叉树的根节点，求该树的深度。从根节点到叶子节点依次经过的节点形成的一条路径，最长路径的长度为树的深度。
//

#include "BinaryTree.h"

#include <iostream>
#include <deque>

using namespace std;

int BinaryTreeDepthRecursivelyCore(ailee::BinaryTreeNode* pRoot) {
    if (pRoot == nullptr) {
        return 0;
    }

    int leftDepth = BinaryTreeDepthRecursivelyCore(pRoot->m_pLeft);
    int rightDepth = BinaryTreeDepthRecursivelyCore(pRoot->m_pRight);

    return (leftDepth > rightDepth) ? (leftDepth + 1) : (rightDepth + 1);
}

int BinaryTreeDepthRecursively(ailee::BinaryTreeNode* pRoot) {
    if (pRoot == nullptr) {
        cout << "this tree is nullptr" << endl;
        return 0;
    }

    return BinaryTreeDepthRecursivelyCore(pRoot);
}

/**
 * @brief 循环+队列，广度优先搜索
 * @param pRoot
 * @return
 */
int BinaryTreeDepthIteratively(ailee::BinaryTreeNode* pRoot) {
    int depth = 0;
    if (pRoot == nullptr) {
        cout << "this tree is nullptr" << endl;
        return depth;
    }

    deque<ailee::BinaryTreeNode*> binaryTreeNodeDeque;
    binaryTreeNodeDeque.push_back(pRoot);
    int nextLevelNum = 0;
    int numToBePrinted = 1;
    while (!binaryTreeNodeDeque.empty()) {
        ailee::BinaryTreeNode *pNode = binaryTreeNodeDeque.front();
        binaryTreeNodeDeque.pop_front();

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
            depth++;
            numToBePrinted = nextLevelNum;
            nextLevelNum = 0;
        }
    }
    return depth;
}

void test(const char *testName, ailee::BinaryTreeNode* pRoot) {
    cout << testName << endl;

    int depth = 0;
    cout << "Recursively" << endl;
    depth = BinaryTreeDepthRecursively(pRoot);
    cout << depth << endl;

    cout << "Iteratively" << endl;
    depth = BinaryTreeDepthIteratively(pRoot);
    cout << depth << endl;

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
    ailee::BinaryTree::ConnectBinaryNodes(pNode2, pNode6, pNode7);
    ailee::BinaryTree::ConnectBinaryNodes(pNode3, pNode4, pNode5);

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
