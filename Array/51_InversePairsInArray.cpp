//
// Created by AILEE on 2023/2/13.
// 题目51：数组中的逆序对
// 题目：在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字醉成一个逆序对，输入一个数组，求出这个数组中的逆序对总和，例如{7，5，6，4}中一共存在5个逆序对，分别为{7，6} {7，5} {7，4} {6，5} {6，4}
//

#include <iostream>

using namespace std;

int merger(int* array, int* arrayCopy, int left, int right) {
    // 分解
    if (left == right) {
        return 0;
    }

    int middle = (left + right) / 2;
    merger(array, arrayCopy, left, middle);
    merger(array, arrayCopy, middle+1, right);

    // 合并
    int i = left;
    int j = middle + 1;
    int k = right;
    while (i < middle && j < right) {
        if (array[i] < arrayCopy[j]) {
            arrayCopy[k++] = array[i++];
        } else {
            arrayCopy[k++] = array[j++];
        }
    }

    // 右侧无元素
    while (i <= middle) {
        arrayCopy[k++] = array[i++];
    }

    // 左侧无元素
    while (j <= right) {
        arrayCopy[k++] = array[j++];
    }

    for (int l = left; l < right; l++) {
        array[l] = arrayCopy[l];
    }

    return 0;
}

int InversePairsInArray(int* array, int length) {
    if (array == nullptr || length <= 0) {
        return -1;
    }

    int *arrayCopy = new int[length];
    for (int i = 0; i < length; i++) {
        arrayCopy[i] = array[i];
    }

    int result = merger(array, array, 0, length - 1);

    for (int i = 0; i < length; i++) {
        cout << array[i] << " ";
    }

    delete [] arrayCopy;
    return result;
}

void test(const char* testName, int* array, int length) {
    cout << testName << endl;

    InversePairsInArray(array, length);
}

void test_01() {
    test("test 01", nullptr, 0);
}

void test_02() {
    const int length = 6;
    int array[length] = {6, 5, 4, 3, 2, 1};
    test("test 02", array, length);
}

int main(int argc, char** argv) {
    test_01();
    test_02();

    return 0;
}