//
// Created by AILEE on 2023/2/15.
// 题目56_01：翻转单词顺序
// 题目：输入一个英文句子，翻转句子中的单词顺序，但单词内字符的顺序不变，为简单起见，标点和普通字符一样处理，如“I am a student.“，则输出”student. a am I“;
//

#include <iostream>

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

void ReverseWordsInSentence(string &str) {
    if (str.empty()) {
        throw logic_error("please check input");
    }

    try {
        ReverseSentence(str, 0, str.size() - 1);
        int start, end = 0;
        bool setStart, setEnd = false;
        char visit = str[0];
        for (int i = 1; i < str.size(); ++i) {
            if (i == 1 && visit != ' ') {                       ///< 句子开头的空格
                start = (i - 1);
                setStart = true;
            } else if (visit == ' ' && str[i] != ' ') {
                start = i;
                setStart = true;
            } else if (visit != ' ' && str[i] == ' ') {
                end = i - 1;
                setEnd = true;
            } else if (visit != ' ' && i == str.size() - 1) {   ///< 句子结尾的空格
                end = i;
                setEnd = true;
            }
            visit = str[i];
            if (setStart && setEnd) {
                ReverseSentence(str, start, end);
                setStart = false;
                setEnd = false;
            }
        }
    } catch (logic_error &error) {
        cout << error.what() << endl;
    }
}

void test(const char *testName, const string str) {
    cout << testName << endl;

    string temp(str);
    try {
        ReverseWordsInSentence(temp);
        cout << temp << endl;
    } catch (logic_error &error) {
        cout << error.what() << endl;
    }
}

void test_01_04() {
    test("test 01", "");
    test("test 02", "Hello world. I am AILEE.");
    test("test 03", "AILEE");
    test("test 04", "  Hello world.  I am  AILEE.   ");
    test("test 05", "     ");
}

int main(int argc, char** argv) {
    test_01_04();

    return 0;
}