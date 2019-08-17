#include <naukri/comparison.h>
#include <naukri/debug.h>
#include <stdio.h>
#include <string.h>

#define TLE 1000

static char* tolerantify(char dst[], FILE * src)
{
    do
    {
        dst = fgets(dst, BUFSIZ, src);
        if (dst == NULL)
            return NULL;
    } while (dst[0] == '\n');
    int s = 0, e = strlen(dst) - 1;
    if (dst[e] == '\n')
        e--;
    while (dst[s] == ' ')
        s++;
    while (dst[e] == ' ' && e > s)
        e--;
    dst[e + 1] = '\0';
    return dst + s;
}

void __comparison_Cmp_(Evaluation e_main)
{
    fseek(fileOut, 0, SEEK_SET), fseek(fileCmp, 0, SEEK_SET);
    int line = 0, wa = 0;
    char srcBuf[BUFSIZ], cmpBuf[BUFSIZ], * fmtSrc, * fmtCmp;
    for (;;)
    {
        line++;
        fmtSrc = tolerantify(srcBuf, fileOut), fmtCmp = tolerantify(cmpBuf, fileCmp);
        if (fmtSrc == NULL || fmtCmp == NULL)
            break;
        if (strcmp(fmtSrc, fmtCmp))
            Debug.Log("WA (line:%d)\n�z�����׬�: %s\n���T���׬�: %s", line, fmtSrc, fmtCmp), ++wa;
    }
    if (fmtCmp != NULL && fmtCmp[0] == '\n')
        fmtCmp = tolerantify(cmpBuf, fileCmp);
    if (fmtSrc != NULL && fmtSrc[0] == '\n')
        fmtSrc = tolerantify(srcBuf, fileOut);
    if (fmtCmp != NULL)
        Debug.Log("WA (line:%d)\n��X�ɹL�p�A�z�@��X %d ��", line, line - 1);
    else if (fmtSrc != NULL)
        Debug.Log("OLE (%s)\n�Фſ�X�D�إ��n�D����r:\n%s", __evaluation_Log_(e_main), fmtSrc);
    else if (wa)
        Debug.Log("WA (%s)\n�z�@�� %d �ӿ��~", __evaluation_Log_(e_main), wa);
    else if (e_main.Time > TLE)
        Debug.Log("TLE (%s)", __evaluation_Log_(e_main));
    else
        Debug.Log("AC (%s)", __evaluation_Log_(e_main));
}
