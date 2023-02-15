//
// Created by AILEE on 2023/2/15.
// 题目38：字符串的排列
// 题目：输入一个字符串，打印出该字符串中字符的所有排列，例如：输入字符串abc，则打印出abc，acb，bac，bca，cab，cba
//

#include <iostream>
#include <string>
#include <set>
#include <vector>

using namespace std;

void Permutation(string str, int index, vector<string> &result) {
    if (index == str.size() - 1) {
        result.push_back(str);
        return;
    }

    set<int> st;
    for (int i = index; i < str.size(); i++) {
        // 去重
        if (st.find(str[i])  != st.end()) {
            continue;
        }
        st.insert(str[i]);                              ///< 不重复的字符添加到set中
        swap(str[index], str[i]);                   ///< 交换，将str[i]固定在str[index]位置上
        Permutation(str, index + 1, result);        ///< 开启固定第index + 1个字符
        swap(str[index], str[i]);                   ///< 交换，将str[index]位置固定的字符恢复到str[i]位置上，恢复数组
    }
}

void Permutation(string &str, vector<string> &result) {
    if (str.empty()) {
        throw logic_error("please check input");
    }

    Permutation(str, 0, result);
}

void test(const char *testName, string &str) {
    cout << testName << endl;

    try {
        vector<string> result;
        Permutation(str, result);
        cout << "具有不重复的排列数量为：" << result.size() << endl;
        for (auto &it : result) {
            cout << it << endl;
        }
    } catch (logic_error &error) {
        cout << error.what() << endl;
    }
}

void test_01() {
    string str;
    str.clear();
    test("test 01", str);
}

void test_02() {
    string str = "a";
    test("test 02", str);
}

void test_03() {
    string str = "ab";
    test("test 03", str);
}

void test_04() {
    string str = "abcc";
    test("test 04", str);
}

void test_05() {
    string str = "aabbccd";
    test("test 05", str);
}

int main(int argc, char** argv) {
    test_01();
    test_02();
    test_03();
    test_04();
    test_05();

    return 0;
}
