//
// Created by AILEE on 2023/2/11.
// 题目54：二叉搜索树的第K个节点
// 题目：给定一棵二叉搜索树，请找出其中第K大的节点。
//

#include "BinaryTree.h"

#include <iostream>
#include <stack>

using namespace std;

ailee::BinaryTreeNode *KthNodeBinarySearchTreeIteratively(ailee::BinaryTreeNode *pRoot, unsigned int k) {
    if (pRoot == nullptr || k == 0) {
        return nullptr;
    }

    stack<ailee::BinaryTreeNode*> binaryTreeNodeStack;
    ailee::BinaryTreeNode *pNode = pRoot;
    while (pNode != nullptr || !binaryTreeNodeStack.empty()) {
        // 压入处理左子节点
        if (pNode != nullptr) {
            binaryTreeNodeStack.push(pNode);
            pNode = pNode->m_pLeft;
        } else { // 处理目标任务，压入右子节点。
            pNode = binaryTreeNodeStack.top();
            binaryTreeNodeStack.pop();

            ///////////////////////////////////////////////////
            if (k == 1) {
                return pNode;
            }
            k--;
            ///////////////////////////////////////////////////

            pNode = pNode->m_pRight;
        }
    }

    return nullptr;
}

ailee::BinaryTreeNode *KthNodeInBinarySearchTreeCore(ailee::BinaryTreeNode *pRoot, unsigned int &k) {
    ailee::BinaryTreeNode *pTarget = nullptr;

    // 中序遍历
    if (pRoot->m_pLeft != nullptr) {
        pTarget = KthNodeInBinarySearchTreeCore(pRoot->m_pLeft, k);
    }

    // 如果pTarget为空，则说明不在左子树
    if (pTarget == nullptr) {
        // 如果K为1，且pTarget为空，则说明目标节点为根节点。
        if (k == 1) {
            pTarget = pRoot;
        }
        k--;
    }

    if (pTarget == nullptr && pRoot->m_pRight != nullptr) {
        pTarget = KthNodeInBinarySearchTreeCore(pRoot->m_pRight, k);
    }

    return pTarget;
}

ailee::BinaryTreeNode *KthNodeInBinarySearchTree(ailee::BinaryTreeNode* pRoot, unsigned int k) {
    if (pRoot == nullptr || k == 0) {
        return nullptr;
    }

    return KthNodeInBinarySearchTreeCore(pRoot, k);
}

void test(const char *testName, ailee::BinaryTreeNode* pRoot, unsigned int k) {
    cout << testName << endl;

    ailee::BinaryTreeNode *pKthNode = nullptr;
    pKthNode = KthNodeInBinarySearchTree(pRoot, k);
    ailee::BinaryTree::PrintBinaryTreeNode(pKthNode);

    pKthNode = KthNodeBinarySearchTreeIteratively(pRoot, k);
    ailee::BinaryTree::PrintBinaryTreeNode(pKthNode);
}

//            10
//         /      \
//        6        14
//       /\        /\
//      4  8     12  16
void test_01_02()
{
    ailee::BinaryTreeNode* pNode10 = ailee::BinaryTree::CreateBinaryTreeNode(10);
    ailee::BinaryTreeNode* pNode6 = ailee::BinaryTree::CreateBinaryTreeNode(6);
    ailee::BinaryTreeNode* pNode14 = ailee::BinaryTree::CreateBinaryTreeNode(14);
    ailee::BinaryTreeNode* pNode4 = ailee::BinaryTree::CreateBinaryTreeNode(4);
    ailee::BinaryTreeNode* pNode8 = ailee::BinaryTree::CreateBinaryTreeNode(8);
    ailee::BinaryTreeNode* pNode12 = ailee::BinaryTree::CreateBinaryTreeNode(12);
    ailee::BinaryTreeNode* pNode16 = ailee::BinaryTree::CreateBinaryTreeNode(16);

    ailee::BinaryTree::ConnectBinaryNodes(pNode10, pNode6, pNode14);
    ailee::BinaryTree::ConnectBinaryNodes(pNode6, pNode4, pNode8);
    ailee::BinaryTree::ConnectBinaryNodes(pNode14, pNode12, pNode16);

    test("test 01", pNode10, 3);

    test("test 02", pNode10, 8);

    ailee::BinaryTree::DestroyBinaryTree(pNode4);
}

//               5
//              /
//             4
//            /
//           3
//          /
//         2
//        /
//       1
void test_03()
{
    ailee::BinaryTreeNode* pNode5 = ailee::BinaryTree::CreateBinaryTreeNode(5);
    ailee::BinaryTreeNode* pNode4 = ailee::BinaryTree::CreateBinaryTreeNode(4);
    ailee::BinaryTreeNode* pNode3 = ailee::BinaryTree::CreateBinaryTreeNode(3);
    ailee::BinaryTreeNode* pNode2 = ailee::BinaryTree::CreateBinaryTreeNode(2);
    ailee::BinaryTreeNode* pNode1 = ailee::BinaryTree::CreateBinaryTreeNode(1);

    ailee::BinaryTree::ConnectBinaryNodes(pNode5, pNode4, nullptr);
    ailee::BinaryTree::ConnectBinaryNodes(pNode4, pNode3, nullptr);
    ailee::BinaryTree::ConnectBinaryNodes(pNode3, pNode2, nullptr);
    ailee::BinaryTree::ConnectBinaryNodes(pNode2, pNode1, nullptr);

    test("test 03", pNode5, 5);

    ailee::BinaryTree::DestroyBinaryTree(pNode1);
}

// 1
//  \
//   2
//    \
//     3
//      \
//       4
//        \
//         5
void test_04()
{
    ailee::BinaryTreeNode* pNode1 = ailee::BinaryTree::CreateBinaryTreeNode(1);
    ailee::BinaryTreeNode* pNode2 = ailee::BinaryTree::CreateBinaryTreeNode(2);
    ailee::BinaryTreeNode* pNode3 = ailee::BinaryTree::CreateBinaryTreeNode(3);
    ailee::BinaryTreeNode* pNode4 = ailee::BinaryTree::CreateBinaryTreeNode(4);
    ailee::BinaryTreeNode* pNode5 = ailee::BinaryTree::CreateBinaryTreeNode(5);

    ailee::BinaryTree::ConnectBinaryNodes(pNode1, nullptr, pNode2);
    ailee::BinaryTree::ConnectBinaryNodes(pNode2, nullptr, pNode3);
    ailee::BinaryTree::ConnectBinaryNodes(pNode3, nullptr, pNode4);
    ailee::BinaryTree::ConnectBinaryNodes(pNode4, nullptr, pNode5);

    test("test 04", pNode1, 1);

    ailee::BinaryTree::DestroyBinaryTree(pNode1);
}

// 树中只有1个结点
void test_05()
{
    ailee::BinaryTreeNode* pNode1 = ailee::BinaryTree::CreateBinaryTreeNode(1);
    test("test 04", pNode1, 1);

    ailee::BinaryTree::DestroyBinaryTree(pNode1);
}

// 树中没有结点
void test_06()
{
    test("test 05", nullptr, 0);
}

int main(int argc, char** argv) {
    test_01_02();
    test_03();
    test_04();
    test_05();
    test_06();

    return 0;
}
