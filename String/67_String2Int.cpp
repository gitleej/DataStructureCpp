//
// Created by AILEE on 2023/2/16.
// 题目67：把字符串转换成整数
// 题目：请写一个函数实现将字符串转换成整数的功能，要求不能使用atoi等库函数
//

#include <iostream>
#include <string>

using namespace std;

int String2Int(const string &str) {
    if (str.empty()) {
        throw logic_error("Empty string. Please check input.");
    }

    // 检查字符串是否以+-号开头。
    bool isNegative = false;
    int index = 0;
    if (str[index] == '+') {
        index++;
        isNegative = false;
    } else if (str[index] == '-') {
        index++;
        isNegative = true;
    }

    // 检查是否只输入了+-号
    if (index == str.size()) {
        throw logic_error("Only plus and minus signs are entered, please check your entry.");
    }

    // 进行数字转换
    long long number = 0;
    for (int i = index; i < str.size(); ++i) {
        if (str[i] >= '0' && str[i] <= '9') {
            if (isNegative) {
                number = number * 10 + (-1) * (str[i] - '0');
            } else {
                number = number * 10 + (str[i] - '0');
            }

            if ((isNegative && number < (signed int) 0x80000000) || !isNegative && number > 0x7FFFFFFF) {
                number = 0;
                throw logic_error("Integer out of bounds.");
            }
        } else {
            number = 0;
            throw logic_error("There are non-numeric characters in the string.");
        }
    }

    return (int)number;
}

void test(const char* testName, const string &str) {
    cout << testName << endl;

    try {
        int result = String2Int(str);
        cout << result << endl;
    } catch (logic_error &error) {
        cout << error.what() << endl;
    }
}

void test_01_14() {
    test("test 01", "");
    test("test 02", "+");
    test("test 03", "+0");
    test("test 04", "-0");
    test("test 05", "-123");
    test("test 06", "+123");
    test("test 07", "1234");
    test("test 08", "a123");
    test("test 09", "1a23");
    test("test 10", "123a");
    test("test 11", "-2147483648");
    test("test 12", "+2147483647");
    test("test 13", "+2147483649");
    test("test 14", "-2147483649");
}

int main(int argc, char** argv) {
    test_01_14();

    return 0;
}
