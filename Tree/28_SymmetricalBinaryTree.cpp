//
// Created by AILEE on 2023/2/3.
// 题目28：对称的二叉树
// 题目：请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和他的镜像一样，那么它是一棵对称二叉树。
//

#include "BinaryTree.h"

#include <iostream>
#include <stack>

using namespace std;

/**
 * @brief 利用先序遍历和镜像树的先序遍历实现，当两棵树是对称的树时，其先序遍历结果是相同的。
 * @param pRoot1 原树的根节点
 * @param pRoot2 镜像树的根节点
 * @return 是否为对称树
 */
bool IsSymmetricalBinaryTree(ailee::BinaryTreeNode* pRoot1, ailee::BinaryTreeNode* pRoot2) {
    // 到达叶子节点
    if (pRoot1 == nullptr && pRoot2 == nullptr) {
        return true;
    }

    // 处理结构不对称情况
    if (pRoot1 == nullptr || pRoot2 == nullptr) {
        return false;
    }

    if (pRoot1->m_nValue != pRoot2->m_nValue) {
        return false;
    }

    // 处理左右子树。
    return IsSymmetricalBinaryTree(pRoot1->m_pLeft, pRoot2->m_pRight) && IsSymmetricalBinaryTree(pRoot1->m_pRight, pRoot2->m_pLeft);
}

/**
 * @brief 栈加循环实现
 * @param pRoot1 原树的根节点
 * @param pRoot2 镜像树的根节点
 * @return 是否为对称树
 */
bool IsSymmetricalBinaryTreeIteratively(ailee::BinaryTreeNode* pRoot1, ailee::BinaryTreeNode* pRoot2) {
    if (pRoot1 == nullptr && pRoot2 == nullptr) {
        return false;
    }

    stack<ailee::BinaryTreeNode *> binaryTree1NodeStack;
    stack<ailee::BinaryTreeNode *> binaryTree2NodeStack;
    binaryTree1NodeStack.push(pRoot1);
    binaryTree2NodeStack.push(pRoot2);

    bool result = false;
    while (!binaryTree1NodeStack.empty() && !binaryTree2NodeStack.empty()) {
        result = false;
        ailee::BinaryTreeNode *pNode1 = binaryTree1NodeStack.top();
        ailee::BinaryTreeNode *pNode2 = binaryTree2NodeStack.top();
        binaryTree1NodeStack.pop();
        binaryTree2NodeStack.pop();

        if (pNode1 == nullptr && pNode2 == nullptr) {
            result = true;
        } else if (pNode1 != nullptr && pNode2 != nullptr) {
            if (pNode1->m_nValue == pNode2->m_nValue) {
                result = true;
            } else {
                result = false;
                break;
            }
        } else {
            result = false;
            break;
        }

        // 处理左子树
        if (pNode1->m_pLeft != nullptr && pNode2->m_pRight != nullptr) {
            binaryTree1NodeStack.push(pNode1->m_pLeft);
            binaryTree2NodeStack.push(pNode2->m_pRight);
        } else if (pNode1->m_pLeft == nullptr && pNode2->m_pRight == nullptr) {
            result = true;
        } else {
            result = false;
            break;
        }

        // 处理右子树
        if (pNode1->m_pRight != nullptr && pNode2->m_pLeft != nullptr) {
            binaryTree1NodeStack.push(pNode1->m_pRight);
            binaryTree2NodeStack.push(pNode2->m_pLeft);
        } else if (pNode1->m_pRight == nullptr && pNode2->m_pLeft == nullptr) {
            result = true;
        } else {
            result = false;
            break;
        }
    }

    return result;
}

bool IsSymmetricalBinaryTree(ailee::BinaryTreeNode* pRoot) {
    if (pRoot == nullptr) {
        return false;
    }

    return IsSymmetricalBinaryTree(pRoot, pRoot);
}

void test(const char* testName, ailee::BinaryTreeNode* pRoot) {
    cout << testName << endl;

    bool result = IsSymmetricalBinaryTree(pRoot);
    cout << "Recursively" << endl;
    if (result) {
        cout << "this binary tree is a symmetrical tree." << endl;
    } else {
        cout << "this binary tree is not a symmetrical tree." << endl;
    }

    result = IsSymmetricalBinaryTreeIteratively(pRoot, pRoot);
    cout << "Iteratively" << endl;
    if (result) {
        cout << "this binary tree is a symmetrical tree." << endl;
    } else {
        cout << "this binary tree is not a symmetrical tree." << endl;
    }
}

/**
 * @brief 空树
 */
void test_01() {
    test("test 01", nullptr);
}

/**
 * @brief 只有一个节点的二叉树
 */
void test_02() {
    ailee::BinaryTreeNode *pNode1 = ailee::BinaryTree::CreateBinaryTreeNode(1);

    test("test 02", pNode1);
}

/**
 * @brief 对称的完全二叉树
 */
void test_03() {
    ailee::BinaryTreeNode *pNode1 = ailee::BinaryTree::CreateBinaryTreeNode(1);
    ailee::BinaryTreeNode *pNode2 = ailee::BinaryTree::CreateBinaryTreeNode(2);
    ailee::BinaryTreeNode *pNode3 = ailee::BinaryTree::CreateBinaryTreeNode(2);
    ailee::BinaryTreeNode *pNode4 = ailee::BinaryTree::CreateBinaryTreeNode(3);
    ailee::BinaryTreeNode *pNode5 = ailee::BinaryTree::CreateBinaryTreeNode(3);
    ailee::BinaryTreeNode *pNode6 = ailee::BinaryTree::CreateBinaryTreeNode(4);
    ailee::BinaryTreeNode *pNode7 = ailee::BinaryTree::CreateBinaryTreeNode(4);

    ailee::BinaryTree::ConnectBinaryNodes(pNode1, pNode2, pNode3);
    ailee::BinaryTree::ConnectBinaryNodes(pNode2, pNode4, pNode6);
    ailee::BinaryTree::ConnectBinaryNodes(pNode3, pNode7, pNode5);

    test("test 03", pNode1);
}

/**
 * @brief 不对称的完全二叉树
 */
void test_04() {
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

    test("test 04", pNode1);
}

/**
 * @brief 结构不对称的二叉树
 */
void test_05() {
    ailee::BinaryTreeNode *pNode1 = ailee::BinaryTree::CreateBinaryTreeNode(1);
    ailee::BinaryTreeNode *pNode2 = ailee::BinaryTree::CreateBinaryTreeNode(2);
    ailee::BinaryTreeNode *pNode3 = ailee::BinaryTree::CreateBinaryTreeNode(2);
    ailee::BinaryTreeNode *pNode4 = ailee::BinaryTree::CreateBinaryTreeNode(3);
    ailee::BinaryTreeNode *pNode5 = ailee::BinaryTree::CreateBinaryTreeNode(3);
    ailee::BinaryTreeNode *pNode6 = ailee::BinaryTree::CreateBinaryTreeNode(4);
    ailee::BinaryTreeNode *pNode7 = ailee::BinaryTree::CreateBinaryTreeNode(4);
    ailee::BinaryTreeNode *pNode8 = ailee::BinaryTree::CreateBinaryTreeNode(5);

    ailee::BinaryTree::ConnectBinaryNodes(pNode1, pNode2, pNode3);
    ailee::BinaryTree::ConnectBinaryNodes(pNode2, pNode4, pNode6);
    ailee::BinaryTree::ConnectBinaryNodes(pNode3, pNode7, pNode5);
    ailee::BinaryTree::ConnectBinaryNodes(pNode4, pNode8, nullptr);

    test("test 05", pNode1);
}

/**
 * @brief 所有节点都相同，但结构不对称的二叉树
 */
void test_06() {
    ailee::BinaryTreeNode *pNode1 = ailee::BinaryTree::CreateBinaryTreeNode(1);
    ailee::BinaryTreeNode *pNode2 = ailee::BinaryTree::CreateBinaryTreeNode(1);
    ailee::BinaryTreeNode *pNode3 = ailee::BinaryTree::CreateBinaryTreeNode(1);
    ailee::BinaryTreeNode *pNode4 = ailee::BinaryTree::CreateBinaryTreeNode(1);
    ailee::BinaryTreeNode *pNode5 = ailee::BinaryTree::CreateBinaryTreeNode(1);
    ailee::BinaryTreeNode *pNode6 = ailee::BinaryTree::CreateBinaryTreeNode(1);
    ailee::BinaryTreeNode *pNode7 = ailee::BinaryTree::CreateBinaryTreeNode(1);
    ailee::BinaryTreeNode *pNode8 = ailee::BinaryTree::CreateBinaryTreeNode(1);

    ailee::BinaryTree::ConnectBinaryNodes(pNode1, pNode2, pNode3);
    ailee::BinaryTree::ConnectBinaryNodes(pNode2, pNode4, pNode5);
    ailee::BinaryTree::ConnectBinaryNodes(pNode3, pNode6, pNode7);
    ailee::BinaryTree::ConnectBinaryNodes(pNode4, pNode8, nullptr);

    test("test 06", pNode1);
}

/**
 * @brief 所有节点都相同，结构对称的二叉树
 */
void test_07() {
    ailee::BinaryTreeNode *pNode1 = ailee::BinaryTree::CreateBinaryTreeNode(1);
    ailee::BinaryTreeNode *pNode2 = ailee::BinaryTree::CreateBinaryTreeNode(1);
    ailee::BinaryTreeNode *pNode3 = ailee::BinaryTree::CreateBinaryTreeNode(1);
    ailee::BinaryTreeNode *pNode4 = ailee::BinaryTree::CreateBinaryTreeNode(1);
    ailee::BinaryTreeNode *pNode5 = ailee::BinaryTree::CreateBinaryTreeNode(1);
    ailee::BinaryTreeNode *pNode6 = ailee::BinaryTree::CreateBinaryTreeNode(1);
    ailee::BinaryTreeNode *pNode7 = ailee::BinaryTree::CreateBinaryTreeNode(1);

    ailee::BinaryTree::ConnectBinaryNodes(pNode1, pNode2, pNode3);
    ailee::BinaryTree::ConnectBinaryNodes(pNode2, pNode4, pNode5);
    ailee::BinaryTree::ConnectBinaryNodes(pNode3, pNode6, pNode7);

    test("test 07", pNode1);
}

/**
 * @brief 只有一个子节点的树，对称
 */
void test_08() {
    ailee::BinaryTreeNode *pNode1 = ailee::BinaryTree::CreateBinaryTreeNode(1);
    ailee::BinaryTreeNode *pNode2 = ailee::BinaryTree::CreateBinaryTreeNode(2);
    ailee::BinaryTreeNode *pNode3 = ailee::BinaryTree::CreateBinaryTreeNode(2);
    ailee::BinaryTreeNode *pNode4 = ailee::BinaryTree::CreateBinaryTreeNode(3);
    ailee::BinaryTreeNode *pNode5 = ailee::BinaryTree::CreateBinaryTreeNode(3);
    ailee::BinaryTreeNode *pNode6 = ailee::BinaryTree::CreateBinaryTreeNode(4);
    ailee::BinaryTreeNode *pNode7 = ailee::BinaryTree::CreateBinaryTreeNode(4);

    ailee::BinaryTree::ConnectBinaryNodes(pNode1, pNode2, pNode3);
    ailee::BinaryTree::ConnectBinaryNodes(pNode2, pNode4, nullptr);
    ailee::BinaryTree::ConnectBinaryNodes(pNode3, nullptr, pNode5);
    ailee::BinaryTree::ConnectBinaryNodes(pNode4, pNode6, nullptr);
    ailee::BinaryTree::ConnectBinaryNodes(pNode5, nullptr, pNode7);

    test("test 08", pNode1);
}

/**
 * @brief 只有一个子节点的树，结构对称，数据不对称
 */
void test_09() {
    ailee::BinaryTreeNode *pNode1 = ailee::BinaryTree::CreateBinaryTreeNode(1);
    ailee::BinaryTreeNode *pNode2 = ailee::BinaryTree::CreateBinaryTreeNode(2);
    ailee::BinaryTreeNode *pNode3 = ailee::BinaryTree::CreateBinaryTreeNode(2);
    ailee::BinaryTreeNode *pNode4 = ailee::BinaryTree::CreateBinaryTreeNode(3);
    ailee::BinaryTreeNode *pNode5 = ailee::BinaryTree::CreateBinaryTreeNode(3);
    ailee::BinaryTreeNode *pNode6 = ailee::BinaryTree::CreateBinaryTreeNode(4);
    ailee::BinaryTreeNode *pNode7 = ailee::BinaryTree::CreateBinaryTreeNode(5);

    ailee::BinaryTree::ConnectBinaryNodes(pNode1, pNode2, pNode3);
    ailee::BinaryTree::ConnectBinaryNodes(pNode2, pNode4, nullptr);
    ailee::BinaryTree::ConnectBinaryNodes(pNode3, nullptr, pNode5);
    ailee::BinaryTree::ConnectBinaryNodes(pNode4, pNode6, nullptr);
    ailee::BinaryTree::ConnectBinaryNodes(pNode5, nullptr, pNode7);

    test("test 09", pNode1);
}

/**
 * @brief 只有一个子节点的树，结构不对称，数据对称
 */
void test_10() {
    ailee::BinaryTreeNode *pNode1 = ailee::BinaryTree::CreateBinaryTreeNode(1);
    ailee::BinaryTreeNode *pNode2 = ailee::BinaryTree::CreateBinaryTreeNode(2);
    ailee::BinaryTreeNode *pNode3 = ailee::BinaryTree::CreateBinaryTreeNode(2);
    ailee::BinaryTreeNode *pNode4 = ailee::BinaryTree::CreateBinaryTreeNode(3);
    ailee::BinaryTreeNode *pNode5 = ailee::BinaryTree::CreateBinaryTreeNode(3);
    ailee::BinaryTreeNode *pNode6 = ailee::BinaryTree::CreateBinaryTreeNode(4);
    ailee::BinaryTreeNode *pNode7 = ailee::BinaryTree::CreateBinaryTreeNode(4);

    ailee::BinaryTree::ConnectBinaryNodes(pNode1, pNode2, pNode3);
    ailee::BinaryTree::ConnectBinaryNodes(pNode2, pNode4, nullptr);
    ailee::BinaryTree::ConnectBinaryNodes(pNode3, nullptr, pNode5);
    ailee::BinaryTree::ConnectBinaryNodes(pNode4, pNode6, nullptr);
    ailee::BinaryTree::ConnectBinaryNodes(pNode5, pNode7, nullptr);

    test("test 10", pNode1);
}

int main(int argc, char** argv) {
    test_01();
    test_02();
    test_03();
    test_04();
    test_05();
    test_06();
    test_07();
    test_08();
    test_09();
    test_10();

    return 0;
}