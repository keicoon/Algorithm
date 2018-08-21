#pragma once

#include "Problem.h"
#include <iostream>
#include <vector>
#include <algorithm>

namespace kakao_num4
{
	struct TestSet
	{
		int n;
		int t;
		int m;
		std::vector<int> timetable;
	};

	class MyProblem:Problem
	{
	public:
		void InitTestSet() override
		{
			{
				TestSet TestSet;
				TestSet.n = 1;
				TestSet.t = 1;
				TestSet.m = 5;
				char timetable[][6] = { "08:00", "08:01", "08:02", "08:03" };
				for (int i = 0; i < 4; i++)
				{
					TestSet.timetable.push_back(GetMinuates(timetable[i]));
				}
				_TestSet.push_back(TestSet);
			}
			{
				TestSet TestSet;
				TestSet.n = 2;
				TestSet.t = 10;
				TestSet.m = 2;
				char timetable[][6] = { "09:10", "09:09", "08:00" };
				for (int i = 0; i < 3; i++)
				{
					TestSet.timetable.push_back(GetMinuates(timetable[i]));
				}
				_TestSet.push_back(TestSet);
			}
			{
				TestSet TestSet;
				TestSet.n = 2;
				TestSet.t = 1;
				TestSet.m = 2;
				char timetable[][6] = { "09:00", "09:00", "09:00", "09:00" };
				for (int i = 0; i < 4; i++)
				{
					TestSet.timetable.push_back(GetMinuates(timetable[i]));
				}
				_TestSet.push_back(TestSet);
			}
			{
				TestSet TestSet;
				TestSet.n = 1;
				TestSet.t = 1;
				TestSet.m = 5;
				char timetable[][6] = { "00:01", "00:01", "00:01", "00:01", "00:01" };
				for (int i = 0; i < 5; i++)
				{
					TestSet.timetable.push_back(GetMinuates(timetable[i]));
				}
				_TestSet.push_back(TestSet);
			}
			{
				TestSet TestSet;
				TestSet.n = 1;
				TestSet.t = 1;
				TestSet.m = 1;
				char timetable[][6] = { "23:59" };
				for (int i = 0; i < 1; i++)
				{
					TestSet.timetable.push_back(GetMinuates(timetable[i]));
				}
				_TestSet.push_back(TestSet);
			}
			{
				TestSet TestSet;
				TestSet.n = 10;
				TestSet.t = 60;
				TestSet.m = 45;
				char timetable[][6] = { "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59" };
				for (int i = 0; i < 16; i++)
				{
					TestSet.timetable.push_back(GetMinuates(timetable[i]));
				}
				_TestSet.push_back(TestSet);
			}
		}

		void Run(int TestSetNum) override
		{
			std::cout << "================" << std::endl;
			std::cout << "TestSet_" << TestSetNum + 1 << std::endl;

			TestSet TestSet = _TestSet[TestSetNum];

			std::sort(TestSet.timetable.begin(), TestSet.timetable.end());
			int Index = 0, Len = (int)TestSet.timetable.size();
			
			int Time, m, M = TestSet.m;
			for (int n = 0; n < TestSet.n; n++)
			{
				if (n == 0)
				{
					Time = 540;
				}
				else if(Index < Len)
				{
					Time += TestSet.t;
				}

				m = 0;

				for (;Index < Len;)
				{
					if (m++ < M && TestSet.timetable[Index] < Time)
					{
						++Index;
					}
					else
					{
						break;
					}
				}
			}

			int LastTime = Time;
			if (m >= M)
			{
				int LastCrawTime = (Index < Len) ? TestSet.timetable[Index] : TestSet.timetable[Len - 1];
				if (LastCrawTime <= LastTime)
				{
					LastTime = LastCrawTime - 1;
				}
			}

			int hour = LastTime / 60, minuate = LastTime % 60;
			
			char buf[6];
			sprintf_s(buf, "%2d:%2d", hour, minuate);
			for (int i = 0; buf[i] != '\0'; i++)
			{
				if (buf[i] == ' ')
				{
					buf[i] = '0';
				}
			}
			printf("%s\n", buf);
		}

		void RunAll() override
		{
			int len = (int)_TestSet.size();
			for (int i = 0; i < len; i++)
			{
				Run(i);
			}
		}

	private:
		int GetMinuates(char* str)
		{
			int hour, minuate;

			char buf[3];
			memcpy(buf, &str[0], 2);
			hour = atoi(buf);
			memcpy(buf, &str[3], 2);
			minuate = atoi(buf);

			return hour * 60 + minuate;
		}

	private:
		std::vector<TestSet> _TestSet;
	};
}