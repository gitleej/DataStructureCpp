//
// Created by AILEE on 2023/2/11.
// 题目03_01：找出数组中重复的数字
// 题目：在一个长度为n的数组中所有数字都在0-(n-1)范围内，数组中某些数字是重复的，但不知道哪些数字重复了，也不知道每个数字重复了多少次，请找出数组中任意一个重复的数字。
//

#include <iostream>

using namespace std;

bool DuplicationInArray(int* array, int length, int* duplicationNum) {
    if (array == nullptr || length <= 0) {
        return false;
    }

    // 检查是否存在越界值
    for (int i = 0; i < length; i++) {
        if (array[i] < 0 || array[i] > (length -1)) {
            return false;
        }
    }

    for (int i = 0; i < length; i++) {
        while (array[i] != i) {
            // 当前下标对应的值与当前下表对应的值为下标对应的值相等时，则存在重复的数字，否则将当前下标对应的值交换到当前值对应的下标位置。
            if (array[i] == array[array[i]]) {
                *duplicationNum = array[i];
                return true;
            }

            // 交换元素
            int temp = array[i];
            array[i] = array[array[i]];
            array[temp] = temp;
        }
    }

    return false;
}

void test(const char* testName, int* array, int length) {
    cout << testName << endl;
    int duplicationNum = 0;
    bool isDuplication = false;

    if (DuplicationInArray(array, length, &duplicationNum)) {
        cout << "the duplication number is: " << duplicationNum << endl;
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
 * @brief 无重复数字
 */
void test_02() {
    const int length = 10;
    int array[length] = {9, 7, 6, 4 , 5, 8, 1 , 3, 0, 2};

    test("test 02", array, length);
}

/**
 * @brief 无重复，但包含越界数字
 */
void test_03() {
    const int length = 10;
    int array[length] = {9, 10, 6, 4 , 5, 8, 1 , 3, 0, 2};

    test("test 03", array, length);
}

/**
 * @brief 存在一个重复数字
 */
void test_04() {
    const int length = 10;
    int array[length] = {9, 8, 6, 4 , 7, 8, 1 , 3, 0, 2};

    test("test 04", array, length);
}

/**
 * @brief 存在多个重复数字
 */
void test_05() {
    const int length = 10;
    int array[length] = {9, 8, 7, 3 , 7, 8, 1 , 3, 0, 2};

    test("test 05", array, length);
}

int main(int argc, char** argv) {
    test_01();
    test_02();
    test_03();
    test_04();
    test_05();

    return 0;
}