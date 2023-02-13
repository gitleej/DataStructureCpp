//
// Created by AILEE on 2023/2/13.
// 题目45：把数组排成最小的数
// 题目：输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个，例如，输入{3，32，321}，则打印出这三个数字能排列成的最小数字为321323
//

#include <iostream>
#include <cstring>

#define MAX_LENGTH 10

using namespace std;

int Compare(const void* str1, const void*str2) {
    char num1[MAX_LENGTH * 2 + 1] = "\0";
    char num2[MAX_LENGTH * 2 + 1] = "\0";

    strcpy(num1, *(const char**)str1);
    strcat(num1, *(const char**)str2);

    strcpy(num2, *(const char**)str2);
    strcat(num2, *(const char**)str1);

    return strcmp(num1, num2);
}

/**
 * @brief 注意组合后的数字越界，大数问题，将数字转换为字符串可以解决组合后数字越界溢出的问题。
 * @param array
 * @param length
 */
void SortArrayForMinNumber(int* array, int length) {
    if (array == nullptr || length <= 0) {
        cout << "please check input." << endl;
        return;
    }

    char **numberStr = (char**)(new int[length]);
    for (int i = 0; i < length; i++) {
        numberStr[i] = new char[MAX_LENGTH + 1];
        sprintf(numberStr[i], "%d", array[i]);
    }

    // 快速排序
    qsort(numberStr, length, sizeof(char *), Compare);

    for (int i = 0; i < length; i++) {
        cout << numberStr[i];
    }

    cout << endl;
    // 垃圾回收
    for (int i = 0; i < length; i++) {
        delete numberStr[i];
    }
    delete [] numberStr;
}

void test(const char* testName, int *array, int length) {
    cout << testName << endl;

    SortArrayForMinNumber(array, length);
}

/**
 * @brief 空数组
 */
void test_01() {
    test("test 01", nullptr, 0);
}

void test_02() {
    const int length = 3;
    int array[length] = {3, 321, 32};

    test("test 02", array, length);
}

void test_03() {
    const int length = 1;
    int array[length] = {321};

    test("test 03", array, length);
}

int main(int argc, char** argv) {
    test_01();
    test_02();
    test_03();

    return 0;
}