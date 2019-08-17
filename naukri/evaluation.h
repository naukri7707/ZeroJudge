#pragma once
#ifndef INC_EVALUATION
#define INC_EVALUATION

typedef struct Evaluation
{
    int Result;
    int Memory;
    double Time;
}Evaluation;

Evaluation __new_Evaluation_(
    int (*func)()
);

char* __evaluation_Log_(
    Evaluation e
);

#endif