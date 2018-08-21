#pragma once

#include "Problem.h"
#include <iostream>
#include <locale>
#include <vector>
#include <map>
#include <algorithm>

/* @TODO: 
 * "cities는 도시 이름으로 이뤄진 문자열 배열로, 최대 도시 수는 100,000개이다."
 * 위 조건은 stack에 넣기에 너무 큰 크기이므로 TestSet에서는 최대 도시 수를 100개로 제한함
 * TestSet 이외의 data를 입력 받을 시 heap에 동적할당 받도록 수정해야 함
 */ 

namespace kakao_num3
{
	struct TestSet
	{
		int cache_size;
		char cities[100][20];
	};

	class MyProblem : Problem
	{
	public:
		void InitTestSet() override
		{
			TestSet& TestSet_1 = _TestSet[0];
			{
				TestSet_1.cache_size = 3;
				char cities[100][20] = { "Jeju", "Pangyo", "Seoul", "NewYork", "LA", "Jeju", "Pangyo", "Seoul", "NewYork", "LA" };
				std::memcpy(TestSet_1.cities, cities, sizeof(cities));
			}
			TestSet& TestSet_2 = _TestSet[1];
			{
				TestSet_2.cache_size = 3;
				char cities[100][20] = { "Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul" };
				std::memcpy(TestSet_2.cities, cities, sizeof(cities));
			}
			TestSet& TestSet_3 = _TestSet[2];
			{
				TestSet_3.cache_size = 2;
				char cities[100][20] = { "Jeju", "Pangyo", "Seoul", "NewYork", "LA", "SanFrancisco", "Seoul", "Rome", "Paris", "Jeju", "NewYork", "Rome" };
				std::memcpy(TestSet_3.cities, cities, sizeof(cities));
			}
			TestSet& TestSet_4 = _TestSet[3];
			{
				TestSet_4.cache_size = 5;
				char cities[100][20] = { "Jeju", "Pangyo", "Seoul", "NewYork", "LA", "SanFrancisco", "Seoul", "Rome", "Paris", "Jeju", "NewYork", "Rome" };
				std::memcpy(TestSet_4.cities, cities, sizeof(cities));
			}
			TestSet& TestSet_5 = _TestSet[4];
			{
				TestSet_5.cache_size = 2;
				char cities[100][20] = { "Jeju", "Pangyo", "NewYork", "newyork" };
				std::memcpy(TestSet_5.cities, cities, sizeof(cities));
			}
			TestSet& TestSet_6 = _TestSet[5];
			{
				TestSet_6.cache_size = 0;
				char cities[100][20] = { "Jeju", "Pangyo", "Seoul", "NewYork", "LA" };
				std::memcpy(TestSet_6.cities, cities, sizeof(cities));
			}
		}

		void Run(int TestSetNum) override
		{
			std::cout << "================" << std::endl;
			std::cout << "TestSet_" << TestSetNum + 1 << std::endl;

			TestSet TestSet = _TestSet[TestSetNum];

			int cache_size = TestSet.cache_size;
			//
			std::vector<char*> alloc_mem;
			std::map<char*, int> cache;
			std::map<char*, int>::iterator it;
			std::locale loc;
			int cache_index = 0, lru_count = 0;
			int time = 0;

			for (int i = 0;; i++)
			{
				char* city = new char[20];
				alloc_mem.push_back(city);

				std::memcpy(city, TestSet.cities[i], 20);
				toLower(city);

				char alphabet = city[0];
				if ((alphabet >= 'a' && alphabet <= 'z') || (alphabet >= 'A' && alphabet <= 'Z'))
				{
					it = std::find_if(cache.begin(), cache.end(),
						[city](decltype(cache)::value_type& vt) {
							return strcmp(city, vt.first) == 0;
					});
					if (it == cache.end())
					{
						if (cache_index < cache_size)
						{
							++cache_index;
						}
						else
						{
							it = std::min_element(cache.begin(), cache.end(),
								[](decltype(cache)::value_type& l, decltype(cache)::value_type& r) -> bool { return l.second < r.second; });
							if (it != cache.end())
								cache.erase(it);
						}
						cache[city] = lru_count++;
						time += 5;
					}
					else
					{
						(*it).second = lru_count++;
						time += 1;
					}
				}
				// end
				else
				{
					break;
				}
			}

			for (std::vector<char*>::size_type i = 0; i < alloc_mem.size(); ++i)
			{
				delete alloc_mem[i];
			}
			printf("%d\n", time);
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
		void toLower(char* str)
		{
			for (int index = 0; str[index] != '\0'; index++)
			{
				if (str[index] <= 'Z' && str[index] >= 'A')
				{
					str[index] -= ('Z' - 'z');
				}
			}
		}
	private:
		TestSet _TestSet[6];
	};
}