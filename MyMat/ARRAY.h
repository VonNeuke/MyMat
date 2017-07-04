//ARRAY.h
#pragma once
class ARRAY
{
public:
	double arr[10][10];//存放矩阵
	int Row;//矩阵的行
	int Line;//矩阵的列
	ARRAY(void);//构造
	~ARRAY(void);//析构

	void getRow(ARRAY TEMP, int rRow);//获取行
	void getLine(ARRAY TEMP, int rLine);//获取列
	double getPixel(int rRow, int rLine);//获取特定元素
	void setPixel(int rRow, int rLine, double value);//设置特定元素

	void add(ARRAY A, ARRAY B);//矩阵相加
	void sub(ARRAY A, ARRAY B);//矩阵相减
	void mutiply(ARRAY A, ARRAY B);//矩阵相乘
	void trans(ARRAY TEMP);//转置矩阵
	double hanglieshi(ARRAY TEMP);//求行列式
	void bansui(ARRAY TEMP);//伴随矩阵
	void inv(ARRAY BANSUI, double HANGLIESHI);//逆矩阵
	CString out();//输出矩阵
	//void copy(ARRAY TEMP);//拷贝矩阵
	//void Aarray_2_3_A(void);//随机生成2*3的矩阵元素小于4
	//void Aarray_3_3_A(void);//随机生成3*3的矩阵元素小于10
	//void Aarray_3_2_B(void);//随机生成3*2的矩阵元素小于5
	//void Aarray_3_3_B(void);//随机生成3*3的矩阵元素小于7
};

