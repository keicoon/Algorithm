#include <stdio.h>
#include <stdlib.h>
#include <cstring>

#define MAX_LEN 30001
using namespace std;

char *str, *solve;
int idx = 0;

void shift(const int &j, bool is_left)
{
    memcpy(&solve[idx++], &str[is_left ? 0 : j], 1);
    if(is_left)
    {
        memcpy(str, &str[1], j); // 땡겨오기
    }
    str[j + 1] = '\0';
}

int main()
{    
    int test_case;
	int T;

    setbuf(stdout, NULL);
	scanf("%d", &T);

    str = (char*)malloc(MAX_LEN);
    solve = (char*)malloc(MAX_LEN);

    for (test_case = 1; test_case <= T; ++test_case)
	{
        scanf("%s", str);

        for(int j = strlen(str) - 1; 0 < j; j--)
        {
            if(str[0] < str[j])
            {
                shift(j, true);
            }
            else if(str[0] > str[j])
            {
                shift(j, false);
            }
            else // str[i] == str[j]
            {
                int k = 0, l = j;
                
                for(;str[k] == str[l]; k++, l--);

                if(str[k] < str[l])
                {
                    shift(j, true);
                }
                else
                {
                    shift(j, false);
                }
            }
        }
        shift(0, false); // 마지막
	    
        solve[idx] = '\0';
        printf("#%d %s\n", test_case, solve);
    }

    free(str);
    free(solve);
    
    return 1;
}
