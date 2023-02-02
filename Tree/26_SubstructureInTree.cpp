//
// Created by AILEE on 2023/2/2.
//

#include "BinaryTree.h"

#include <iostream>

using namespace std;

bool DoseTreeAHaseTreeB(ailee::BinaryTreeNode* pRootA, ailee::BinaryTreeNode* pRootB) {
    // 递归结束条件
    if (pRootB == nullptr) {
        return true;
    }

    if (pRootA == nullptr) {
        return false;
    }

    if (pRootA->m_nValue != pRootB->m_nValue) {
        return false;
    }

    bool result = DoseTreeAHaseTreeB(pRootA->m_pLeft, pRootB->m_pLeft) &&
            DoseTreeAHaseTreeB(pRootA->m_pRight, pRootB->m_pRight);
    return result;
}

bool SubstructureInBinaryTree(ailee::BinaryTreeNode* pRootA, ailee::BinaryTreeNode* pRootB) {
    if (pRootA == nullptr || pRootB == nullptr) {
        return false;
    }

    bool result = false;
    if (pRootA->m_nValue == pRootB->m_nValue) {
        result = DoseTreeAHaseTreeB(pRootA, pRootB);
    }
    // 如果根节点不相等，查找左子树
    if (!result) {
        result = SubstructureInBinaryTree(pRootA->m_pLeft, pRootB);
    }
    // 如果左子树没有找到，查找右子树
    if (!result) {
        result = SubstructureInBinaryTree(pRootA->m_pRight, pRootB);
    }

    return result;
}

void test(const char* testName, ailee::BinaryTreeNode* pRootA, ailee::BinaryTreeNode* pRootB) {
    cout << testName <<endl;

    bool result = SubstructureInBinaryTree(pRootA, pRootB);
    if (result) {
        cout << "Tree B is in tree A" <<endl;
    } else {
        cout << "Tree B is not in tree A" <<endl;
    }
}

/**
 * @brief 树中节点含有分叉，树B是树A的子节点。
 */
void test_01() {
    ailee::BinaryTreeNode *pNodeA1 = ailee::BinaryTree::CreateBinaryTreeNode(1);
    ailee::BinaryTreeNode *pNodeA2 = ailee::BinaryTree::CreateBinaryTreeNode(1);
    ailee::BinaryTreeNode *pNodeA3 = ailee::BinaryTree::CreateBinaryTreeNode(3);
    ailee::BinaryTreeNode *pNodeA4 = ailee::BinaryTree::CreateBinaryTreeNode(4);
    ailee::BinaryTreeNode *pNodeA5 = ailee::BinaryTree::CreateBinaryTreeNode(5);
    ailee::BinaryTreeNode *pNodeA6 = ailee::BinaryTree::CreateBinaryTreeNode(6);
    ailee::BinaryTreeNode *pNodeA7 = ailee::BinaryTree::CreateBinaryTreeNode(7);

    ailee::BinaryTreeNode *pNodeB1 = ailee::BinaryTree::CreateBinaryTreeNode(1);
    ailee::BinaryTreeNode *pNodeB2 = ailee::BinaryTree::CreateBinaryTreeNode(4);
    ailee::BinaryTreeNode *pNodeB3 = ailee::BinaryTree::CreateBinaryTreeNode(5);

    ailee::BinaryTree::ConnectBinaryNodes(pNodeA1, pNodeA2, pNodeA3);
    ailee::BinaryTree::ConnectBinaryNodes(pNodeA2, pNodeA4, pNodeA5);
    ailee::BinaryTree::ConnectBinaryNodes(pNodeA5, pNodeA6, pNodeA7);

    ailee::BinaryTree::ConnectBinaryNodes(pNodeB1, pNodeB2, pNodeB3);

    test("test 01", pNodeA1, pNodeB1);
}

/**
 * @brief 树中节点含有分叉，树B不是树A的子节点。
 */
void test_02() {
    ailee::BinaryTreeNode *pNodeA1 = ailee::BinaryTree::CreateBinaryTreeNode(1);
    ailee::BinaryTreeNode *pNodeA2 = ailee::BinaryTree::CreateBinaryTreeNode(2);
    ailee::BinaryTreeNode *pNodeA3 = ailee::BinaryTree::CreateBinaryTreeNode(3);
    ailee::BinaryTreeNode *pNodeA4 = ailee::BinaryTree::CreateBinaryTreeNode(4);
    ailee::BinaryTreeNode *pNodeA5 = ailee::BinaryTree::CreateBinaryTreeNode(5);
    ailee::BinaryTreeNode *pNodeA6 = ailee::BinaryTree::CreateBinaryTreeNode(6);
    ailee::BinaryTreeNode *pNodeA7 = ailee::BinaryTree::CreateBinaryTreeNode(7);

    ailee::BinaryTreeNode *pNodeB1 = ailee::BinaryTree::CreateBinaryTreeNode(1);
    ailee::BinaryTreeNode *pNodeB2 = ailee::BinaryTree::CreateBinaryTreeNode(4);
    ailee::BinaryTreeNode *pNodeB3 = ailee::BinaryTree::CreateBinaryTreeNode(5);

    ailee::BinaryTree::ConnectBinaryNodes(pNodeA1, pNodeA2, pNodeA3);
    ailee::BinaryTree::ConnectBinaryNodes(pNodeA2, pNodeA4, pNodeA5);
    ailee::BinaryTree::ConnectBinaryNodes(pNodeA5, pNodeA6, pNodeA7);

    ailee::BinaryTree::ConnectBinaryNodes(pNodeB1, pNodeB2, pNodeB3);

    test("test 02", pNodeA1, pNodeB1);
}

/**
 * @brief 树中仅包含左子节点，树B是树A的子节点。
 */
void test_03() {
    ailee::BinaryTreeNode *pNodeA1 = ailee::BinaryTree::CreateBinaryTreeNode(1);
    ailee::BinaryTreeNode *pNodeA2 = ailee::BinaryTree::CreateBinaryTreeNode(2);
    ailee::BinaryTreeNode *pNodeA3 = ailee::BinaryTree::CreateBinaryTreeNode(3);
    ailee::BinaryTreeNode *pNodeA4 = ailee::BinaryTree::CreateBinaryTreeNode(4);
    ailee::BinaryTreeNode *pNodeA5 = ailee::BinaryTree::CreateBinaryTreeNode(5);

    ailee::BinaryTreeNode *pNodeB1 = ailee::BinaryTree::CreateBinaryTreeNode(2);
    ailee::BinaryTreeNode *pNodeB2 = ailee::BinaryTree::CreateBinaryTreeNode(3);
    ailee::BinaryTreeNode *pNodeB3 = ailee::BinaryTree::CreateBinaryTreeNode(4);

    ailee::BinaryTree::ConnectBinaryNodes(pNodeA1, pNodeA2, nullptr);
    ailee::BinaryTree::ConnectBinaryNodes(pNodeA2, pNodeA3, nullptr);
    ailee::BinaryTree::ConnectBinaryNodes(pNodeA3, pNodeA4, nullptr);
    ailee::BinaryTree::ConnectBinaryNodes(pNodeA4, pNodeA5, nullptr);

    ailee::BinaryTree::ConnectBinaryNodes(pNodeB1, pNodeB2, nullptr);
    ailee::BinaryTree::ConnectBinaryNodes(pNodeB2, pNodeB3, nullptr);

    test("test 03", pNodeA1, pNodeB1);
}

/**
 * @brief 树中仅包含右子节点，树B是树A的子节点。
 */
void test_04() {
    ailee::BinaryTreeNode *pNodeA1 = ailee::BinaryTree::CreateBinaryTreeNode(1);
    ailee::BinaryTreeNode *pNodeA2 = ailee::BinaryTree::CreateBinaryTreeNode(2);
    ailee::BinaryTreeNode *pNodeA3 = ailee::BinaryTree::CreateBinaryTreeNode(3);
    ailee::BinaryTreeNode *pNodeA4 = ailee::BinaryTree::CreateBinaryTreeNode(4);
    ailee::BinaryTreeNode *pNodeA5 = ailee::BinaryTree::CreateBinaryTreeNode(5);

    ailee::BinaryTreeNode *pNodeB1 = ailee::BinaryTree::CreateBinaryTreeNode(2);
    ailee::BinaryTreeNode *pNodeB2 = ailee::BinaryTree::CreateBinaryTreeNode(3);
    ailee::BinaryTreeNode *pNodeB3 = ailee::BinaryTree::CreateBinaryTreeNode(4);

    ailee::BinaryTree::ConnectBinaryNodes(pNodeA1, nullptr, pNodeA2);
    ailee::BinaryTree::ConnectBinaryNodes(pNodeA2, nullptr, pNodeA3);
    ailee::BinaryTree::ConnectBinaryNodes(pNodeA3, nullptr, pNodeA4);
    ailee::BinaryTree::ConnectBinaryNodes(pNodeA4, nullptr, pNodeA5);

    ailee::BinaryTree::ConnectBinaryNodes(pNodeB1, nullptr, pNodeB2);
    ailee::BinaryTree::ConnectBinaryNodes(pNodeB2, nullptr, pNodeB3);

    test("test 04", pNodeA1, pNodeB1);
}

/**
 * @brief 树中仅包含左子节点，树B不是树A的子节点。
 */
void test_05() {
    ailee::BinaryTreeNode *pNodeA1 = ailee::BinaryTree::CreateBinaryTreeNode(1);
    ailee::BinaryTreeNode *pNodeA2 = ailee::BinaryTree::CreateBinaryTreeNode(2);
    ailee::BinaryTreeNode *pNodeA3 = ailee::BinaryTree::CreateBinaryTreeNode(3);
    ailee::BinaryTreeNode *pNodeA4 = ailee::BinaryTree::CreateBinaryTreeNode(4);
    ailee::BinaryTreeNode *pNodeA5 = ailee::BinaryTree::CreateBinaryTreeNode(5);

    ailee::BinaryTreeNode *pNodeB1 = ailee::BinaryTree::CreateBinaryTreeNode(2);
    ailee::BinaryTreeNode *pNodeB2 = ailee::BinaryTree::CreateBinaryTreeNode(3);
    ailee::BinaryTreeNode *pNodeB3 = ailee::BinaryTree::CreateBinaryTreeNode(5);

    ailee::BinaryTree::ConnectBinaryNodes(pNodeA1, pNodeA2, nullptr);
    ailee::BinaryTree::ConnectBinaryNodes(pNodeA2, pNodeA3, nullptr);
    ailee::BinaryTree::ConnectBinaryNodes(pNodeA3, pNodeA4, nullptr);
    ailee::BinaryTree::ConnectBinaryNodes(pNodeA4, pNodeA5, nullptr);

    ailee::BinaryTree::ConnectBinaryNodes(pNodeB1, pNodeB2, nullptr);
    ailee::BinaryTree::ConnectBinaryNodes(pNodeB2, pNodeB3, nullptr);

    test("test 05", pNodeA1, pNodeB1);
}

/**
 * @brief 树中仅包含右子节点，树B不是树A的子节点。
 */
void test_06() {
    ailee::BinaryTreeNode *pNodeA1 = ailee::BinaryTree::CreateBinaryTreeNode(1);
    ailee::BinaryTreeNode *pNodeA2 = ailee::BinaryTree::CreateBinaryTreeNode(2);
    ailee::BinaryTreeNode *pNodeA3 = ailee::BinaryTree::CreateBinaryTreeNode(3);
    ailee::BinaryTreeNode *pNodeA4 = ailee::BinaryTree::CreateBinaryTreeNode(4);
    ailee::BinaryTreeNode *pNodeA5 = ailee::BinaryTree::CreateBinaryTreeNode(5);

    ailee::BinaryTreeNode *pNodeB1 = ailee::BinaryTree::CreateBinaryTreeNode(2);
    ailee::BinaryTreeNode *pNodeB2 = ailee::BinaryTree::CreateBinaryTreeNode(3);
    ailee::BinaryTreeNode *pNodeB3 = ailee::BinaryTree::CreateBinaryTreeNode(5);

    ailee::BinaryTree::ConnectBinaryNodes(pNodeA1, nullptr, pNodeA2);
    ailee::BinaryTree::ConnectBinaryNodes(pNodeA2, nullptr, pNodeA3);
    ailee::BinaryTree::ConnectBinaryNodes(pNodeA3, nullptr, pNodeA4);
    ailee::BinaryTree::ConnectBinaryNodes(pNodeA4, nullptr, pNodeA5);

    ailee::BinaryTree::ConnectBinaryNodes(pNodeB1, nullptr, pNodeB2);
    ailee::BinaryTree::ConnectBinaryNodes(pNodeB2, nullptr, pNodeB3);

    test("test 06", pNodeA1, pNodeB1);
}

/**
 * @brief A、B均为空树
 */
void test_07() {
    test("test 07", nullptr, nullptr);
}

/**
 * @brief A为空树
 */
void test_08() {
    ailee::BinaryTreeNode *pNodeB1 = ailee::BinaryTree::CreateBinaryTreeNode(1);
    ailee::BinaryTreeNode *pNodeB2 = ailee::BinaryTree::CreateBinaryTreeNode(4);
    ailee::BinaryTreeNode *pNodeB3 = ailee::BinaryTree::CreateBinaryTreeNode(5);

    ailee::BinaryTree::ConnectBinaryNodes(pNodeB1, pNodeB2, pNodeB3);

    test("test 08", nullptr, pNodeB1);
}

/**
 * @brief B为空树
 */
void test_09() {
    ailee::BinaryTreeNode *pNodeA1 = ailee::BinaryTree::CreateBinaryTreeNode(1);
    ailee::BinaryTreeNode *pNodeA2 = ailee::BinaryTree::CreateBinaryTreeNode(1);
    ailee::BinaryTreeNode *pNodeA3 = ailee::BinaryTree::CreateBinaryTreeNode(3);
    ailee::BinaryTreeNode *pNodeA4 = ailee::BinaryTree::CreateBinaryTreeNode(4);
    ailee::BinaryTreeNode *pNodeA5 = ailee::BinaryTree::CreateBinaryTreeNode(5);
    ailee::BinaryTreeNode *pNodeA6 = ailee::BinaryTree::CreateBinaryTreeNode(6);
    ailee::BinaryTreeNode *pNodeA7 = ailee::BinaryTree::CreateBinaryTreeNode(7);

    ailee::BinaryTree::ConnectBinaryNodes(pNodeA1, pNodeA2, pNodeA3);
    ailee::BinaryTree::ConnectBinaryNodes(pNodeA2, pNodeA4, pNodeA5);
    ailee::BinaryTree::ConnectBinaryNodes(pNodeA5, pNodeA6, pNodeA7);

    test("test 09", pNodeA1, nullptr);
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

    return 0;
}