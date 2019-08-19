#pragma once
#ifndef INC_NTDIO
#define INC_NTDIO

#ifndef FILE_INPUT
#define FILE_INPUT "systemInput.txt"
#endif // !FILE_INPUT

#ifndef FILE_OUTPUT
#define FILE_OUTPUT "userOutput.txt"
#endif // !FILE_OUTPUT

#ifndef FILE_COMPARE
#define FILE_COMPARE "systemOutput.txt"
#endif // !FILE_COMPARE

#define termIn  (__acrt_iob_func(0))
#define termOut (__acrt_iob_func(1))
#define termErr (__acrt_iob_func(2))
#define fileIn  (__ncrt_iob_func(0))
#define fileOut (__ncrt_iob_func(1))
#define fileCmp (__ncrt_iob_func(2))

int __ntdres_;

#if defined(F_C) // 檔案 => 比較
#define scanf(_Format, ...) (__ntdres_ = fscanf(fileIn, _Format, __VA_ARGS__))
#define gets(_Buffer) (fgets(_Buffer, sizeof(_Buffer), fileIn))
#define fgets(_Buffer, _MaxCount, _Stream) (fgets(_Buffer, _MaxCount , fileIn))
#define getchar() (fgetc(fileIn))
#define printf(_Format, ...) (__ntdres_ = fprintf(fileCmp, _Format, __VA_ARGS__))
#define puts(_Buffer) (fputs(_Buffer, fileCmp), fputc('\n', fileCmp))
#define putchar(_Character) (fputc(_Character, fileCmp))
#elif defined(F_TC) // 檔案 => 終端+比較
#define scanf(_Format, ...) (__ntdres_ = fscanf(fileIn, _Format, __VA_ARGS__))
#define gets(_Buffer) (fgets(_Buffer, sizeof(_Buffer), fileIn))
#define fgets(_Buffer, _MaxCount, _Stream) (fgets(_Buffer, _MaxCount , fileIn))
#define getchar() (fgetc(fileIn))
#define printf(_Format, ...) (fprintf(termOut, _Format, __VA_ARGS__), fprintf(fileCmp, _Format, __VA_ARGS__))
#define puts(_Buffer) (fputs(_Buffer, termOut), fputc('\n', termOut), fputs(_Buffer, fileCmp), fputc('\n', fileCmp))
#define putchar(_Character) (fputc(_Character, termOut), fputc(_Character, fileCmp))
#elif defined(T_T) // 終端 => 終端
#define scanf(_Format, ...) (__ntdres_ = fscanf(termIn, _Format, __VA_ARGS__))
#define gets(_Buffer) (fgets(_Buffer, sizeof(_Buffer), termIn))
#define fgets(_Buffer, _MaxCount, _Stream) (fgets(_Buffer, _MaxCount , termIn))
#define getchar() (fgetc(termIn))
#define printf(_Format, ...) (fprintf(termOut, _Format, __VA_ARGS__))
#define puts(_Buffer) (fputs(_Buffer, termOut), fputc('\n', termOut))
#define putchar(_Character) fputc(_Character, termOut))
#elif defined(T_F) // 終端 => 檔案
#define scanf(_Format, ...) (__ntdres_ = fscanf(termIn, _Format, __VA_ARGS__))
#define gets(_Buffer) (fgets(_Buffer, sizeof(_Buffer), termIn))
#define fgets(_Buffer, _MaxCount, _Stream) (fgets(_Buffer, _MaxCount , termIn))
#define getchar() (fgetc(termIn))
#define printf(_Format, ...) (fprintf(fileOut, _Format, __VA_ARGS__))
#define puts(_Buffer) (fputs(_Buffer, fileOut), fputc('\n', fileOut))
#define putchar(_Character) (fputc(_Character, fileOut))
#elif defined(T_TF) // 終端 => 終端+檔案
#define scanf(_Format, ...) (__ntdres_ = fscanf(termIn, _Format, __VA_ARGS__))
#define gets(_Buffer) (fgets(_Buffer, sizeof(_Buffer), termIn))
#define fgets(_Buffer, _MaxCount, _Stream) (fgets(_Buffer, _MaxCount , termIn))
#define getchar() (fgetc(termIn))
#define printf(_Format, ...) (fprintf(termOut, _Format, __VA_ARGS__), fprintf(fileOut, _Format, __VA_ARGS__))
#define puts(_Buffer) (fputs(_Buffer, termOut), fputc('\n', termOut), fputs(_Buffer, fileOut), fputc('\n', fileOut))
#define putchar(_Character) (fputc(_Character, termOut), fputc(_Character, fileOut))
#elif defined(F_T) // 檔案 => 終端
#define scanf(_Format, ...) (__ntdres_ = fscanf(fileIn, _Format, __VA_ARGS__))
#define gets(_Buffer) (fgets(_Buffer, sizeof(_Buffer), fileIn))
#define fgets(_Buffer, _MaxCount, _Stream) (fgets(_Buffer, _MaxCount , fileIn))
#define getchar() (fgetc(fileIn))
#define printf(_Format, ...) (fprintf(termOut, _Format, __VA_ARGS__))
#define puts(_Buffer) (fputs(_Buffer, termOut), fputc('\n', termOut))
#define putchar(_Character) fputc(_Character, termOut))
#elif defined(F_F) // 檔案 => 檔案
#define scanf(_Format, ...) ((__ntdres_ = fscanf(fileIn, _Format, __VA_ARGS__))
#define gets(_Buffer) (fgets(_Buffer, sizeof(_Buffer), fileIn))
#define fgets(_Buffer, _MaxCount, _Stream) (fgets(_Buffer, _MaxCount , fileIn))
#define getchar() (fgetc(fileIn))
#define printf(_Format, ...) (fprintf(fileOut, _Format, __VA_ARGS__))
#define puts(_Buffer) (fputs(_Buffer, fileOut), fputc('\n', fileOut))
#define putchar(_Character) (fputc(_Character, fileOut))
#elif defined(F_TF) // 檔案 => 終端+檔案
#define scanf(_Format, ...) (__ntdres_ = fscanf(fileIn, _Format, __VA_ARGS__))
#define gets(_Buffer) (fgets(_Buffer, sizeof(_Buffer), fileIn))
#define fgets(_Buffer, _MaxCount, _Stream) (fgets(_Buffer, _MaxCount , fileIn))
#define getchar() (fgetc(fileIn))
#define printf(_Format, ...) (fprintf(termOut, _Format, __VA_ARGS__), fprintf(fileOut, _Format, __VA_ARGS__))
#define puts(_Buffer) (fputs(_Buffer, termOut), fputc('\n', termOut), fputs(_Buffer, fileOut), fputc('\n', fileOut))
#define putchar(_Character) (fputc(_Character, termOut), fputc(_Character, fileOut))
#else  // 不包裝 
#endif

FILE* __cdecl __ncrt_iob_func(
    unsigned _Ix
);

#endif