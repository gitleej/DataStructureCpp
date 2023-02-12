//
// Created by AILEE on 2023/2/12.
// 题目39：数组中出现次数超过一半的数字
// 题目：数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
//

#include <iostream>

using namespace std;

int MoreThanHalfNumberInArray(int* array, int length) {
    // check data input
    if (array == nullptr || length <= 0) {
        cout << "please check input data" << endl;
        return -1;
    }

    int result = array[0];
    int count = 1;
    for (int i = 0; i < length; i++) {
        if (count == 0) {
            result = array[i];
            count = 1;
        }

        if (array[i] == result) {
            count++;
        } else {
            count--;
        }
    }

    // 检查结果是否正确
    count = 0;
    for (int i = 0; i < length; i++) {
        if (array[i] == result) {
            count++;
        }
    }

    if (count * 2 > length) {
        return result;
    }

    return -1;
}

void test(const char *testName, int* array, int length) {
    cout << testName << endl;

    int result = MoreThanHalfNumberInArray(array, length);
    if (result != -1) {
        cout << result << endl;
    } else {
        cout << "error" << endl;
    }
}

/**
 * @brief 空数组
 */
void test_01() {
    test("test 01", nullptr, 0);
}

/**
 * @brief 数组中存在超过一半的数字
 */
void test_02() {
    const int length = 9;
    int array[length] = {1, 2, 3, 2, 2, 2, 5, 4, 2};

    test("test 02", array, length);
}

/**
 * @brief 数组中不存在超过一半的数字
 */
void test_03() {
    const int length = 9;
    int array[length] = {1, 2, 3, 4, 2, 2, 5, 4, 2};

    test("test 03", array, length);
}

void test_04() {
    const int length = 1;
    int array[length] = {1};

    test("test 04", array, length);
}

int main(int argc, char **argv) {
    test_01();
    test_02();
    test_03();
    test_04();

    return 0;
}