//
// Created by AILEE on 2023/2/10.
//

#include "BinaryTree.h"

#include <iostream>

using namespace std;

void ConvertNode(ailee::BinaryTreeNode *pRoot, ailee::BinaryTreeNode **pLastNodeInList) {
    // check input
    if (pRoot == nullptr) {
        return;
    }

    ailee::BinaryTreeNode *pCurrent = pRoot;
    if (pCurrent->m_pLeft != nullptr) {
        ConvertNode(pCurrent->m_pLeft, pLastNodeInList);
    }

    // 左子节点指向前一个指针，右子节点指向后一个指针
    pCurrent->m_pLeft = *pLastNodeInList;
    if (*pLastNodeInList != nullptr) {
        (*pLastNodeInList)->m_pRight = pCurrent;
    }

    // 更新链表的最后一个指针为当前指针
    *pLastNodeInList = pCurrent;
    if (pCurrent->m_pRight != nullptr) {
        ConvertNode(pCurrent->m_pRight, pLastNodeInList);
    }
}

ailee::BinaryTreeNode *ConvertBinarySearchTree2List(ailee::BinaryTreeNode *pRoot) {
    if (pRoot == nullptr){
        cout << "this tree is nullptr" << endl;
        return nullptr;
    }

    // 指向链表最后一个节点的指针
    ailee::BinaryTreeNode *pLastNodeInList = nullptr;

    ConvertNode(pRoot, &pLastNodeInList);
    ailee::BinaryTreeNode *pHeadNodeInList = pLastNodeInList;

    while (pHeadNodeInList != nullptr && pHeadNodeInList->m_pLeft != nullptr) {
        pHeadNodeInList = pHeadNodeInList->m_pLeft;
    }

    return pHeadNodeInList;
}

void test(const char* testName, ailee::BinaryTreeNode* pRoot) {
    cout << testName << endl;

    ailee::BinaryTreeNode *pHeadNodeInList = ConvertBinarySearchTree2List(pRoot);
    ailee::BinaryTree::PrintBinaryTree(pHeadNodeInList);
}

//            10
//         /      \
//        6        14
//       /\        /\
//      4  8     12  16
void test_01()
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

    test("test 01", pNode10);

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
void test_02()
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

    test("test 02", pNode5);

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
void test_03()
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

    test("test 03", pNode1);

    ailee::BinaryTree::DestroyBinaryTree(pNode1);
}

// 树中只有1个结点
void test_04()
{
    ailee::BinaryTreeNode* pNode1 = ailee::BinaryTree::CreateBinaryTreeNode(1);
    test("test 04", pNode1);

    ailee::BinaryTree::DestroyBinaryTree(pNode1);
}

// 树中没有结点
void test_05()
{
    test("test 05", nullptr);
}


int main(int argc, char** argv) {
    test_01();
    test_02();
    test_03();
    test_04();
    test_05();

    return 0;
}