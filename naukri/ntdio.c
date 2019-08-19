#include <stdio.h>
#include <naukri.h>
#include <naukri/ntdio.h>

FILE* files[3];
const char filesMode[][3] = { "r", "w+", "w+" };
const char filesName[][20] = { FILE_INPUT, FILE_OUTPUT, FILE_COMPARE };

FILE* __cdecl __ncrt_iob_func(unsigned _Ix)
{
    if (files[_Ix] == NULL)
    {
        files[_Ix] = fopen(filesName[_Ix], filesMode[_Ix]);
    }
    return files[_Ix];
}
