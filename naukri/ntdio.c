#include <stdio.h>
#include <naukri/ntdio.h>

FILE* files[4];
const char filesMode[][3] = { "r", "w+", "w", "w+" };
const char filesName[][15] = { FILE_INPUT, FILE_OUTPUT, FILE_ERROR, FILE_COMPARE };

FILE* __cdecl __ncrt_iob_func(unsigned _Ix)
{
    if (files[_Ix] == NULL)
    {
        files[_Ix] = fopen(filesName[_Ix], filesMode[_Ix]);
    }
    return files[_Ix];
}
