//
// Created by AILEE on 2023/2/15.
// 题目50_01：第一个只出现一次的字符
// 题目：在字符串中找出第一个只出现一次的字符，例如输入“abaccdeff”，则输出b。
//

#include <iostream>
#include <string>
#include <map>

using namespace std;

/**
 * @brief 采用map存储每个字符出现的次数，只需遍历两次数组即可查找到第一个只出现1次的字符。
 * @param str
 * @return
 */
char FirstNotRepeatingChar(const string &str) {
    if (str.empty()) {
        throw logic_error("please check input");
    }

    // 统计每个数字出现的次数
    map<char, int> counter;
    for (char i : str) {
        if (counter.find(i) == counter.end()) {
            counter[i] = 1;
        } else {
            counter[i]++;
        }
    }

    // 检查数字出现的次数
    for (char i : str) {
        if (counter[i] == 1) {
            return i;
        }
    }

    return '\0';
}

void test(const char* testName, const string &str) {
    cout << testName << endl;

    try {
        char ch = FirstNotRepeatingChar(str);
        if (ch != '\0') {
            cout << ch << endl;
        } else {
            cout << "Find no characters that appear only once." << endl;
        }
    } catch (logic_error &error) {
        cout << error.what() << endl;
    }
}

void test_01() {
    test("test 01", "");
}

void test_02() {
    string str = "abcdefg";
    test("test 02", str);
}

void test_03() {
    string str = "abcdefgabcdefg";
    test("test 03", str);
}

void test_04() {
    string str = "aabbbccdeefgg";
    test("test 04", str);
}

int main(int argc, char** argv) {
    test_01();
    test_02();
    test_03();
    test_04();

    return 0;
}
