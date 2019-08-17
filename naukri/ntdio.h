#pragma once
#ifndef INC_NTDIO
#define INC_NTDIO

#ifndef FILE_INPUT
#define FILE_INPUT "input.txt"
#endif // !FILE_INPUT

#ifndef FILE_OUTPUT
#define FILE_OUTPUT "output.txt"
#endif // !FILE_OUTPUT

#ifndef FILE_ERROR
#define FILE_ERROR "error.txt"
#endif // !FILE_ERROR

#ifndef FILE_COMPARE
#define FILE_COMPARE "compare.txt"
#endif // !FILE_COMPARE

#define termIn  (__acrt_iob_func(0))
#define termOut (__acrt_iob_func(1))
#define termErr (__acrt_iob_func(2))
#define fileIn  (__ncrt_iob_func(0))
#define fileOut (__ncrt_iob_func(1))
#define fileErr (__ncrt_iob_func(2))
#define fileCmp (__ncrt_iob_func(3))

#if defined(F_C) // �ɮ� => ���
#define scanf(_Format, ...) fscanf(fileIn, _Format, __VA_ARGS__)
#define gets(_Buffer) fgets(_Buffer, sizeof(_Buffer), fileIn)
#define getchar() fgetc(fileIn)
#define printf(_Format, ...) fprintf(fileCmp, _Format, __VA_ARGS__)
#define puts(_Buffer) fputs(_Buffer, fileCmp), fputc('\n', fileCmp)
#define putchar(_Character) fputc(_Character, fileCmp)
#elif defined(F_TC) // �ɮ� => �׺�+���
#define scanf(_Format, ...) fscanf(fileIn, _Format, __VA_ARGS__)
#define gets(_Buffer) fgets(_Buffer, sizeof(_Buffer), fileIn)
#define getchar() fgetc(fileIn)
#define printf(_Format, ...) fprintf(termOut, _Format, __VA_ARGS__), fprintf(fileCmp, _Format, __VA_ARGS__)
#define puts(_Buffer) fputs(_Buffer, termOut), fputc('\n', termOut), fputs(_Buffer, fileCmp), fputc('\n', fileCmp)
#define putchar(_Character) fputc(_Character, termOut), fputc(_Character, fileCmp)
#elif defined(T_T) // �׺� => �׺�
#define scanf(_Format, ...) fscanf(termIn, _Format, __VA_ARGS__)
#define gets(_Buffer) fgets(_Buffer, sizeof(_Buffer), termIn)
#define getchar() fgetc(termIn)
#define printf(_Format, ...) fprintf(termOut, _Format, __VA_ARGS__)
#define puts(_Buffer) fputs(_Buffer, termOut), fputc('\n', termOut)
#define putchar(_Character) fputc(_Character, termOut)
#elif defined(T_F) // �׺� => �ɮ�
#define scanf(_Format, ...) fscanf(termIn, _Format, __VA_ARGS__)
#define gets(_Buffer) fgets(_Buffer, sizeof(_Buffer), termIn)
#define getchar() fgetc(termIn)
#define printf(_Format, ...) fprintf(fileOut, _Format, __VA_ARGS__)
#define puts(_Buffer) fputs(_Buffer, fileOut), fputc('\n', fileOut)
#define putchar(_Character) fputc(_Character, fileOut)
#elif defined(T_TF) // �׺� => �׺�+�ɮ�
#define scanf(_Format, ...) fscanf(termIn, _Format, __VA_ARGS__)
#define gets(_Buffer) fgets(_Buffer, sizeof(_Buffer), termIn)
#define getchar() fgetc(termIn)
#define printf(_Format, ...) fprintf(termOut, _Format, __VA_ARGS__), fprintf(fileOut, _Format, __VA_ARGS__)
#define puts(_Buffer) fputs(_Buffer, termOut), fputc('\n', termOut), fputs(_Buffer, fileOut), fputc('\n', fileOut)
#define putchar(_Character) fputc(_Character, termOut), fputc(_Character, fileOut)
#elif defined(F_T) // �ɮ� => �׺�
#define scanf(_Format, ...) fscanf(fileIn, _Format, __VA_ARGS__)
#define gets(_Buffer) fgets(_Buffer, sizeof(_Buffer), fileIn)
#define getchar() fgetc(fileIn)
#define printf(_Format, ...) fprintf(termOut, _Format, __VA_ARGS__)
#define puts(_Buffer) fputs(_Buffer, termOut), fputc('\n', termOut)
#define putchar(_Character) fputc(_Character, termOut)
#elif defined(F_F) // �ɮ� => �ɮ�
#define scanf(_Format, ...) fscanf(fileIn, _Format, __VA_ARGS__)
#define gets(_Buffer) fgets(_Buffer, sizeof(_Buffer), fileIn)
#define getchar() fgetc(fileIn)
#define printf(_Format, ...) fprintf(fileOut, _Format, __VA_ARGS__)
#define puts(_Buffer) fputs(_Buffer, fileOut), fputc('\n', fileOut)
#define putchar(_Character) fputc(_Character, fileOut)
#elif defined(F_TF) // �ɮ� => �׺�+�ɮ�
#define scanf(_Format, ...) fscanf(fileIn, _Format, __VA_ARGS__)
#define gets(_Buffer) fgets(_Buffer, sizeof(_Buffer), fileIn)
#define getchar() fgetc(fileIn)
#define printf(_Format, ...) fprintf(termOut, _Format, __VA_ARGS__), fprintf(fileOut, _Format, __VA_ARGS__)
#define puts(_Buffer) fputs(_Buffer, termOut), fputc('\n', termOut), fputs(_Buffer, fileOut), fputc('\n', fileOut)
#define putchar(_Character) fputc(_Character, termOut), fputc(_Character, fileOut)
#else  // ���]�� 
#endif

FILE* __cdecl __ncrt_iob_func(
    unsigned _Ix
);

#endif