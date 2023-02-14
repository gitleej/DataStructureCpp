//
// Created by AILEE on 2023/2/13.
// 题目51：数组中的逆序对
// 题目：在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字醉成一个逆序对，输入一个数组，求出这个数组中的逆序对总和，例如{7，5，6，4}中一共存在5个逆序对，分别为{7，6} {7，5} {7，4} {6，5} {6，4}
//

#include <iostream>

using namespace std;

/**
 * @brief 归并排序
 * @param array
 * @param arrayCopy
 * @param left
 * @param right
 * @return
 */
int Merger(int* array, int* arrayCopy, int left, int right) {
    int middle = (left + right) / 2;
    int i_start = left;
    int i_end = middle;
    int j_start = middle + 1;
    int j_end = right;

    int len = right;
    int count = 0;
    while (i_start <= i_end && j_start <= j_end) {
        if (array[i_end] > array[j_end]) {
            arrayCopy[len] = array[i_end];
            len--;
            i_end--;
            count += j_end - middle;
        } else {
            arrayCopy[len] = array[j_end];
            len--;
            j_end--;
        }
    }

    while (i_start <= i_end) {
        arrayCopy[len] = array[i_end];
        len--;
        i_end--;
    }

    while (j_start <= j_end) {
        arrayCopy[len] = array[j_end];
        len--;
        j_end--;
    }

    for (int i = 0; i < right - left + 1; i++) {
        array[left + i] = arrayCopy[left + i];
    }

    return count;
}

int MergerSort(int* array, int* arrayCopy, int left, int right) {
    // 分解
    if (left == right) {
        return 0;
    }

    int middle = (left + right) / 2;
    int leftCount = MergerSort(array, arrayCopy, left, middle);
    int rightCount = MergerSort(array, arrayCopy, middle + 1, right);

    // 合并
    int count = Merger(array, arrayCopy, left, right);

    return leftCount + rightCount + count;
}

int InversePairsInArray(int* array, int length) {
    if (array == nullptr || length <= 0) {
        return -1;
    }

    int *arrayCopy = new int[length];
    for (int i = 0; i < length; i++) {
        arrayCopy[i] = array[i];
    }

    int result = MergerSort(array, arrayCopy, 0, length - 1);

//    for (int i = 0; i < length; i++) {
//        cout << array[i] << " ";
//    }

    delete [] arrayCopy;
    return result;
}

void test(const char* testName, int* array, int length) {
    cout << testName << endl;

    int result = InversePairsInArray(array, length);
    cout << result << endl;
}

void test_01() {
    test("test 01", nullptr, 0);
}

void test_02() {
    const int length = 6;
    int array[length] = {6, 5, 4, 3, 2, 1};
    test("test 02", array, length);
}

void test_03() {
    const int length = 4;
    int array[length] = {7, 5, 6, 4};
    test("test 03", array, length);
}

void test_04() {
    const int length = 6;
    int array[length] = {1, 2, 3, 4, 5, 6};
    test("test 04", array, length);
}

void test_05() {
    const int length = 6;
    int array[length] = {3, 3, 2, 2, 1, 1};
    test("test 05", array, length);
}

void test_06() {
    const int length = 2;
    int array[length] = {3, 2};
    test("test 06", array, length);
}

void test_07() {
    const int length = 1;
    int array[length] = {3};
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