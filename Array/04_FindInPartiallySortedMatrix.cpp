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

    int row = 0;
    int col = cols - 1;
    while (row < rows && col >= 0) {
        if (matrix[row * cols + col] > num) {
            col--;
        } else if (matrix[row * cols + col] == num) {
            return true;
        } else {
            row++;
        }
    }

    return false;
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

    if (FindInPartiallySortedMatrix(matrix, rows, cols, num)) {
        cout << "true" << endl;
    } else {
        cout << "false" <<endl;
    }
}

/**
 * @brief 空指针
 */
void test_01() {
    test("test 01", nullptr, 0, 0, 0);
}

/**
 * @brief 要查找的数在数组中
 */
void test_02() {
    const int rows = 4;
    const int cols = 4;
    int matrix[rows][cols] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};

    test("test 02", (int *)matrix, rows, cols, 7);
}

/**
 * @brief 要查找的数不在数组中
 */
void test_03() {
    const int rows = 4;
    const int cols = 4;
    int matrix[rows][cols] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};

    test("test 03", (int *)matrix, rows, cols, 16);
}

/**
 * @brief 要查找的数是最小数字
 */
void test_04() {
    const int rows = 4;
    const int cols = 4;
    int matrix[rows][cols] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};

    test("test 04", (int *)matrix, rows, cols, 1);
}

/**
 * @brief 要查找的数是最大数字
 */
void test_05() {
    const int rows = 4;
    const int cols = 4;
    int matrix[rows][cols] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};

    test("test 05", (int *)matrix, rows, cols, 15);
    test("test 06", (int *)matrix, rows, cols, 0);
    test("test 07", (int *)matrix, rows, cols, 17);
}

int main(int argc, char** argv) {
    test_01();
    test_02();
    test_03();
    test_04();
    test_05();

    return 0;
}
