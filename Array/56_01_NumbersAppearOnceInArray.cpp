//
// Created by AILEE on 2023/2/14.
// 题目56_01：数组中只出现一次的两个数字
// 题目：一个整形数组中，除了两个数字，其他数字都出现了两次，请写程序找出这两个只出现一次的数字。
//

#include <iostream>

using namespace std;

/**
 * @brief 查找数字二进制中最右边为1的位置
 * @param number
 * @return
 */
unsigned int FindFirstBits1(int number) {
    unsigned int index = 0;
    for (int i = 0; (i < 8 * sizeof(int)) && ((number & 1) == 0); ++i) {
        number = number >> 1;
        index++;
    }

    return index;
}

/**
 * @brief 检查当前位是否为1
 * @param number
 * @param index
 * @return
 */
bool IsBit1(int number, unsigned int index) {
    number = number >> index;
    return (number & 1);
}

void NumbersAppearOnceInArray(int* array, int length, int *pNumber1, int* pNumber2) {
    bool isFind = false;
    if (array == nullptr || length <= 0) {
        cout << "please check input" << endl;
        return;
    }

    // 异或遍历数组
    int resultXOR = 0;
    for (int i = 0; i < length; ++i) {
        resultXOR ^= array[i];
    }

    if (resultXOR == 0) {
        cout << "There is no number that appears only once in the array." << endl;
        return;
    }

    // 查找异或结果中最右边不为0的值，将数组划分为两部分，一部分为当前位为1，一部分为当前位为0
    unsigned int index = FindFirstBits1(resultXOR);

    *pNumber1 = 0;
    *pNumber2 = 0;
    for (int i = 0; i < length; ++i) {
        if (IsBit1(array[i], index)) {
            *pNumber1 ^= array[i];
        } else {
            *pNumber2 ^= array[i];
        }
    }
}

void test(const char *testName, int* array, int length) {
    cout << testName << endl;

    int number1;
    int number2;

    NumbersAppearOnceInArray(array, length, &number1, &number2);
    cout << number1 << "\t" << number2 << endl;
}

void test_01() {
    test("test 01", nullptr, 0);
}

void test_02() {
    const int length = 1;
    int array[length] = {5};
    test("test 02", array, length);
}

void test_03() {
    const int length = 2;
    int array[length] = {5, 5};
    test("test 03", array, length);
}

void test_04() {
    const int length = 8;
    int array[length] = {5, 5, 4, 4, 2, 3, 3, 8};
    test("test 04", array, length);
}

int main(int argc, char** argv) {
    test_01();
    test_02();
    test_03();
    test_04();

    return 0;
}