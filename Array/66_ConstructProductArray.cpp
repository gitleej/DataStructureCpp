//
// Created by AILEE on 2023/2/14.
// 题目66：构建乘积数组
// 题目：给定一个数组A[0,1,2,…,n-1]，请构建一个数组B[0,1,2,…,n-1]，其中B中的元素B[i] = A[0]*A[1]*…A[i-1]*A[i+1]*…*A[n-1]。不能使用除法。
//

#include <iostream>

using namespace std;

int *ConstructProductArray(int* array, int length) {
    if (array == nullptr || length <= 0) {
        throw logic_error("please check input");
    }

    static int *arrayB = new int[length];

    // 计算C[i] = C[i - 1] * A[i - 1]
    arrayB[0] = 1;
    for (int i = 1; i < length; ++i) {
        arrayB[i] = arrayB[i - 1] * array[i - 1];
    }

    // 计算D[i - 1] = D[i] * A[i]
    int D = 1;
    for (int i = length - 2; i >= 0; i--) {
        D = D * array[i + 1];
        arrayB[i] = D * arrayB[i];
    }

    return arrayB;
}

void test(const char* testName, int *array, int length) {
    cout << testName << endl;
    try {
        int *arrayB = ConstructProductArray(array, length);
        for (int i = 0; i < length; ++i) {
            cout << arrayB[i] << " ";
        }
        cout << endl;
    } catch (logic_error &error) {
        cout << error.what() << endl;
    }
}

void test_01() {
    test("test 01", nullptr, 0);
}

void test_02 () {
    const int length = 5;
    int array[length] = { 1, 2, 3, 4, 5 };

    test("test 02", array, length);
}

void test_03 () {
    const int length = 5;
    int array[length] = { 1, 2, 0, 4, 5 };

    test("test 03", array, length);
}

void test_04 () {
    const int length = 5;
    int array[length] = { 1, 2, 0, 4, 0 };;

    test("test 04", array, length);
}

void test_05 () {
    const int length = 5;
    int array[length] = { 1, -2, 3, -4, 5 };

    test("test 05", array, length);
}

void test_06 () {
    const int length = 2;
    int array[length] = { 1, -2 };

    test("test 06", array, length);
}

int main(int argc, char** argv) {
    test_01();
    test_02();
    test_03();
    test_04();
    test_05();
    test_06();

    return 0;
}