//ARRAY.h
#pragma once
class ARRAY
{
public:
	double arr[10][10];//��ž���
	int Row;//�������
	int Line;//�������
	ARRAY(void);//����
	~ARRAY(void);//����

	void getRow(ARRAY TEMP, int rRow);//��ȡ��
	void getLine(ARRAY TEMP, int rLine);//��ȡ��
	double getPixel(int rRow, int rLine);//��ȡ�ض�Ԫ��
	void setPixel(int rRow, int rLine, double value);//�����ض�Ԫ��

	void add(ARRAY A, ARRAY B);//�������
	void sub(ARRAY A, ARRAY B);//�������
	void mutiply(ARRAY A, ARRAY B);//�������
	void trans(ARRAY TEMP);//ת�þ���
	double hanglieshi(ARRAY TEMP);//������ʽ
	void bansui(ARRAY TEMP);//�������
	void inv(ARRAY BANSUI, double HANGLIESHI);//�����
	CString out();//�������
	//void copy(ARRAY TEMP);//��������
	//void Aarray_2_3_A(void);//�������2*3�ľ���Ԫ��С��4
	//void Aarray_3_3_A(void);//�������3*3�ľ���Ԫ��С��10
	//void Aarray_3_2_B(void);//�������3*2�ľ���Ԫ��С��5
	//void Aarray_3_3_B(void);//�������3*3�ľ���Ԫ��С��7
};

