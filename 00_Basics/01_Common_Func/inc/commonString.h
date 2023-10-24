/*
 * @FilePath     : \Practice_LeetCode_C\00_Basics\01_Common_Func\inc\commonString.h
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-24 00:56:41
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-25 00:32:30
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 通用字符串头文件
 */
#ifndef __COMMON_STRING_H
#define __COMMON_STRING_H

/**********************************************************************************/
/*                                                                                */
/*                                UTILITY FUNCTIONS                               */
/*                                                                                */
/**********************************************************************************/
void swapChar(char *a, char *b);
void reverse(char* leftIndex, char* rightIndex);

/**********************************************************************************/
/*                                                                                */
/*                                  TEST FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
void validateString(char testNum, char *expect, char *actual);


#endif  /* __COMMON_STRING_H */