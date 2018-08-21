#include <stdio.h>
 
typedef struct{
    int price, point;
}_ds;
_ds MAP[201][101];
int N, M;
void sort()
{
    for (int k = 0; k < M; k++)
    for (int i = 0; i < N; i++)
    for (int j = i+1; j < N; j++)
        if (MAP[i][k].point < MAP[j][k].point)
            {
                _ds temp = MAP[i][k];
                MAP[i][k] = MAP[j][k];
                MAP[j][k] = temp;
            }
}
int solve()
{
    int Small = 9999999;
    for (int i = 0; i < M; i++){
        int _count = MAP[0][i].price, _point = MAP[0][i].point;
        for (int j = 1; j < N; j++)
            if (_point < MAP[j][i].price)
            {
                _count += (MAP[j][i].price - _point);
                _point = MAP[j][i].point;
            }
            else
            {
                _point += -MAP[j][i].price + MAP[j][i].point;
            }
        if (Small > _count)
            Small = _count;
    }
    return Small;
}
int main()
{
    int C;
    for (scanf("%d", &C); C > 0; C--)
    {
        scanf("%d %d", &N, &M);
        for (int i = 0; i < N;i++)
        for (int j = 0; j < M; j++)
            scanf("%d %d", &MAP[i][j].price, &MAP[i][j].point);
         
        sort();
 
        printf("%d\n", solve());
    }
    return 0;
}