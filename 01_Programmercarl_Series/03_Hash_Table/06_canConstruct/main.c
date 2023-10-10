/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\03_Hash_Table\06_canConstruct\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-09-16 08:57:10
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-10 23:51:06
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 383. 赎金信：https://leetcode.cn/problems/ransom-note/
 * https://programmercarl.com/0383.%E8%B5%8E%E9%87%91%E4%BF%A1.html
 * https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0383.%E8%B5%8E%E9%87%91%E4%BF%A1.md
 */
#include <stdio.h>
#include <stdbool.h>

/**********************************************************************************/
/**********************************************************************************/
/***                                                                            ***/
/***                               TARGET FUNCTION                              ***/
/***                                                                            ***/
/**********************************************************************************/
/**********************************************************************************/
/* TODO */
/* ============================================================================== */
/* ============================================================================== */
/**
 * @description:
 * =================================================================================
 * @param {char} *ransomNote
 * @param {char} *magazine
 * @return {bool}
 */
bool canConstruct(char *ransomNote, char *magazine){
    int counter[26] = {0};

    for (int i = 0; magazine[i] != '\0'; i++) {
        counter[magazine[i] - 'a']++;
    }

    for (int i = 0; ransomNote[i] != '\0'; i++) {
        counter[ransomNote[i] - 'a']--;

        if (counter[ransomNote[i] - 'a'] < 0) {
            return false;
        }
    }
    return true;
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
int main(int argc, char const *argv[]) {
    /* Test case 1 */
    printf("======== Case 1 ======== \n");
    char r1[] = "a";
    char m1[] = "b";
    printf("Can be constructed: %s\r\n", canConstruct(r1, m1) ? "true" : "false");

    /* Test case 2 */
    printf("======== Case 2 ======== \n");
    char r2[] = "aa";
    char m2[] = "ab";
    printf("Can be constructed: %s\r\n", canConstruct(r2, m2) ? "true" : "false");

    /* Test case 3 */
    printf("======== Case 3 ======== \n");
    char r3[] = "aa";
    char r4[] = "aab";
    printf("Can be constructed: %s\r\n", canConstruct(r3, r4) ? "true" : "false");
    return 0;
}