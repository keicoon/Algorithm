#pragma once

class Problem
{
	virtual void InitTestSet() = 0;
	virtual void Run(int TestSetNum) = 0;
	virtual void RunAll() = 0;
};