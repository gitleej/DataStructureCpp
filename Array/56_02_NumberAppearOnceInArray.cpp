//
// Created by AILEE on 2023/2/14.
// 题目56_02：数组中唯一只出现一次的数字
// 题目：在一个数组中，除了一个数字只出现一次之外，其余数字都出现了三次，找出这个只出现一次的数字。
//

#include <iostream>
#include <exception>

using namespace std;

/**
 * @brief 利用位运算计算，通过计算每一位的重复次数排除重复次数为3次的数。
 * @param array
 * @param length
 * @return
 */
int FindNumberAppearOnceInArray(int* array, int length) {
    if (array == nullptr || length <= 0) {
        throw std::logic_error("please check input");
    }

    const int MaxLengthOfInt = sizeof(int) * 8;
    int bitSum[MaxLengthOfInt] = {0};
    for (int i = 0; i < length; ++i) {
        int temp = array[i];
        for (int j = MaxLengthOfInt - 1; j >= 0; j--) {
            bitSum[j] = bitSum[j] + (temp & 1);
            temp = temp >> 1;
        }
    }

    int result = 0;
    for (int i : bitSum) {
        result = result << 1;
        if (i % 3 == 1 || i % 3 == 0) {
            result += (i % 3);
        } else {
            throw std::logic_error("There are numbers whose number of repetitions is not 3 or a multiple of 3.");
        }
    }

    return result;
}

void test(const char* testName, int* array, int length) {
    cout << testName << endl;
    try {
        int result = FindNumberAppearOnceInArray(array, length);
        cout << result << endl;
    } catch (std::logic_error &e) {
        cout << e.what() << endl;
    }

}

void test_01() {
    test("test 01", nullptr, 0);
}

void test_02() {
    const int length = 13;
    int array[length] = {1, 2, 3, 4, 5, 1, 2, 3, 4, 1, 2, 3, 4};

    test("test 02", array, length);
}

void test_03() {
    const int length = 13;
    int array[length] = {-1, -2, -3, -4, 5, -1, -2, -3, -4, -1, -2, -3, -4};

    test("test 03", array, length);
}

void test_04() {
    const int length = 13;
    int array[length] = {0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0};

    test("test 04", array, length);
}

void test_05() {
    const int length = 13;
    int array[length] = {1, 2, 3, 4, -5, 1, 2, 3, 4, 1, 2, 3, 4};

    test("test 05", array, length);
}
void test_06() {
    const int length = 13;
    int array[length] = {1, 2, 3, 4, 0, 1, 2, 3, 4, 1, 2, 3, 4};

    test("test 06", array, length);
}

void test_07() {
    const int length = 14;
    int array[length] = {1, 2, 3, 4, 5, 5, 1, 2, 3, 4, 1, 2, 3, 4};

    test("test 07", array, length);
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