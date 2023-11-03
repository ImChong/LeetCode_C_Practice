'''
FilePath     : \Practice_LeetCode_C\.vscode\build.py
Author       : Chong Liu
CreateDate   : 2023-11-04 00:23:08
LastEditors  : Chong Liu
LastEditTime : 2023-11-04 01:03:54
=================================================================================
Copyright (c) 2023 by Chong Liu, All Rights Reserved.
=================================================================================
Description  : python 编译指令
'''
import subprocess
import sys

if __name__ == "__main__":
    print("Hello World!")
    print("argv: ", sys.argv)

    # 如果没有 ${fileDirname}/main.c 则报错

    # 如果有 ${fileDirname}/src 文件夹则编译
        # gcc
        #     -I${workspaceFolder}/00_Basics/01_Common_Func/inc/
        #     -I${workspaceFolder}/00_Basics/01_Common_Func/inc/commonDef/
        #     -I${fileDirname}/cfg/
        #     -I${fileDirname}/inc/
        #     ${workspaceFolder}/00_Basics/01_Common_Func/src/*.c
        #     ${fileDirname}/src/*.c
        #     main.c
        #     -o
        #     main.exe
        #     &&
        #     $dirmain.exe

    # 如果没有 ${fileDirname}/src 文件夹则编译
        # gcc
        #     -I${workspaceFolder}/00_Basics/01_Common_Func/inc/
        #     -I${workspaceFolder}/00_Basics/01_Common_Func/inc/commonDef/
        #     ${workspaceFolder}/00_Basics/01_Common_Func/src/*.c
        #     main.c
        #     -o
        #     main.exe
        #     &&
        #     $dirmain.exe