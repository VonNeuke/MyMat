//ARRAY.cpp
#include "StdAfx.h"
#include "ARRAY.h"
#include<cstring>
#include<cstdlib>
#include<ctime>
using namespace std;

ARRAY::ARRAY(void)
{
	Row = 0;
	Line = 0;
	memset(arr, 0, sizeof(arr));
}
ARRAY::~ARRAY(void)
{
}
//获取行
void ARRAY::getRow(ARRAY TEMP, int rRow)
{
	Row = 1;
	Line = TEMP.Line;
	for (int i = 0; i < Line; i++)
	{
		arr[0][i] = TEMP.arr[rRow][i];
	}
}
//获取列
void ARRAY::getLine(ARRAY TEMP, int rLine)
{
	Line = 1;
	Row = TEMP.Row;
	for (int i = 0; i < Row; i++)
	{
		arr[i][0] = TEMP.arr[i][rLine];
	}
}
//获取指定元素
double ARRAY::getPixel(int rRow, int rLine)
{
	return arr[rRow][rLine];
}
//设置指定元素
void ARRAY::setPixel(int rRow, int rLine, double value)
{
	arr[rRow][rLine] = value;
}
//矩阵相加
void ARRAY::add(ARRAY A, ARRAY B)
{

	Row = B.Row;
	Line = B.Line;
	for (int i = 0; i<Row; i++)
		for (int j = 0; j<Line; j++)
			arr[i][j] = A.arr[i][j] + B.arr[i][j];
}
//矩阵相减
void ARRAY::sub(ARRAY A, ARRAY B)
{
	Row = B.Row;
	Line = B.Line;
	for (int i = 0; i<Row; i++)
		for (int j = 0; j<Line; j++)
			arr[i][j] = A.arr[i][j] - B.arr[i][j];
}
//矩阵相乘
void ARRAY::mutiply(ARRAY A, ARRAY B)
{
	Row = A.Row;
	Line = B.Line;
	for (int i = 0; i<Row; i++)
		for (int j = 0; j<Line; j++)
		{
			for (int k = 0; k<B.Row; k++)
				arr[i][j] += A.arr[i][k] * B.arr[k][j];
		}
}
//矩阵转置
void ARRAY::trans(ARRAY TEMP)
{
	Row = TEMP.Line;
	Line = TEMP.Row;
	for (int i = 0; i<Row; i++)
		for (int j = 0; j<Line; j++)
		{
			arr[i][j] = TEMP.arr[j][i];
		}
}
//矩阵求行列式
double ARRAY::hanglieshi(ARRAY TEMP)
{
	Row = TEMP.Row;
	Line = TEMP.Line;
	for (int i = 0; i<Row; i++)
		for (int j = 0; j<Line; j++)
			arr[i][j] = TEMP.arr[i][j];
	int n = Row;
	double sum = 1.0;
	double t;
	if (n == 1)
		sum = arr[0][0];
	else
	{
		int symbol = 1;//标记交换的次数
		for (int i = 0; i<n - 1; i++)
		{
			for (int j = i + 1; j<n; j++)
			{
				if (arr[i][i] == 0)//判断主对角线元素是否为0
				{
					if (i == n - 1)
						return 0;
					else
					{
						int m = i + 1;
						for (; m < n; m++)
						{
							if (arr[m][i] != 0)
							{
								for (int k = i; k < n; k++)//进行行交换
								{
									double temp = arr[i][k];
									arr[i][k] = arr[m][k];
									arr[m][k] = temp;
								}
								symbol = symbol*(-1);
								break;
							}
						}
						if (m == n)
							return 0;
					}
				}
				t = arr[j][i];
				for (int k = i; k < n; k++)//计算行列式的值
					arr[j][k] = arr[j][k] + (-1)*(t / arr[i][i] * arr[i][k]);
			}
		}
		for (int i = 0; i < n; i++)
			sum = sum * arr[i][i];
		sum = sum*symbol;
	}
	return sum;
}
//求伴随矩阵
void ARRAY::bansui(ARRAY TEMP)
{
	Row = TEMP.Row;
	Line = TEMP.Line;
	ARRAY yuzi, temp;
	if (Row == 1)
	{
		arr[0][0] = 1;
		return;
	}
	yuzi.Row = Row - 1;
	yuzi.Line = Line - 1;
	for (int i = 0; i < Row; i++) 
	{
		for (int j = 0; j < Row; j++)
		{
			//求矩阵的余子矩阵
			for (int m = 0; m < yuzi.Row; m++)
			{
				for (int n = 0; n < yuzi.Line; n++)
				{
					if (m < i&&n < j)
					{
						yuzi.arr[m][n] = TEMP.arr[m][n];
					}
					else if(m < i&&n >= j)
					{
						yuzi.arr[m][n] = TEMP.arr[m][n + 1];
					}
					else if (m >= i&&n < j)
					{
						yuzi.arr[m][n] = TEMP.arr[m +1][n];
					}
					else if (m >= i&&n >= j)
					{
						yuzi.arr[m][n] = TEMP.arr[m + 1][n+1];
					}
				}
			}
			//arr[j][i] = TEMP.arr[i][j] * temp.hanglieshi(yuzi);
			arr[j][i] = temp.hanglieshi(yuzi);
			if ((i + j) % 2 == 1)
			{
				arr[j][i] = arr[j][i] * (-1);
			}
		}
	}
}
//求逆矩阵
void ARRAY::inv(ARRAY BANSUI, double HANGLIESHI)
{
	Row = BANSUI.Row;
	Line = BANSUI.Line;
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Line; j++)
		{
			arr[i][j] = BANSUI.arr[i][j] / HANGLIESHI;
		}
	}
}
//输出矩阵
CString ARRAY::out(void)
{
	CString st, st1;
	for (int i = 0; i<Row; i++)
	{
		for (int j = 0; j<Line; j++)
		{
			st1.Format(_T("%.1lf "), arr[i][j]);
			st = st + st1;
		}
		st1.Format(_T("\r\n"));
		st += st1;
	}
	return st;
}
//void ARRAY::copy(ARRAY TEMP)
//{
//	Row = TEMP.Row;
//	Line = TEMP.Line;
//	for (int i = 0; i<Row; i++)
//		for (int j = 0; j<Line; j++)
//			arr[i][j] = TEMP.arr[i][j];
//}
//void ARRAY::Aarray_2_3_A(void)
//{
//	Row = 2;
//	Line = 3;
//	int num;
//	srand((unsigned)time(NULL));
//	for (int i = 0; i<Row; i++)
//		for (int j = 0; j<Line; j++)
//		{
//			num = rand() % 4;
//			arr[i][j] = num;
//		}
//}
//void ARRAY::Aarray_3_3_A(void)
//{
//	Row = 3;
//	Line = 3;
//	int num;
//	srand((unsigned)time(NULL));
//	for (int i = 0; i<Row; i++)
//		for (int j = 0; j<Line; j++)
//		{
//			num = rand() % 10;
//			arr[i][j] = num;
//		}
//}
//void ARRAY::Aarray_3_2_B(void)
//{
//	Row = 3;
//	Line = 2;
//	int num;
//	srand((unsigned)time(NULL));
//	for (int i = 0; i<Row; i++)
//		for (int j = 0; j<Line; j++)
//		{
//			num = rand() % 5;
//			arr[i][j] = num;
//		}
//}
//void ARRAY::Aarray_3_3_B(void)
//{
//	Row = 3;
//	Line = 3;
//	int num;
//	srand((unsigned)time(NULL));
//	for (int i = 0; i<Row; i++)
//		for (int j = 0; j<Line; j++)
//		{
//			num = rand() % 7;
//			arr[i][j] = num;
//		}
//}