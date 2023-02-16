//
// Created by AILEE on 2023/2/16.
// 题目58_02：左旋转字符串
// 题目：字符串的左旋转操作是把字符串前面的若干个字符串转移到字符串的尾部，请定义一个函数实现字符串左旋转的功能。如输入“adcdefg”和数字2，则输出“cdefgab”
//

#include <iostream>
#include <string>

using namespace std;

void ReverseSentence(string &str, int start, int end) {
    if (str.empty()) {
        return;
    }

    if (start > end || end > (str.size() - 1) || start > end > (str.size() - 1)) {
        throw logic_error("please check input.");
    }

    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

void LeftRotateString(string &str, int k) {
    if (str.empty() || k > str.size() || k < 0) {
        throw logic_error("please check input");
    }

    if (k == 0 || k == str.size()) {
        return;
    }

    ReverseSentence(str, 0, k - 1);
    ReverseSentence(str, k, str.size() - 1);
    ReverseSentence(str, 0, str.size() - 1);
}

void test(const char *testName, string str, int k) {
    cout << testName << endl;

    try {
        LeftRotateString(str, k);
        cout << str << endl;
    } catch (logic_error &error) {
        cout << error.what() << endl;
    }
}

void test_01() {
    string str = "";
    test("test 01", str, 0);
}

void test_02_08 () {
    string str = "abcdefg";
    test("test 02", str, 0);
    test("test 03", str, 1);
    test("test 04", str, 2);
    test("test 05", str, 3);
    test("test 06", str, str.size() - 1);
    test("test 07", str, str.size());
    test("test 08", str, str.size() + 1);
}

void test_09_15 () {
    string str = "  abcdefg   ";
    test("test 09", str, 0);
    test("test 10", str, 1);
    test("test 11", str, 2);
    test("test 12", str, 3);
    test("test 13", str, str.size() - 1);
    test("test 14", str, str.size());
    test("test 15", str, str.size() + 1);
}

int main(int argc, char **argv) {
    test_01();
    test_02_08();
    test_09_15();

    return 0;
}