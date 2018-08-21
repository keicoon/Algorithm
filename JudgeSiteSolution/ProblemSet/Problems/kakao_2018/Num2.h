#pragma once

#include "Problem.h"
#include <iostream>
#include <cstring>

namespace kakao_num2
{
	struct TestSet
	{
		char score[255];
	};

	class MyProblem : Problem
	{
	public:
		void InitTestSet() override
		{
			char score[7][255] = { "1S2D*3T",  "1D2S#10S", "1D2S0T", "1S*2T*3S", "1D#2S*3S", "1T2D3D#", "1D2S3T*" };
			for (int i = 0; i < 7; i++)
			{
				TestSet& TestSet = _TestSet[i];
				std::memcpy(TestSet.score, score[i], sizeof(score[i]));
			}
		}

		void Run(int TestSetNum) override
		{
			std::cout << "================" << std::endl;
			std::cout << "TestSet_" << TestSetNum + 1 << std::endl;

			TestSet TestSet = _TestSet[TestSetNum];

			int score[3] = {0, }, index = 0;
			for (int i = 0; i < 3; i++)
			{
				bool IsStar = Calcurate(TestSet.score, index, score[i]);
				if (IsStar && i > 0)
				{
					score[i - 1] *= 2;
				}
			}

			printf("%d\n", score[0] + score[1] + score[2]);
		}

		void RunAll() override
		{
			int len = sizeof(_TestSet) / sizeof(TestSet);
			for (int i = 0; i < len; i++)
			{
				Run(i);
			}
		}

	private:
		bool Calcurate(char* score_str, int& index, int& score)
		{
			if (score_str[index + 1] == '0')
			{
				score = 10;
				index += 2;
			}
			else
			{
				score = score_str[index] - 48; // ascii
				++index;
			}
			// bonus
			switch (score_str[index++])
			{
			case 'S':
				break;
			case 'D':
				score = score * score;
				break;
			case 'T':
				score = score * score * score;
				break;
			}
			// option
			bool IsStart = false;
			switch (score_str[index])
			{
			case '*':
				score *= 2;
				IsStart = true;
				++index;
				break;
			case '#':
				score *= -1;
				++index;
				break;
			}

			return IsStart;
		}

	private:
		TestSet _TestSet[7];
	};
}