//
// Created by AILEE on 2023/2/9.
// 题目33：二叉搜索树的后序遍历序列
// 题目：输入一个整数数组，判断该数组是否为二叉搜索树的后续遍历序列。
// 二叉搜索树：
// 1.若它的左子树不为空，左子树上所有节点的值都小于它的根节点
// 2.若它的右子树不为空，右子树上所有的节点的值都大于它的根节点。
//

#include "BinaryTree.h"

#include <iostream>

using namespace std;

bool VerifySequenceOfBinarySearchTreeCore(int* pArray, int length) {
    if (pArray == nullptr || length <= 0) {
        return false;
    }

    int rootValue = pArray[length - 1];

    // 在序列中搜索节点值小于根节点的值
    int leftRootIndex = 0;
    for (leftRootIndex;  leftRootIndex < length - 1; leftRootIndex++) {
        if (pArray[leftRootIndex] > rootValue) {
            break;
        }
    }

    // 找右子树中大于根节点的值
    int rightRootIndex = leftRootIndex;
    for (rightRootIndex; rightRootIndex < length - 1; rightRootIndex++) {
        if (pArray[rightRootIndex] < rootValue){
            return false;
        }
    }

    // 递归调用判断左子树是否为二叉搜索树
    bool left = true;
    if (leftRootIndex > 0) {
        left = VerifySequenceOfBinarySearchTreeCore(pArray, leftRootIndex);
    }

    bool right = true;
    if (leftRootIndex < length - 1) {
        right = VerifySequenceOfBinarySearchTreeCore(pArray + leftRootIndex, length - leftRootIndex - 1);
    }

    return left && right;
}

bool VerifySequenceOfBinarySearchTree(int* pArray, int length) {
    if (pArray == nullptr) {
        cout << "this array is nullptr" << endl;
        return false;
    }

    return VerifySequenceOfBinarySearchTreeCore(pArray, length);
}

void test(const char* testName, int* pArray, int length) {
    cout << testName << endl;

    cout << VerifySequenceOfBinarySearchTree(pArray, length) << endl;

    delete[] pArray;
}

/**
 * @brief 空数组
 */
void test_01() {
    test("test 01", nullptr, 0);
}

/**
 * @brief 只有一个节点的树
 */
void test_02() {
    const int length = 1;
    int array[length] = {1};
    test("test 02", array, length);
}

/**
 * @brief 完全二叉树
 */
void test_03() {
    const int length = 7;
    int array[length] = {5, 7, 6, 9, 11, 10, 8};
    test("test 03", array, length);
}

/**
 * @brief 只包含左子节点的树
 */
void test_04() {
    const int length = 5;
    int array[length] = {1, 2, 3, 4, 5};
    test("test 04", array, length);
}

/**
 * @brief 只包含右子节点的树
 */
void test_05() {
    const int length = 5;
    int array[length] = {9, 8, 7, 6, 5};
    test("test 05", array, length);
}

/**
 * @brief 完全二叉树
 */
void test_06() {
    const int length = 7;
    int array[length] = {5, 10, 6, 9, 7, 11, 8};
    test("test 06", array, length);
}

/**
 * @brief 只包含左子节点的树
 */
void test_07() {
    const int length = 5;
    int array[length] = {1, 5, 2, 4, 3};
    test("test 07", array, length);
}

/**
 * @brief 只包含右子节点的树
 */
void test_08() {
    const int length = 5;
    int array[length] = {8, 5, 7, 6, 9};
    test("test 08", array, length);
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

    return 0;
}