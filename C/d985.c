#include<stdio.h>

int main()
{
    int track, lap, time, best, sum, min, sec;
    while (scanf(" %d", &track) == 1)
    {
        for (int t = 1; t <= track; t++)
        {
            best = 999999, sum = 0;
            scanf(" %d", &lap);
            for (int l = 0; l < lap; l++)
            {
                scanf(" %d %d", &min, &sec);
                time = min * 60 + sec;
                if (time < best)
                    best = time;
                sum += time;
            }
            sum /= lap;
            printf("Track %d:\n", t);
            printf("Best Lap: %d minute(s) %d second(s).\n", best / 60, best % 60);
            printf("Average: %d minute(s) %d second(s).\n\n", sum / 60, sum % 60);
        }
    }
    return 0;
}