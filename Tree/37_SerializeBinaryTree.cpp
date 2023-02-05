//
// Created by AILEE on 2023/2/4.
// 题目27：序列化二叉树
// 题目：请实现两个函数分别用来序列化和反序列化二叉树。
//

#include "BinaryTree.h"

#include <iostream>
#include <fstream>

using namespace std;

void printSerials(const char* fileName) {
    ifstream inFile;
    inFile.open(fileName, ios::in);
    if (!inFile.is_open()) {
        cout << "open file failed." << endl;
    }
    string line;
    while (getline(inFile,line)) {
        line.pop_back();
        cout << line << endl;
    }

    inFile.close();
}

bool readStream(istream& stream, int* number)
{
    if(stream.eof())
        return false;

    char buffer[32];
    buffer[0] = '\0';

    char ch;
    stream >> ch;
    int i = 0;
    while(!stream.eof() && ch != ',')
    {
        buffer[i++] = ch;
        stream >> ch;
    }

    bool isNumeric = false;
    if(i > 0 && buffer[0] != '$')
    {
        *number = atoi(buffer);
        isNumeric = true;
    }

    return isNumeric;
}

void SerializeBinaryTreeRecursivelyCore(ailee::BinaryTreeNode *pRoot, ostream &stream) {
    // 到达叶子节点
    if (pRoot == nullptr) {
        stream << "$,";
        return;
    }

    stream << pRoot->m_nValue << ",";
    SerializeBinaryTreeRecursivelyCore(pRoot->m_pLeft, stream);
    SerializeBinaryTreeRecursivelyCore(pRoot->m_pRight, stream);
}

void SerializeBinaryTreeRecursively(ailee::BinaryTreeNode *pRoot, ostream &stream) {
    if (pRoot == nullptr) {
        cout << "this tree is nullptr." << endl;
        return;
    }

    SerializeBinaryTreeRecursivelyCore(pRoot, stream);
}

void DeserializeBinaryTreeRecursively(ailee::BinaryTreeNode** pRoot, istream &stream) {
    int number;
    if (readStream(stream, &number)) {
        *pRoot = new ailee::BinaryTreeNode();
        (*pRoot)->m_nValue = number;
        (*pRoot)->m_pLeft = nullptr;
        (*pRoot)->m_pRight = nullptr;
        // 构建左节点
        DeserializeBinaryTreeRecursively(&((*pRoot)->m_pLeft), stream);
        // 构建右节点
        DeserializeBinaryTreeRecursively(&((*pRoot)->m_pRight), stream);
    }
}

void test(const char* testName, ailee::BinaryTreeNode* pRoot) {
    cout << testName << endl;

    ofstream outFile;
    ifstream inFile;
    const char *fileName = "test.txt";
    ailee::BinaryTreeNode *pNewRoot = nullptr;
    cout << "Recursively" << endl;
    outFile.open(fileName);
    SerializeBinaryTreeRecursively(pRoot, outFile);
    outFile.close();

    printSerials(fileName);

    inFile.open(fileName);
    DeserializeBinaryTreeRecursively(&pNewRoot, inFile);
    ailee::BinaryTree::PrintBinaryTree(pNewRoot);
    inFile.close();

    ailee::BinaryTree::DestroyBinaryTree(pRoot);
    ailee::BinaryTree::DestroyBinaryTree(pNewRoot);
}

/**
 * @brief 空树
 */
void test_01() {
    test("test 01", nullptr);
}

/**
 * @brief 只有一个节点的树。
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
    ailee::BinaryTreeNode *pNode8 = ailee::BinaryTree::CreateBinaryTreeNode(8);
    ailee::BinaryTreeNode *pNode9 = ailee::BinaryTree::CreateBinaryTreeNode(9);
    ailee::BinaryTreeNode *pNode10 = ailee::BinaryTree::CreateBinaryTreeNode(10);
    ailee::BinaryTreeNode *pNode11 = ailee::BinaryTree::CreateBinaryTreeNode(11);
    ailee::BinaryTreeNode *pNode12 = ailee::BinaryTree::CreateBinaryTreeNode(12);
    ailee::BinaryTreeNode *pNode13 = ailee::BinaryTree::CreateBinaryTreeNode(13);
    ailee::BinaryTreeNode *pNode14 = ailee::BinaryTree::CreateBinaryTreeNode(14);
    ailee::BinaryTreeNode *pNode15 = ailee::BinaryTree::CreateBinaryTreeNode(15);

    ailee::BinaryTree::ConnectBinaryNodes(pNode1, pNode2, pNode3);
    ailee::BinaryTree::ConnectBinaryNodes(pNode2, pNode4, pNode5);
    ailee::BinaryTree::ConnectBinaryNodes(pNode3, pNode6, pNode7);
    ailee::BinaryTree::ConnectBinaryNodes(pNode4, pNode8, pNode9);
    ailee::BinaryTree::ConnectBinaryNodes(pNode5, pNode10, pNode11);
    ailee::BinaryTree::ConnectBinaryNodes(pNode6, pNode12, pNode13);
    ailee::BinaryTree::ConnectBinaryNodes(pNode7, pNode14, pNode15);

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