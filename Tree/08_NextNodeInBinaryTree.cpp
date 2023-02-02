//
// Created by AILEE on 2023/2/2.
// 题目8：二叉树的下一个节点
// 题目：给定一颗二叉树和其中一个节点，如何找出中序遍历的下一个节点？树中的节点除了有两个分别指向左、右叶子节点的指针，还有一个指向父节点的指针。
//

#include <iostream>

using namespace std;

/**
 * @brief define special binary tree node data struct
 */
typedef struct BinaryTreeNodeType{
    int m_nValue;
    BinaryTreeNodeType* m_pLeft;
    BinaryTreeNodeType* m_pRight;
    BinaryTreeNodeType* m_pParent;
} BinaryTreeNode;

BinaryTreeNode *createBinaryTreeNode(int value) {
    BinaryTreeNode *pNode = new BinaryTreeNode();
    pNode->m_nValue = value;
    pNode->m_pLeft = pNode->m_pRight = pNode->m_pParent = nullptr;

    return pNode;
}

void connectBinaryTreeNode(BinaryTreeNode* pParent, BinaryTreeNode* pLeft, BinaryTreeNode* pRight) {
    if (pParent != nullptr) {
        pParent->m_pLeft = pLeft;
        pParent->m_pRight = pRight;

        if (pLeft != nullptr) {
            pLeft->m_pParent = pParent;
        }
        if (pRight != nullptr) {
            pRight->m_pParent = pParent;
        }
    }
}

void printBinaryTreeNode( const BinaryTreeNode* pNode) {
    if (pNode != nullptr) {
        cout << "the value of this node is: " << pNode->m_nValue << endl;
        if (pNode->m_pLeft != nullptr) {
            cout << "the value of its left node is: " <<pNode->m_pLeft->m_nValue << endl;
        } else {
            cout << "its left node is nullptr" << endl;
        }
        if (pNode->m_pRight != nullptr) {
            cout << "the value of its right node is: " <<pNode->m_pRight->m_nValue << endl;
        } else {
            cout << "its right node is nullptr" << endl;
        }
    } else {
        cout << "this node is nullptr" << endl;
    }
}

void printBinaryTree(const BinaryTreeNode* pRoot) {
    printBinaryTreeNode(pRoot);

    if (pRoot != nullptr) {
        if (pRoot->m_pLeft != nullptr) {
            printBinaryTree(pRoot->m_pLeft);
        }
        if (pRoot->m_pRight != nullptr) {
            printBinaryTree(pRoot->m_pRight);
        }
    }
}

void destroyBinaryTree(BinaryTreeNode* pRoot) {
    if (pRoot != nullptr) {
        BinaryTreeNode *pLeft = pRoot->m_pLeft;
        BinaryTreeNode *pRight = pRoot->m_pRight;

        delete pRoot;
        pRoot = nullptr;

        destroyBinaryTree(pLeft);
        destroyBinaryTree(pRight);
    }
}

BinaryTreeNode *NextNodeInBinaryTree(BinaryTreeNode* pNode) {
    if (pNode == nullptr) {
        return nullptr;
    }

    BinaryTreeNode *pNext = new BinaryTreeNode();

    if (pNode->m_pRight != nullptr) {
        BinaryTreeNode *pRight = pNode->m_pRight;
        while (pRight->m_pLeft != nullptr) {
            pRight = pRight->m_pLeft;
        }

        pNext = pRight;
    } else if (pNode->m_pParent != nullptr) {
        BinaryTreeNode *pCurrent = pNode;
        BinaryTreeNode *pParent = pNode->m_pParent;
        while (pParent != nullptr && pCurrent == pParent->m_pRight) {
            pCurrent = pParent;
            pParent = pCurrent->m_pParent;
        }

        pNext = pParent;
    }

    return pNext;
}

void test(const char* testName, BinaryTreeNode* pNode) {
    cout << testName << endl;

    BinaryTreeNode *pNext = NextNodeInBinaryTree(pNode);
    printBinaryTreeNode(pNext);
}

void test_01_09() {
    BinaryTreeNode *pNode1 = createBinaryTreeNode(1);
    BinaryTreeNode *pNode2 = createBinaryTreeNode(2);
    BinaryTreeNode *pNode3 = createBinaryTreeNode(3);
    BinaryTreeNode *pNode4 = createBinaryTreeNode(4);
    BinaryTreeNode *pNode5 = createBinaryTreeNode(5);
    BinaryTreeNode *pNode6 = createBinaryTreeNode(6);
    BinaryTreeNode *pNode7 = createBinaryTreeNode(7);
    BinaryTreeNode *pNode8 = createBinaryTreeNode(8);
    BinaryTreeNode *pNode9 = createBinaryTreeNode(9);

    connectBinaryTreeNode(pNode1, pNode2, pNode3);
    connectBinaryTreeNode(pNode2, pNode4, pNode5);
    connectBinaryTreeNode(pNode3, pNode6, pNode7);
    connectBinaryTreeNode(pNode5, pNode8, pNode9);

    // test
    test("test 01", pNode1);
    test("test 02", pNode2);
    test("test 03", pNode3);
    test("test 04", pNode4);
    test("test 05", pNode5);
    test("test 06", pNode6);
    test("test 07", pNode7);
    test("test 08", pNode8);
    test("test 09", pNode9);

    destroyBinaryTree(pNode1);
}

int main(int argc, char** argv) {
    test_01_09();

    return 0;
}