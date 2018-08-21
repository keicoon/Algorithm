#include <stdio.h>
#include <string.h>
#define INTERVAL 97

int MAP[11][26];

void setMapKeyValue(int Num, char *str)
{
    int Len = strlen(str);
    for (int i = 0; i < Len; i++)
        ++MAP[Num][str[i] - INTERVAL];
}

void makeMap()
{
    memset(MAP, 0, sizeof(MAP));
    setMapKeyValue(0, "zero"); setMapKeyValue(1, "one"); setMapKeyValue(2, "two"); setMapKeyValue(3, "three");
    setMapKeyValue(4, "four"); setMapKeyValue(5, "five"); setMapKeyValue(6, "six"); setMapKeyValue(7, "seven");
    setMapKeyValue(8, "eight"); setMapKeyValue(9, "nine"); setMapKeyValue(10, "ten");
}

int getTrans(char *numberSTR)
{
    int Num, Len = strlen(numberSTR);
    int iMap[26];
    memset(iMap, 0, sizeof(iMap));
    for (int i = 0; i < Len; i++)
        ++iMap[numberSTR[i] - INTERVAL];
     
    for (int i = 0; i < 11; i++)
    {
        bool s = true;
        for (int j = 0; j < 26;j++)
        if (MAP[i][j] != iMap[j])
            s = false;
 
        if (s)
            return i;
    }
    return -1;
}

int main()
{
    makeMap();
    int T;
    for (scanf("%d", &T); T > 0; T--)
    {
        char A[11], B[11], C[11], operator1, operator2;
        scanf("%s %c %s %c %s", &A, &operator1, &B, &operator2, C);
 
        int iA = getTrans(A), iB = getTrans(B), iC = getTrans(C);
 
        if (iC == -1)printf("No\n");
        else
        {
            switch (operator1)
            {
            case '+':
                if (iA + iB > 10) printf("No\n");
                else if ((iA + iB) == iC) printf("Yes\n");
                else  printf("No\n");
                break;
            case '-':
                if (iA - iB < 0) printf("No\n");
                else if ((iA - iB) == iC) printf("Yes\n");
                else  printf("No\n");
                break;
            case '*':
                if (iA * iB > 10) printf("No\n");
                else if ((iA * iB) == iC) printf("Yes\n");
                else  printf("No\n");
                break;
            }
        }
    }
 
    return 0;
}


출처: http://keicoon15.tistory.com/category/ACM준비/algospot [Temp]