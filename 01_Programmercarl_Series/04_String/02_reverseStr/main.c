/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\04_String\02_reverseStr\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-08-21 22:14:49
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-24 00:54:21
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 541. 反转字符串 II： https://leetcode.cn/problems/reverse-string-ii/
 * https://programmercarl.com/0541.%E5%8F%8D%E8%BD%AC%E5%AD%97%E7%AC%A6%E4%B8%B2II.html
 * https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0541.%E5%8F%8D%E8%BD%AC%E5%AD%97%E7%AC%A6%E4%B8%B2II.md
 */
#include <stdio.h>
#include <string.h>

/**********************************************************************************/
/**********************************************************************************/
/***                                                                            ***/
/***                               TARGET FUNCTION                              ***/
/***                                                                            ***/
/**********************************************************************************/
/**********************************************************************************/
/**
 * @description:
 * =================================================================================
 * @param {char} *s
 * @param {int} k
 * @return {char} *ans
 */
char *reverseStr(char *s, int k){

    return NULL;
}

/**********************************************************************************/
/*                                                                                */
/*                                 HELPER FUNCTIONS                               */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 验证字符串
 * =================================================================================
 * @param {char} testNum    测试编号
 * @param {int} expect      预期
 * @param {int} actual      实际
 * @return {void}
 */
void validateString(char testNum, char *expect, char *actual) {
    if (expect == NULL && actual == NULL) {
        printf("✅ Test %c Passed\n", testNum);
        return;
    } else if (expect == NULL || actual == NULL) {
        printf("❌ Test %c Failed\n", testNum);
        return;
    }
    if (strcmp(expect, actual) == 0) {
        printf("✅ Test %c Passed\n", testNum);
    } else {
        printf("❌ Test %c Failed\n", testNum);
    }
}

/**********************************************************************************/
/*                                                                                */
/*                                  TEST FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 测试 1
 * 输入：s = "abcdefg", k = 2
 * 输出："bacdfeg"
 * =================================================================================
 * @return {void}
 */
void test_1(void) {
    /* 实际结果 */
    char *s = "abcdefg";
    int k = 2;
    char *actual = reverseStr(s, k);

    /* 预期结果 */
    char *expect = "bacdfeg";

    /* 比较结果 */
    validateString('1', expect, actual);
}

/**
 * @description: 测试 2
 * 输入：s = "abcd", k = 2
 * 输出："bacd"
 * =================================================================================
 * @return {void}
 */
void test_2(void) {
    /* 实际结果 */
    char *s = "abcd";
    int k = 2;
    char *actual = reverseStr(s, k);

    /* 预期结果 */
    char *expect = "bacd";

    /* 比较结果 */
    validateString('2', expect, actual);
}

/**
 * @description: 测试 3
 * 输入：s = "abcdefg", k = 4
 * 输出："dcbaefg"
 * =================================================================================
 * @return {void}
 */
void test_3(void) {
    /* 实际结果 */
    char *s = "abcdefg";
    int k = 4;
    char *actual = reverseStr(s, k);

    /* 预期结果 */
    char *expect = "dcbaefg";

    /* 比较结果 */
    validateString('3', expect, actual);
}

/**********************************************************************************/
/*                                                                                */
/*                                  MAIN FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 主函数
 * =================================================================================
 * @param {int} argc        程序入参个数
 * @param {char} *argv[]    程序入参字符串数组
 * @return {int}            程序运行状态
 */
int main(int argc, const char *argv[]) {
    test_1();
    test_2();
    test_3();
    return 0;
}