// concept idea
// using std::vector

// init
/*
make array by params `T`.
*/

// action
/*
find value by index.
and swap by using std::vector::emplace, emplace_back.
*/

// solve
/*
find key by ordered number.
and check neared value in index's value.
if is not valid increase solve_count.
erase current number in vector.
solve that all array's value.

finally solve_count is answer.
*/

#include <stdio.h>
#include <vector>

#define SWAP(x,y) { int t; t = x; x = y; y = t;}

using namespace std;

vector<int> list;

void swap(bool left, int X, int Y)
{
    std::vector<int>::iterator x, y;
    for (auto it = list.begin() ; it != list.end(); ++it)
    {
        if(*it == X)
        {
            x = it;
        }
        else if(*it == Y)
        {
            y = it;
        }
    }

    if(left)
    {
        if(y != list.begin())
        {
            SWAP(*x, *(y-1));
        }
        else
        {
            list.erase(x);
            list.emplace(list.begin(), X);
        }
    }
    else // right
    {
        if(y != list.end())
        {
            SWAP(*x, *(y+1));
        }
        else
        {
            list.erase(x);
            list.emplace_back(X);
        }
    }
}

int solve(int N)
{
    int count = 0;

    for(int i = 1; i < N; i++)
    {
        for (auto it = list.begin() ; it != list.end(); ++it)
        {
            if(*it == i)
            {
                if(it == list.begin() && *(it+1) != i+1)
                {
                    ++count;
                }
                else if(it == list.end() && *(it-1) != i-1)
                {
                    ++count;
                }
                else if(*(it+1) != i+1 || *(it-1) != i-1)
                {
                    ++count;
                }

                list.erase(it);
                --it;
            }
        }
    }

    return count;
}

int main(void)
{
	int test_case;
	int T;

	setbuf(stdout, NULL);
	scanf("%d", &T);

	for (test_case = 1; test_case <= T; ++test_case)
	{
        int N, M;
        scanf("%d %d", &N, &M);
        
        list.clear();

        for(int i = 1; i <= N;i++)
        {
            list.emplace_back(i);
        }

        for(int i = 0; i < M;i++)
        {
            char R;
            int X, Y;
            scanf("%c %d %d", &R, &X, &Y);

            swap(R == 'A', X, Y);
        }

        printf("#%d %d\n", test_case, solve(N));
	}
	return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}
