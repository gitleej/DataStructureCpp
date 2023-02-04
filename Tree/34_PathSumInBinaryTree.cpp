//
// Created by AILEE on 2023/2/4.
// 题目34：二叉树中和为某一值的路径
// 题目：输入一棵二叉树和一个整数，打印出二叉树中节点值的和为输入帧数的所有路径，从树的根节点开始往下一直到叶节点所经过的节点形成一条路径。
//

#include "BinaryTree.h"

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/**
 * @brief 递归实现核心算法
 * @param pRoot 二叉树根节点指针
 * @param targetValue 目标值
 * @param path 路径
 * @param currentSum 当前值
 */
void PathSumInBinaryTreeRecursivelyCore(ailee::BinaryTreeNode* pRoot,
                                        int targetValue,
                                        vector<int> &path,
                                        int currentSum) {
    // 更新当前值
    currentSum += pRoot->m_nValue;
    // 更新路径
    path.push_back(pRoot->m_nValue);

    // 当到达叶子节点时，且路径和与目标值相等时，打路径
    if (pRoot->m_pLeft == nullptr && pRoot->m_pRight == nullptr && currentSum == targetValue) {
        cout << "find a suitable path:" << endl;
        for (auto &it : path) {
            cout << it << " ";
        }
        cout << endl;
    }

    // 如果不是叶子节点，则递归
    // 处理左子树
    if (pRoot->m_pLeft != nullptr) {
        PathSumInBinaryTreeRecursivelyCore(pRoot->m_pLeft, targetValue, path, currentSum);
    }
    // 处理右子树
    if (pRoot->m_pRight != nullptr) {
        PathSumInBinaryTreeRecursivelyCore(pRoot->m_pRight, targetValue, path, currentSum);
    }

    // 回到父节点
    path.pop_back();
}

/**
 * @brief 递归实现
 * @param pRoot
 * @param targetValue
 */
void PathSumInBinaryTreeRecursively(ailee::BinaryTreeNode* pRoot, int targetValue) {
    if (pRoot == nullptr) {
        cout << "this tree is nullptr" << endl;
        return;
    }

    int currentSum = 0;
    vector<int> path;
    PathSumInBinaryTreeRecursivelyCore(pRoot, targetValue, path, currentSum);
}

/**
 * @brief 循环加栈实现，只有后续遍历才能保存根节点到最后
 * @param pRoot 二叉树根节点
 * @param targetValue 目标值
 */
void PathSumInBinaryTreeIteratively(ailee::BinaryTreeNode* pRoot, int targetValue) {
    if (pRoot == nullptr) {
        cout << "this tree is nullptr" << endl;
        return;
    }

    stack<ailee::BinaryTreeNode*> binaryTreeNodeStack;
    vector<ailee::BinaryTreeNode*> binaryTreeNodeVector; // 用数组模拟栈的先入后出
    ailee::BinaryTreeNode *pCurrentNode = pRoot;
    ailee::BinaryTreeNode *pPrevNode = nullptr;
    int currentSum = 0;
    while (pCurrentNode != nullptr || !binaryTreeNodeStack.empty()) {
        if (pCurrentNode != nullptr) {
            binaryTreeNodeStack.push(pCurrentNode);
            binaryTreeNodeVector.push_back(pCurrentNode);
            currentSum += pCurrentNode->m_nValue;
            pCurrentNode = pCurrentNode->m_pLeft;
        } else {
            pCurrentNode = binaryTreeNodeStack.top();
            // 当一个节点的右子节点为空或者被访问过时，则表示该节点可以被访问
            if (pCurrentNode->m_pRight == nullptr || pCurrentNode->m_pRight == pPrevNode) {
                // 找到了合适的叶子节点
                if (pCurrentNode->m_pLeft == nullptr && pCurrentNode->m_pLeft == nullptr) {
                    if (currentSum == targetValue) {
                        cout << "find a suitable path." << endl;
                        for (auto &it : binaryTreeNodeVector) {
                            cout << it->m_nValue << " ";
                        }
                        cout << endl;
                    }
                }

                currentSum -= pCurrentNode->m_nValue;
                pPrevNode = pCurrentNode;
                binaryTreeNodeStack.pop();
                binaryTreeNodeVector.pop_back();
                pCurrentNode = nullptr;

            } else { // 处理右子节点
                pCurrentNode = pCurrentNode->m_pRight;
            }
        }
    }

}

void test(const char* testName, ailee::BinaryTreeNode* pRoot, int targetValue) {
    cout << testName <<endl;

    cout << "Recursively" << endl;
    PathSumInBinaryTreeRecursively(pRoot, targetValue);
    cout << "Iteratively" << endl;
    PathSumInBinaryTreeIteratively(pRoot, targetValue);
}

/**
 * @brief 空树
 */
void test_01() {
    test("test 01", nullptr, 0);
}

/**
 * @brief 只有一个节点的树
 */
void test_02_03() {
    ailee::BinaryTreeNode *pNode1 = ailee::BinaryTree::CreateBinaryTreeNode(1);

    test("test 02", pNode1, 1);
    test("test 03", pNode1, 2);

    ailee::BinaryTree::DestroyBinaryTree(pNode1);
}

/**
 * @brief 完全二叉树
 */
void test_04_06() {
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

    test("test 04", pNode1, 11);
    test("test 05", pNode1, 10);
    test("test 06", pNode1, 9);

    ailee::BinaryTree::DestroyBinaryTree(pNode1);
}

/**
 * @brief 只有左子节点的树
 */
void test_07_08() {
    ailee::BinaryTreeNode *pNode1 = ailee::BinaryTree::CreateBinaryTreeNode(1);
    ailee::BinaryTreeNode *pNode2 = ailee::BinaryTree::CreateBinaryTreeNode(2);
    ailee::BinaryTreeNode *pNode3 = ailee::BinaryTree::CreateBinaryTreeNode(3);
    ailee::BinaryTreeNode *pNode4 = ailee::BinaryTree::CreateBinaryTreeNode(4);
    ailee::BinaryTreeNode *pNode5 = ailee::BinaryTree::CreateBinaryTreeNode(5);

    ailee::BinaryTree::ConnectBinaryNodes(pNode1, pNode2, nullptr);
    ailee::BinaryTree::ConnectBinaryNodes(pNode2, pNode3, nullptr);
    ailee::BinaryTree::ConnectBinaryNodes(pNode3, pNode4, nullptr);
    ailee::BinaryTree::ConnectBinaryNodes(pNode4, pNode5, nullptr);

    test("test 07", pNode1, 15);
    test("test 08", pNode1, 14);

    ailee::BinaryTree::DestroyBinaryTree(pNode1);
}

/**
 * @brief 只有右子节点的树
 */
void test_09_10() {ailee::BinaryTreeNode *pNode1 = ailee::BinaryTree::CreateBinaryTreeNode(1);
    ailee::BinaryTreeNode *pNode2 = ailee::BinaryTree::CreateBinaryTreeNode(2);
    ailee::BinaryTreeNode *pNode3 = ailee::BinaryTree::CreateBinaryTreeNode(3);
    ailee::BinaryTreeNode *pNode4 = ailee::BinaryTree::CreateBinaryTreeNode(4);
    ailee::BinaryTreeNode *pNode5 = ailee::BinaryTree::CreateBinaryTreeNode(5);

    ailee::BinaryTree::ConnectBinaryNodes(pNode1, nullptr, pNode2);
    ailee::BinaryTree::ConnectBinaryNodes(pNode2, nullptr, pNode3);
    ailee::BinaryTree::ConnectBinaryNodes(pNode3, nullptr, pNode4);
    ailee::BinaryTree::ConnectBinaryNodes(pNode4, nullptr, pNode5);

    test("test 09", pNode1, 15);
    test("test 10", pNode1, 14);

    ailee::BinaryTree::DestroyBinaryTree(pNode1);
}

int main(int argc, char** argv) {
    test_01();
    test_02_03();
    test_04_06();
    test_07_08();
    test_09_10();

    return 0;
}