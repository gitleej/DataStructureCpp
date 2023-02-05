//
// Created by AILEE on 2023/2/5.
// 题目55_02：平衡二叉树
// 题目：输入一棵二叉树的根节点，判断该树是不是平衡二叉树，如果某二叉树中任意节点的左右子树的深度相差不超过1，那么他就是一颗平衡二叉树。
//

#include "BinaryTree.h"

#include <iostream>

using namespace std;

int BinaryTreeDepthRecursively(ailee::BinaryTreeNode* pRoot) {
    if (pRoot == nullptr) {
        return 0;
    }

    int leftDepth = BinaryTreeDepthRecursively(pRoot->m_pLeft);
    int rightDepth = BinaryTreeDepthRecursively(pRoot->m_pRight);

    return (leftDepth > rightDepth) ? (leftDepth + 1) : (rightDepth + 1);
}

bool IsBalancedBinaryTreeSolution1(ailee::BinaryTreeNode* pRoot) {
    if (pRoot == nullptr) {
        return true;
    }

    int leftDepth = BinaryTreeDepthRecursively(pRoot->m_pLeft);
    int rightDepth = BinaryTreeDepthRecursively(pRoot->m_pRight);

    int diff = leftDepth - rightDepth;
    if (diff > 1 || diff < -1) {
        return false;
    }

    return IsBalancedBinaryTreeSolution1(pRoot->m_pLeft) && IsBalancedBinaryTreeSolution1(pRoot->m_pRight);
}

/**
 * @brief 最优解，只遍历一遍节点，后序遍历
 * @param pRoot
 * @param pDepth
 * @return
 */
bool IsBalancedBinaryTreeSolution2Core(ailee::BinaryTreeNode* pRoot, int *pDepth) {
    if (pRoot == nullptr) {
        *pDepth = 0;
        return true;
    }

    int leftDepth, rightDepth;
    if (IsBalancedBinaryTreeSolution2Core(pRoot->m_pLeft, &leftDepth) && IsBalancedBinaryTreeSolution2Core(pRoot->m_pRight, &rightDepth)) {
        int diff = leftDepth - rightDepth;
        if (diff >= -1 && diff <= 1) {
            *pDepth = 1 + ((leftDepth > rightDepth) ? leftDepth : rightDepth);
            return true;
        }
    }

    return false;
}

bool IsBalancedBinaryTreeSolution2(ailee::BinaryTreeNode* pRoot) {
    if (pRoot == nullptr) {
        return true;
    }

    int depth = 0;
    return IsBalancedBinaryTreeSolution2Core(pRoot, &depth);
}

void test(const char* testName, ailee::BinaryTreeNode* pRoot) {
    cout << testName << endl;

    cout << "Solution 01" << endl;
    cout << IsBalancedBinaryTreeSolution1(pRoot) << endl;

    cout << "Solution 02" << endl;
    cout << IsBalancedBinaryTreeSolution2(pRoot) << endl;

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