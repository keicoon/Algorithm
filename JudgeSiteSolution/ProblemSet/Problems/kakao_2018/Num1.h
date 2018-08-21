#pragma once

#include "Problem.h"
#include <iostream>
#include <cstring>

namespace kakao_num1
{
	struct TestSet
	{
		int n;
		int arr1[16];
		int arr2[16];
	};

	class MyProblem : Problem
	{
	public:
		void InitTestSet() override
		{
			TestSet& TestSet_1 = _TestSet[0];
			{
				TestSet_1.n = 5;
				int arr1[5] = { 9, 20, 28, 18, 11 };
				int arr2[5] = { 30, 1, 21, 17, 28 };
				std::memcpy(TestSet_1.arr1, arr1, sizeof(arr1));
				std::memcpy(TestSet_1.arr2, arr2, sizeof(arr2));
			}
			TestSet& TestSet_2 = _TestSet[1];
			{
				TestSet_2.n = 6;
				int arr1[6] = { 46, 33, 33 ,22, 31, 50 };
				int arr2[6] = { 27 ,56, 19, 14, 14, 10 };
				std::memcpy(TestSet_2.arr1, arr1, sizeof(arr1));
				std::memcpy(TestSet_2.arr2, arr2, sizeof(arr2));
			}
		}

		void Run(int TestSetNum) override
		{
			std::cout << "================" << std::endl;
			std::cout << "TestSet_" << TestSetNum + 1 << std::endl;

			TestSet TestSet = _TestSet[TestSetNum];

			char buf[255];
			int buf_idx = 0;

			for (int i = 0; i < TestSet.n; i++)
			{
				buf_idx += TestSet.n;
				int local_buf_index = buf_idx;
				const int Mask = 0x1;
				int V = TestSet.arr1[i] | TestSet.arr2[i];

				for (int j = 0; j < TestSet.n; j++)
				{
					int Wall = V & Mask;
					if (Wall == 0x1)
					{
						buf[--local_buf_index] = '#';
					}
					else
					{
						buf[--local_buf_index] = ' ';
					}
					V = V >> 1;
				}
				buf[buf_idx++] = '\n';
			}
			buf[buf_idx] = '\0';

			printf("%s", buf);
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
		TestSet _TestSet[2];
	};
}