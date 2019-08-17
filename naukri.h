#pragma once
#ifndef INC_NAUKRI
#define INC_NAUKRI

#pragma warning (disable : 4996)

#ifndef CMPMODE
// 0 = 隨意 (皆為隨意則不進行比較)
// 1 = 不進行比較
// 2 = 使用 compare.txt 儲存的答案比較
// 3 = 使用 compare.c   計算的答案比較 (只有在 input 是檔案時才能執行)
// 4 = 自動判斷，fileIn 沒被使用過 = 3 使用過 = 2 
// 一一一一一一一一一一一一一一一一一一一
// main() 的 return 也可以進行選擇，且若非隨意會優先使用 return 的定義。
#define CMPMODE 4
#endif

// IO Mode
#if !(defined(F_C) || defined(F_TC) || defined(T_T)  || defined(T_F)  || defined(T_TF) || defined(F_T) || defined(F_F) || defined(F_TF))
// 輸入 => 輸出
// T = 終端機 (Terminal)
// F = 檔案 (File: output.txt)
// C = 比對檔案 (File: compare.txt)
// 若有多重輸出則以 T > F or C 為順序排列
#define F_TF
#endif

#include <naukri/ntdio.h>

#ifndef main
// Main Wrapper
#define main _entry
#endif // !main

int main(
    void
);

#endif

//compare.c Header (刪到的時用這個復原)
#pragma region Mod Define
//#define main _compare
//#define F_TC
#pragma endregion