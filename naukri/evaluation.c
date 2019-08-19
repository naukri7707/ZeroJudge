#include <Windows.h>
#include <Psapi.h>
#include <stdio.h>
#include <naukri.h>
#include <naukri/evaluation.h>

char e_buf[10];

static int getPeakWorkingSetSize()
{
    PROCESS_MEMORY_COUNTERS pmc;
    GetProcessMemoryInfo(GetCurrentProcess(), &pmc, sizeof(pmc));
    return pmc.PeakWorkingSetSize / 1000;
}

char* __evaluation_Log_(Evaluation e)
{
    if (e.Time < 1000)
    {
        if (e.Memory < 1024)
            sprintf(e_buf, "%.0lfms, %dKB", e.Time, e.Memory);
        else
            sprintf(e_buf, "%.0lfms, %dMB", e.Time, e.Memory / 1024);
    }
    else
    {
        if (e.Memory < 1024)
            sprintf(e_buf, "%.1lfs, %dKB", e.Time / 1000, e.Memory);
        else
            sprintf(e_buf, "%.1lfs, %dMB", e.Time / 1000, e.Memory / 1024);
    }
    return e_buf;
}

Evaluation __new_Evaluation_(int (*func)())
{
    Evaluation res;
    res.Memory = getPeakWorkingSetSize();
    LARGE_INTEGER freq, beginTime, endTime;
    QueryPerformanceFrequency(&freq); // 獲取時鐘週期
    QueryPerformanceCounter(&beginTime); // 獲取時鐘計數
    res.Result = func();
    QueryPerformanceCounter(&endTime);
    res.Time = (endTime.QuadPart - beginTime.QuadPart) * 1000 / freq.QuadPart;
    res.Memory = getPeakWorkingSetSize() - res.Memory;
    return res;
}