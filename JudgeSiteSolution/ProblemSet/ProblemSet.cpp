// ProblemSet.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

/* kakao problems */
#include "Problems/kakao_2018/Num1.h"
#include "Problems/kakao_2018/Num2.h"
#include "Problems/kakao_2018/Num3.h"
#include "Problems/kakao_2018/Num4.h"
/* samsong */
#include "Problems/samsong_2018/Num2.h"

int main()
{
	samsong_2018::Num2 Problem;

	Problem.InitTestSet();

	Problem.RunAll();

    return 0;
}

