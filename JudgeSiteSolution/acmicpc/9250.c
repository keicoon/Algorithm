#include <stdio.h>
#include <string.h>

typedef struct _rk
{
    char pattern[101];
    int length;
    int h;
    int p;
    int dp;
} rk;

rk S[1001];
int d = 25, q = 101;
int N, Q;

void getHash(int index)
{
    S[index].length = strlen(S[index].pattern);
    int i = 0, h = 0, p = 1;
    for (; i < S[index].length - 1; i++)
    {
        h = (d * h + (S[index].pattern[i] - 97)) % q;
        p = (p * d) % q;
    }
    h = (d * h + (S[index].pattern[i] - 97)) % q;

    S[index].h = h;
    S[index].p = p;
}

bool compare(char *txt, int start, int index)
{
    for (int j = 0; j < S[index].length; j++)
        if (txt[start + j] != S[index].pattern[j])
            return false;
    return true;
}

bool rabinKarp(char *txt)
{
    for (int i = 0; i < N; i++)
    {
        S[i].dp = 0;
        for (int j = 0; j < S[i].length; j++)
        {
            S[i].dp = (d * S[i].dp + (txt[j] - 97)) % q;
        }
    }
    for (int i = 0; txt[i] != NULL; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (S[j].dp == -1)
                continue;
            else if (S[j].dp == S[j].h && compare(txt, i, j))
                return true;

            if (txt[i + S[j].length] != NULL)
            {
                S[j].dp = (d * (S[j].dp - (txt[i] - 97) * S[j].p) + (txt[i + S[j].length] - 97)) % q;
                if (S[j].dp < 0)
                    S[j].dp += q;
            }
            else
                S[j].dp = -1;
        }
    }
    return false;
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%s", &S[i].pattern);
        getHash(i);
    }
    scanf("%d", &Q);
    for (int i = 0; i < Q; i++)
    {
        char buff[10001];
        scanf("%s", &buff);
        printf("%s\n", (rabinKarp(buff)) ? "YES" : "NO");
    }
    return 0;
}