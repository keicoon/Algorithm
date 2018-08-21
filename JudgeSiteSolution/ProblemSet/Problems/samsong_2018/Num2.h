#pragma once

#include "Problem.h"
#include <iostream>
#include <vector>

namespace samsong_2018
{
	using namespace std;

    struct TestSet
	{
		int T; // 1 <= T <= 30
		int n[30]; // 1 <= n <= 10,000
	};

    class Num2 : Problem
	{
    private:
		TestSet _TestSet[1];
	
	private:
		vector<int> palidrome_list;
		int min_depth;
		const int max_depth = 3;
		int answer[3];

	public:
		void InitTestSet() override
		{
			TestSet& TestSet_1 = _TestSet[0];
			{
				TestSet_1.T = 2;
				int arr1[5] = { 6, 124 };
				std::memcpy(TestSet_1.n, arr1, sizeof(arr1));
			}
		}

		bool is_palindrome(int v)
		{
			char buffer[6];
			_itoa_s(v, buffer, 10); // :(
			int l = (int)strlen(buffer);
			for(int i = 0, l_i = l - 1, n = l / 2; i < n; i++)
			{
				if(buffer[i] != buffer[l_i - i])
				{
					return false;
				}
			}
			return true;
		}

		int search(int value, int cur_depth)
		{
			if (cur_depth <= max_depth)
			{
				for ( auto target_value : palidrome_list )
				{
					int delta = value - target_value;
					if(delta == 0)
					{
						answer[cur_depth - 1] = target_value;
						min_depth = cur_depth; // set depth bound
						return cur_depth;
					}
					else if (delta > 0 && (cur_depth < min_depth))
					{
						int last_depth = search(delta, cur_depth + 1);
						if(last_depth > 0) // valid check
						{
							answer[cur_depth - 1] = target_value;
							return last_depth;
						}
					}
				}
			}

			return 0; // invalid
		}

		void Run(int TestSetNum) override
		{
			std::cout << "================" << std::endl;
			std::cout << "TestSet_" << TestSetNum + 1 << std::endl;

			TestSet TestSet = _TestSet[TestSetNum];
            // --------------------
			for(int i = 10000; i >= 1; i--)
			{
				if(is_palindrome(i))
				{
					palidrome_list.push_back(i);
				}
			}

			for(int i = 0; i < TestSet.T; i++)
            {
				std::cout << "CASE#" << (i + 1) << "\n";
				
				min_depth = 4; // init
                
				int value = TestSet.n[i];
				int depth = search(value, 1);
 				
				 std::cout << depth;
				for(int j = 0; j < depth; j++)
				{
					std::cout << " " << answer[j];
				}
				std::cout << "\n";
            }
		}

		void RunAll() override
		{
			int len = sizeof(_TestSet) / sizeof(TestSet);
			for (int i = 0; i < len; i++)
			{
				Run(i);
			}
		}
    };
}