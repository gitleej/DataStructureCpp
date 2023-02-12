//
// Created by AILEE on 2023/2/12.
// 题目11：旋转数组中的最小数字
// 题目：把一个数组最开始的几个元素搬到末尾，我们称之为数组的旋转，输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素，如{34512}为{12345}的一个旋转，该数组的最小值为1.
//

#include <iostream>

using namespace std;

int MinNumberInRotatedArray(int *array, int length) {
    if (array == nullptr || length <= 0) {
        return -1;
    }

    int start = 0;
    int end = length - 1;
    int result = 0;
    while (array[start] >= array[end]) {
        // 如果首位相遇，则尾部位置的数为目标数
        if (end - start == 1) {
            result = array[end];
            break;
        }

        // 特殊情况，数组中有相同的元素
        if (array[start] == array[end]) {
            result = array[start];
            for (int i = 0; i < length; ++i) {
                if (array[i] <= result) {
                    result = array[i];
                }
            }
            break;
        }
        // 数组中无重复元素
        int middle = (end + start) >> 1;
        // 如果前面的数小于中间的数，则最小值在后面，更新前端索引值到中间。
        if (array[start] <= array[middle]) {
            start = middle;
        } else if (array[middle] <= array[end]){ // 如果中间的数小于后面的数，则最小值在前面，更新末端索引值到中间
            end = middle;
        }
    }

    return result;
}

void test(const char *testName, int *array, int length) {
    cout << testName << endl;

    int result = MinNumberInRotatedArray(array, length);
    if (result != -1) {
        cout << result << endl;
    }
}

/**
 * @brief 空指针
 */
void test_01() {
    test("test 01", nullptr, 0);
}

/**
 * @brief 典型输入，单调递增数组的旋转
 */
void test_02() {
    const int length = 5;
    int array[length] = { 3, 4, 5, 1, 2 };

    test("test 02", array, length);
}

/**
 * @brief 有重复数字，且重复数字为最小数字
 */
void test_03() {
    const int length = 6;
    int array[length] = { 3, 4, 5, 1, 1, 2 };

    test("test 03", array, length);
}

/**
 * @brief 有重复数字，且重复数字不是第一个也不是最后一个数字
 */
void test_04() {
    const int length = 6;
    int array[length] = { 3, 4, 5, 1, 2, 2 };

    test("test 04", array, length);
}

/**
 * @brief 有重复数字，且重复数字是第一个和最后一个数字
 */
void test_05() {
    const int length = 5;
    int array[length] = { 1, 0, 1, 1, 1 };

    test("test 05", array, length);
}

/**
 * @brief 单调升序数组，旋转0个元素，也就是单调升序数组本身
 */
void test_06() {
    const int length = 5;
    int array[length] = { 1, 2, 3, 4, 5};

    test("test 06", array, length);
}

void test_07() {
    const int length = 1;
    int array[length] = {1};

    test("test 07", array, 1);
}

int main(int argc, char** argv) {
    test_01();
    test_02();
    test_03();
    test_04();
    test_05();
    test_06();
    test_07();

    return 0;
}

