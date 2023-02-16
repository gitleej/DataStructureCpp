//
// Created by AILEE on 2023/2/16.
// 题目20：表示数值的字符串
// 题目：请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如：+100，5e2，-123，3.1415，-1E-16都表示数值，但12e，1a3.14，1.2.3，
// +-5，12e+5.4都不是。
//

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

/**
 * @brief 定义状态
 */
enum Status {
    STATE_INITIAL,              ///< 初始状态
    STATE_INT_SIGN,             ///< 正负符号
    STATE_INTEGER,              ///< 整数
    STATE_POINT,                ///< 有整数部分小数点
    STATE_POINT_WITHOUT_INT,    ///< 无整数部分小数点
    STATE_FRACTION,             ///< 小数
    STATE_EXP,                  ///< 指数字符
    STATE_EXP_SIGN,             ///< 指数正负号
    STATE_EXP_NUMBER,           ///< 指数数字
    STATE_END                   ///< 结束状态
};

/**
 * @brief 字符状态
 */
enum CharType {
    CHAR_NUMBER,            ///< 数字
    CHAR_EXP,               ///< 指数字符
    CHAR_POINT,             ///< 小数点
    CHAR_SIGN,              ///< 正负符号
    CHAR_SPACE,             ///< 空格
    CHAR_ILLEGAL            ///< 非法字符
};

/**
 * @brief 确定字符类型
 * @param ch 输入字符
 * @return 字符类型
 */
CharType toCharType(char ch) {
    if (ch >= '0' && ch <= '9') {
        return CHAR_NUMBER;
    } else if (ch == 'e' || ch == 'E') {
        return CHAR_EXP;
    } else if (ch == '.') {
        return CHAR_POINT;
    } else if (ch == '+' || ch == '-') {
        return CHAR_SIGN;
    } else if (ch == ' ') {
        return CHAR_SPACE;
    } else {
        return CHAR_ILLEGAL;
    }
}

/**
 * @brief 动态规划，有限状态机
 * @param str 输入字符串
 * @return 是否为数值
 */
bool isNumber(const string &str) {
    if (str.empty()) {
        return false;
    }

    // 定义状态转移表
    unordered_map<Status, unordered_map<CharType, Status>> transfer{
            {
                    STATE_INITIAL, {
                                           {CHAR_SPACE, STATE_INITIAL},
                                           {CHAR_NUMBER, STATE_INTEGER},
                                           {CHAR_POINT, STATE_POINT_WITHOUT_INT},
                                           {CHAR_SIGN, STATE_INT_SIGN}
                                   }
            }, {
                    STATE_INT_SIGN, {
                                           {CHAR_NUMBER, STATE_INTEGER},
                                           {CHAR_POINT, STATE_POINT_WITHOUT_INT}
                                   }
            }, {
                    STATE_INTEGER, {
                                           {CHAR_NUMBER, STATE_INTEGER},
                                           {CHAR_EXP, STATE_EXP},
                                           {CHAR_POINT, STATE_POINT},
                                           {CHAR_SPACE, STATE_END}
                                   }
            }, {
                    STATE_POINT, {
                                           {CHAR_NUMBER, STATE_FRACTION},
                                           {CHAR_EXP, STATE_EXP},
                                           {CHAR_SPACE, STATE_END}
                                   }
            }, {
                    STATE_POINT_WITHOUT_INT, {
                                           {CHAR_NUMBER, STATE_FRACTION}
                                   }
            }, {
                    STATE_FRACTION,
                    {
                                           {CHAR_NUMBER, STATE_FRACTION},
                                           {CHAR_EXP, STATE_EXP},
                                           {CHAR_SPACE, STATE_END}
                                   }
            }, {
                    STATE_EXP,
                    {
                                           {CHAR_NUMBER, STATE_EXP_NUMBER},
                                           {CHAR_SIGN, STATE_EXP_SIGN}
                                   }
            }, {
                    STATE_EXP_SIGN, {
                                           {CHAR_NUMBER, STATE_EXP_NUMBER}
                                   }
            }, {
                    STATE_EXP_NUMBER, {
                                           {CHAR_NUMBER, STATE_EXP_NUMBER},
                                           {CHAR_SPACE, STATE_END}
                                   }
            }, {
                    STATE_END, {
                                           {CHAR_SPACE, STATE_END}
                                   }
            }
    };

    int len = str.length();
    Status st = STATE_INITIAL;

    // 遍历字符串
    for (int i = 0; i < len; i++) {
        // 确定字符
        CharType typ = toCharType(str[i]);
        // 查找下一个状态是否存在，不存在则无法转移，存在则从当前状态转移到下一个状态
        if (transfer[st].find(typ) == transfer[st].end()) {
            return false;
        } else { // 状态转移
            st = transfer[st][typ];
        }
    }

    return st == STATE_INTEGER || st == STATE_POINT || st == STATE_FRACTION || st == STATE_EXP_NUMBER || st == STATE_END;
}

void test(const char* testName, const string &str) {
    cout << testName << endl;

    if (isNumber(str)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
}

void test_01_11() {
    test("test 01", "");
    test("test 02", "+100");
    test("test 03", "5e2");
    test("test 04", "-123");
    test("test 05", "3.1415");
    test("test 06", "-1E-16");

    test("test 07", "12e");
    test("test 08", "1a3.14");
    test("test 09", "1.2.3");
    test("test 10", "+-5");
    test("test 11", "12e+5.4");
}

int main(int argc, char ** argv) {
    test_01_11();

    return 0;
}