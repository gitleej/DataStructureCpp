//
// Created by AILEE on 2023/2/12.
// 题目42：连续子数组的最大和
// 题目：输入一个整形数组，数组里有整数也有负数，数组中的一个或连续的多个整数组成一个子数组，求所有数组的和的最大值，要求时间复杂度为O(n)
//

#include <iostream>

using namespace std;

bool GreatestSumOfSubArray(int* array, int length, int* greatestSum) {
    if (array == nullptr || length <= 0) {
        return false;
    }

    int currentSum = 0;
    *greatestSum = array[0];
    for (int i = 0; i < length; i++) {
        if (currentSum < 0) {
            currentSum = array[i];
        } else {
            currentSum += array[i];
        }

        if (currentSum > *greatestSum) {
            *greatestSum = currentSum;
        }
    }

    return true;
}

void test(const char* testName, int* array, int length) {
    cout << testName << endl;

    int greatestSum;
    bool isAvailable = GreatestSumOfSubArray(array, length, &greatestSum);
    if (isAvailable) {
        cout << greatestSum << endl;
    } else {
        cout << "please check input" << endl;
    }
}

void test_01() {
    test("test 01", nullptr, 0);
}

void test_02() {
    const int length = 1;
    int array[length] = {1};

    test("test 02", array, length);
}

void test_03() {
    const int length = 8;
    int array[length] = {1, -2, 3, 10, -4, 7, 2, -5};

    test("test 03", array, length);
}

void test_04() {
    const int length = 8;
    int array[length] = {-3, -2, -4, -1, -5, -7, -9, -6};

    test("test 04", array, length);
}

void test_05() {
    const int length = 8;
    int array[length] = {3, 2, 4, 1, 5, 7, 9, 6};

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
