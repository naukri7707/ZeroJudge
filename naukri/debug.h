#pragma once
#ifndef INC_DEBUG
#define INC_DEBUG

#define BUFSIZ 1024

typedef struct __debug_
{
    int (*Command)(const char* _Format, ...);
    void (*Log)(const char* _Format, ...);
    void (*Print)(const char* _Format, ...);
    void (*ShowFile)(const char* _FileName);
}__debug_;

extern __debug_ Debug;

__debug_ __new_Debug_(
    void
);

#endif