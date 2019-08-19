#include <stdio.h>
#include <string.h>
#include <naukri.h>
#include <naukri\debug.h>
#define BUFSIZ 1024

__debug_ Debug;

static void print(const char* _Format, ...)
{
    int j = 0;
    char src[BUFSIZ];
    va_list _ArgList;
    __crt_va_start(_ArgList, _Format);
    vsprintf(src, _Format, _ArgList);
    __crt_va_end(_ArgList);
    fputs(src, termOut);
}

static void log(const char* _Format, ...)
{
    int j = 3;
    char src[BUFSIZ], dst[BUFSIZ] = { "\n> " };
    va_list _ArgList;
    __crt_va_start(_ArgList, _Format);
    vsprintf(src, _Format, _ArgList);
    __crt_va_end(_ArgList);
    for (int i = 0; src[i]; i++)
    {
        dst[j++] = src[i];
        if (src[i] == '\n')
            dst[j++] = '>', dst[j++] = ' ';
    }
    do {
        j--;
    } while ((dst[j] == '>' || dst[j] == '\n') && j > 0);
    dst[j + 1] = '\n', dst[j + 2] = '\0';
    fputs(dst, termOut);
}

static int command(const char* _Format, ...)
{
    char fmtcmd[BUFSIZ];
    int _Result;
    va_list _ArgList;
    __crt_va_start(_ArgList, _Format);
    _Result = vsprintf(fmtcmd, _Format, _ArgList);
    __crt_va_end(_ArgList);
    system(fmtcmd);
    return _Result;
}

static void showFile(const char* _FileName)
{
    command("notepad %s", _FileName);
}

__debug_ __new_Debug_()
{
    if (Debug.Log == NULL)
    {
        Debug.Command = command;
        Debug.Log = log;
        Debug.Print = print;
        Debug.ShowFile = showFile;
    }
    return Debug;
}