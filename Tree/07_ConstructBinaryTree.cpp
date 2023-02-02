//
// Created by AILEE on 2023/2/1.
// 面试题7：重建二叉树
// 题目：输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输
// 入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列{1,
// 2, 4, 7, 3, 5, 6, 8}和中序遍历序列{4, 7, 2, 1, 5, 3, 8, 6}，则重建出
// 图2.6所示的二叉树并输出它的头结点。
//

#include "BinaryTree.h"

#include <iostream>
#include <exception>

ailee::BinaryTreeNode *ConstructCore(int* pPrevOrderStart, int* pPrevOrderEnd, int* pInOrderStart, int* pInOrderEnd) {
    // 前序遍历
    int rootValue = pPrevOrderStart[0];
    ailee::BinaryTreeNode *pRoot = new ailee::BinaryTreeNode();
    pRoot->m_nValue = rootValue;
    pRoot->m_pLeft = nullptr;
    pRoot->m_pRight = nullptr;

    // 检查输入
    if (pPrevOrderStart == pPrevOrderEnd) {
        if (pInOrderStart == pInOrderEnd && *pPrevOrderStart == *pInOrderStart) { // 头尾为同一个值，说明到达了同一个节点，那么值应该相同。
            return pRoot;
        } else {
            throw std::exception();
        }
    }

    // 中序遍历找根节点
    int *pRootInOrder = pInOrderStart;
    while (pRootInOrder <= pInOrderEnd && *pRootInOrder != rootValue) {
        ++pRootInOrder;
    }

    // 检查输入, 查无对应根节点值
    if (pRootInOrder == pInOrderEnd && *pRootInOrder != rootValue) {
        throw std::exception();
    }

    int leftLength = int(pRootInOrder - pInOrderStart);
    int* pLeftPrevOrderEnd = pPrevOrderStart + leftLength;
    if (leftLength > 0) {
        pRoot->m_pLeft = ConstructCore(pPrevOrderStart + 1, pLeftPrevOrderEnd, pInOrderStart, pRootInOrder - 1);
    }
    if (leftLength < pPrevOrderEnd - pPrevOrderStart) {
        pRoot->m_pRight = ConstructCore(pLeftPrevOrderEnd + 1, pPrevOrderEnd, pRootInOrder + 1, pInOrderEnd);
    }

    return pRoot;
}

ailee::BinaryTreeNode *ConstructBinaryTree(int* pPrevOrder, int* pInOrder, int length) {
    if (pPrevOrder == nullptr || pInOrder == nullptr || length <= 0) {
        return nullptr;
    }

    return ConstructCore(pPrevOrder, pPrevOrder + length - 1, pInOrder, pInOrder + length - 1);
}

void test(const char*testName, int* pPrevOrder, int* pInOrder, int length) {
    std::cout << testName << std::endl;

    ailee::BinaryTreeNode* pRoot = ConstructBinaryTree(pPrevOrder, pInOrder, length);
    ailee::BinaryTree::PrintBinaryTree(pRoot);
    ailee::BinaryTree::DestroyBinaryTree(pRoot);
}
/**
 * @brief 普通二叉树
 */
void test_01() {
    int length = 8;
    int pPrevOrder[] = {1, 2, 4, 7, 3, 5, 6, 8};
    int pInOrder[] = {4, 7, 2, 1, 5, 3, 8, 6};
    test("test 01", pPrevOrder, pInOrder, length);
}

/**
 * @brief 完全二叉树
 */
void test_02() {
    int length = 7;
    int pPrevOrder[] = {7, 3, 1, 2, 6, 4, 5};
    int pInOrder[] = {1, 3, 2, 7, 4, 6, 5};
    test("test 02", pPrevOrder, pInOrder, length);
}

/**
 * @brief 只有左节点的二叉树
 */
void test_03() {
    int length = 5;
    int pPrevOrder[] = {1, 2, 3, 4, 5};
    int pInOrder[] = {5, 4, 3, 2, 1};
    test("test 03", pPrevOrder, pInOrder, length);
}

/**
 * @brief 只有右节点的二叉树
 */
void test_04() {
    int length = 5;
    int pPrevOrder[] = {1, 2, 3, 4, 5};
    int pInOrder[] = {1, 2, 3, 4, 5};
    test("test 04", pPrevOrder, pInOrder, length);
}

/**
 * @brief 空指针
 */
void test_05() {
    int length = 0;
    test("test 05", nullptr, nullptr, length);
}

/**
 * @brief 两个序列不匹配
 */
void test_06() {
    int length = 5;
    int pPrevOrder[] = {1, 2, 3, 4, 5};
    int pInOrder[] = {1, 3, 5, 2, 4};
    test("test 06", pPrevOrder, pInOrder, length);
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