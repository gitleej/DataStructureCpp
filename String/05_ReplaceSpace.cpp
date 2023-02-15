//
// Created by AILEE on 2023/2/15.
// 题目5：替换空格
// 题目：请实现一个函数，把字符串中的每个空格替换成“%20”。
//

#include <iostream>

using namespace std;

void ReplaceSpace(char *str, int length) {
    if (str == nullptr || length <= 0) {
        throw logic_error("please check input");
    }

    // 统计空格数量
    int spaceNum = 0;
    int originalStrLength = 0;
    while (str[originalStrLength] != '\0') {
        if (str[originalStrLength] == ' ') {
            spaceNum++;
        }
        originalStrLength++;
    }

    int newLength = originalStrLength + (spaceNum * 2);
    if (newLength > length) {
        throw logic_error("New string length exceeds memory bounds.");
    }

    // 字符串最后是'\0'
    while (originalStrLength >= 0 && newLength >= 0) {
        if (str[originalStrLength] == ' ') {
            str[newLength--] = '0';
            str[newLength--] = '2';
            str[newLength--] = '%';
        } else {
            str[newLength--] = str[originalStrLength];
        }
        originalStrLength--;
    }
}

void test(const char* testName, char *str, int length) {
    cout << testName << endl;
    try {
        ReplaceSpace(str, length);
        cout << str << endl;
    } catch (logic_error &error) {
        cout << error.what() << endl;
    }
}

void test_01() {
    test("test 01", nullptr, 0);
}

void test_02() {
    const int length = 100;
    char str[length] = "Hello World! I am AILEE";

    test("test 01", str, length);
}

void test_03() {
    const int length = 100;
    char str[length] = " Hello  World! I am AILEE ";

    test("test 03", str, length);
}

int main(int argc, char **argv) {
    test_01();
    test_02();
    test_03();

    return 0;
}
