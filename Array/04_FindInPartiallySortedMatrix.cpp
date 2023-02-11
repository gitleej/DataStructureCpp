//
// Created by AILEE on 2023/2/11.
// 题目4：二维数组中的查找
// 题目：在一个二维数组中，每一行都按照从左到右递增的顺序排列，每一列都按照从上到下递增的顺序排序，请完成一个函数，输入一个这样的二维数组和一个整数，判断该数组中是否含有该数字。
//

#include <iostream>

using namespace std;

bool FindInPartiallySortedMatrix(int* matrix, int rows, int cols, int num) {
    if (matrix == nullptr || rows <= 0 || cols <= 0) {
        return false;
    }


}

/**
 * @brief test
 * @param testName
 * @param matrix
 * @param rows 行
 * @param cols 列
 * @param num
 */
void test(const char* testName, int* matrix, int rows, int cols, int num) {
    cout << testName << endl;
}

/**
 * @brief 空指针
 */
void test_01() {
    test("test 01", nullptr, 0, 0, 0);
}

int main(int argc, char** argv) {
    return 0;
}
