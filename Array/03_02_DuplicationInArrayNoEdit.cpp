//
// Created by AILEE on 2023/2/11.
// 题目03_02：不修改数组找出重复的数字
// 题目：有一个长度为n+1的数组，数组里的所有数字都在1-n的范围内，所以数组中至少有一个数字是重复的，请找出数组中任意一个重复的数字，但不能修改数组的输入。
//

#include <iostream>

using namespace std;

/**
 * @brief 统计在start 到 end范围内的数字个数
 * @param array
 * @param length
 * @param start
 * @param end
 * @return
 */
int CounterNum(const int *array, int length, int start, int end) {
    if (array == nullptr) {
        return 0;
    }

    int count = 0;
    for (int i = 0; i < length; i++) {
        if (array[i] >= start && array[i] <= end) {
            count++;
        }
    }

    return count;
}

int FindDuplicationInArrayNoEdit(const int *array, int length) {
    // 检查输入
    if (array == nullptr || length <= 0) {
        return -1;
    }

    for (int i = 0; i < length; i++) {
        if (array[i] > (length - 1)) {
            return -1;
        }
    }

    int start = 1;
    int end = length - 1;
    while (start <= end) {
        int middle = ((end - start) >> 1) + start;
        // 统计start到middle范围内数字的个数
        int count = CounterNum(array, length, start, middle);

        // 头尾相连
        if (start == end) {
            // 重复的数字就是start
            if (count > 1) {
                return start;
            }
        }

        // 更新数字范围
        if (count > (middle - start + 1)) {
            end = middle;
        } else {
            start = middle + 1;
        }
    }

    return -1;
}

void test(const char *testName, const int* array, int length) {
    cout << testName << endl;

    int duplicationNum = FindDuplicationInArrayNoEdit(array, length);
    if (duplicationNum != -1) {
        cout << duplicationNum << endl;
    } else {
        cout << "There are no duplicate numbers in this array." << endl;
    }
}

/**
 * @brief 空指针
 */
void test_01() {
    test("test 01", nullptr, 0);
}

/**
 * @brief 多个重复的数字
 */
void test_02() {
    const int length = 8;
    int array[length] = { 2, 3, 5, 4, 3, 2, 6, 7 };

    test("test 02", array, length);
}

/**
 * @brief 一个重复的数字
 */
void test_03() {
    const int length = 8;
    int array[length] = { 3, 2, 1, 4, 4, 5, 6, 7 };

    test("test 03", array, length);
}

/**
 * @brief 重复的数字是数组中最小的数字
 */
void test_04() {
    const int length = 9;
    int array[length] = { 1, 2, 3, 4, 5, 6, 7, 1, 8 };

    test("test 04", array, length);
}

/**
 * @brief 重复的数字是数组中最大的数字
 */
void test_05() {
    const int length = 9;
    int array[length] = { 1, 7, 3, 4, 5, 6, 8, 2, 8 };

    test("test 05", array, length);
}

/**
 * @brief 数组中只有两个数字
 */
void test_06() {
    const int length = 2;
    int array[length] = { 1, 1 };

    test("test 06", array, length);
}

/**
 * @brief 重复的数字位于数组当中
 */
void test_07() {
    const int length = 8;
    int array[length] = { 3, 2, 1, 3, 4, 5, 6, 7 };

    test("test 07", array, length);
}

/**
 * @brief 多个重复的数字
 */
void test_08() {
    const int length = 7;
    int array[length] = { 1, 2, 2, 6, 4, 5, 6 };

    test("test 08", array, length);
}

/**
 * @brief 一个数字重复三次
 */
void test_09() {
    const int length = 7;
    int array[length] = { 1, 2, 2, 6, 4, 5, 2 };

    test("test 09", array, length);
}

/**
 * @brief 没有重复的数字
 */
void test_10() {
    const int length = 6;
    int array[length] = { 1, 2, 6, 4, 5, 3 };

    test("test 10", array, length);
}

int main(int argc, char **argv) {
    test_01();
    test_02();
    test_03();
    test_04();
    test_05();
    test_06();
    test_07();
    test_08();
    test_09();
    test_10();

    return 0;
}
