//
// Created by AILEE on 2023/2/12.
// 题目21：调整数组顺序使奇数位于偶数前面
// 题目：输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有奇数位于数组的前半部分，所有偶数位于数组的后半部分。
//

#include <iostream>

using namespace std;

bool isEven(int num) {
    return ((num % 2) == 0);
}

/**
 * @brief 利用双指针来控制移动
 * @param array
 * @param length
 * @param func
 */
void Reorder(int *array, int length, bool (*func)(int)) {
    if (array == nullptr || func == nullptr || length <= 0) {
        cout << "please check input" << endl;
        return;
    }

    int *pFront = array;                ///< 前指针
    int *pBack = array + length - 1;    ///< 后指针
    while (pFront < pBack) {
        // 向后移动前指针，如果前指针指向的数字不是偶数，则向后移动指针
        while (pFront < pBack && !func(*pFront)) {
            pFront++;
        }

        // 向前移动后指针，如果后指针指向的数字是偶数，则向前移动后指针
        while (pFront < pBack && func(*pBack)) {
            pBack--;
        }

        // 交换前后指针数字
        if (pFront < pBack) {
            int temp = *pFront;
            *pFront = *pBack;
            *pBack = temp;
        }
    }
}

void ReorderArray(int* array, int length) {
    Reorder(array, length, isEven);
}

void test(const char *testName, int* array, int length) {
    cout << testName << endl;

    ReorderArray(array, length);

    for (int i = 0; i < length; ++i) {
        cout << array[i] << " ";
    }

    cout << endl;
}

/**
 * @brief 空指针
 */
void test_01() {
    test("test 01", nullptr, 0);
}

/**
 * @brief 数组中只有一个元素
 */
void test_02() {
    const int length = 1;
    int array[length] = {1};

    test("test 02", array, length);
}

/**
 * @brief 奇数偶数交替出现
 */
void test_03() {
    const int length = 8;
    int array[length] = {1, 2, 3, 4, 5, 6, 7, 8};

    test("test 03", array, length);
}

/**
 * @brief 奇数都在偶数后面
 */
void test_04() {
    const int length = 8;
    int array[length] = {2, 4, 6, 8, 1, 3, 5, 7};

    test("test 04", array, length);
}

/**
 * @brief 偶数都在奇数前面
 */
void test_05() {
    const int length = 8;
    int array[length] = {1, 3, 5, 7, 2, 4, 6, 8};

    test("test 05", array, length);
}

int main(int argc, char **argv) {
    test_01();
    test_02();
    test_03();
    test_04();
    test_05();

    return 0;
}
