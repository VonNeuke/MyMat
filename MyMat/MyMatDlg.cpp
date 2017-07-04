// MyMatDlg.cpp : ʵ���ļ�
#include "stdafx.h"
#include "MyMat.h"
#include "MyMatDlg.h"
#include "afxdialogex.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
// CMyMatDlg �Ի���
CMyMatDlg::CMyMatDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MYMAT_DIALOG, pParent)
	, m_edit_row(0)
	, m_edit_col(0)
	, m_edit_data(0)
	, m_edit_x(0)
	, m_edit_y(0)
	, m_edit_value(0)
	, m_edit_getrl(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	flg = 0;
}
void CMyMatDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//��������ı�������
	DDX_Text(pDX, IDC_EDIT_row, m_edit_row);
	DDX_Text(pDX, IDC_EDIT_col, m_edit_col);
	DDX_Text(pDX, IDC_EDIT_data, m_edit_data);
	DDX_Control(pDX, IDC_EDIT_A, m_edit_a);
	DDX_Control(pDX, IDC_EDIT_B, m_edit_b);
	DDX_Control(pDX, IDC_EDIT_single, m_edit_single);
	DDX_Control(pDX, IDC_EDIT_double, m_edit_double);
	DDX_Text(pDX, IDC_EDIT_x, m_edit_x);
	DDX_Text(pDX, IDC_EDIT_y, m_edit_y);
	DDX_Text(pDX, IDC_EDIT_value, m_edit_value);
	DDX_Text(pDX, IDC_EDIT_getRL, m_edit_getrl);
}
BEGIN_MESSAGE_MAP(CMyMatDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//�����������Ϣ�����������
	ON_BN_CLICKED(IDC_BUTTON_add, &CMyMatDlg::OnBnClickedButtonadd)
	ON_BN_CLICKED(IDC_BUTTON_sub, &CMyMatDlg::OnBnClickedButtonsub)
	ON_BN_CLICKED(IDC_BUTTON_mutiply, &CMyMatDlg::OnBnClickedButtonmutiply)
	ON_BN_CLICKED(IDC_BUTTON_trans, &CMyMatDlg::OnBnClickedButtontrans)
	ON_BN_CLICKED(IDC_BUTTON_inv, &CMyMatDlg::OnBnClickedButtoninv)
	ON_BN_CLICKED(IDC_BUTTON_A, &CMyMatDlg::OnBnClickedButtonA)
	ON_BN_CLICKED(IDC_BUTTON_B, &CMyMatDlg::OnBnClickedButtonB)
	ON_BN_CLICKED(IDC_BUTTON_input, &CMyMatDlg::OnBnClickedButtoninput)
	ON_BN_CLICKED(IDC_BUTTON_getPixel, &CMyMatDlg::OnBnClickedButtongetpixel)
	ON_BN_CLICKED(IDC_BUTTON_setPixel, &CMyMatDlg::OnBnClickedButtonsetpixel)
	ON_BN_CLICKED(IDC_BUTTON_getRow, &CMyMatDlg::OnBnClickedButtongetrow)
	ON_BN_CLICKED(IDC_BUTTON_getLine, &CMyMatDlg::OnBnClickedButtongetline)
END_MESSAGE_MAP()
// CMyMatDlg ��Ϣ�������
BOOL CMyMatDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��
	return TRUE;
}
void CMyMatDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������
		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);
		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;
		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}
//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMyMatDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
//�Զ������Ϣ�������
//������������㡢����Ĺ��졢�����Ԫ�ص�����
//����Ԫ�ص���ȡ������������Ϣ����ȡ�ȵ�
void CMyMatDlg::OnBnClickedButtonadd()
{
	flg = 0;
	if (A.Row != B.Row || A.Line != B.Line)   //�ж��Ƿ�����������
		m_edit_double.SetWindowTextW(_T("����ľ�������ӣ�"));
	else
	{
		C.add(A, B);
		m_edit_double.SetWindowTextW(C.out());
		memset(C.arr, 0, sizeof(C.arr));
	}
}
void CMyMatDlg::OnBnClickedButtonsub()
{
	flg = 0;
	if (A.Row != B.Row || A.Line != B.Line)   //�ж��Ƿ�����������
		m_edit_double.SetWindowTextW(_T("����ľ����������"));
	else
	{
		C.sub(A, B);
		m_edit_double.SetWindowTextW(C.out());
		memset(C.arr, 0, sizeof(C.arr));
	}
}
void CMyMatDlg::OnBnClickedButtonmutiply()
{
	flg = 0;
	if (A.Line != B.Row)//�жϾ����Ƿ�����������
		m_edit_double.SetWindowTextW(_T("����ľ�������ˣ�"));
	else
	{
		C.mutiply(A, B);
		m_edit_double.SetWindowTextW(C.out());
		memset(C.arr, 0, sizeof(C.arr));
	}
}
void CMyMatDlg::OnBnClickedButtontrans()
{
	C.trans(A);
	m_edit_single.SetWindowTextW(C.out());
	memset(C.arr, 0, sizeof(C.arr));
}
void CMyMatDlg::OnBnClickedButtoninv()
{
	//UpdateData(TRUE);
	flg = 0;
	if (A.Row != A.Line)
	{
		m_edit_single.SetWindowTextW(_T("�޷����������"));
	}
	else
	{
		C.bansui(A);
		double hls = D.hanglieshi(A);
		memset(D.arr, 0, sizeof(D.arr));
		if(hls ==0)
		{
			m_edit_single.SetWindowTextW(_T("���󲻿���"));
		}
		else
		{
			D.inv(C, hls);
			m_edit_single.SetWindowTextW(D.out());
			memset(D.arr, 0, sizeof(D.arr));
		}
		memset(C.arr, 0, sizeof(C.arr));
	}
}
void CMyMatDlg::OnBnClickedButtonA()
{
	UpdateData(TRUE);
	A.Row = m_edit_row;
	A.Line = m_edit_col;
	flag = 0;
}
void CMyMatDlg::OnBnClickedButtonB()
{
	UpdateData(TRUE);
	B.Row = m_edit_row;
	B.Line = m_edit_col;
	flag = 1;
}
void CMyMatDlg::OnBnClickedButtoninput()
{
	static int m = 0;
	static CString str;
	if (flag == 0 && flg == 0)
	{
		int r, l;
		r = m / A.Line;
		l = m%A.Line;
		UpdateData(TRUE);
		A.arr[r][l] = m_edit_data;
		if (m<(A.Line*A.Row))
		{
			CString str1;
			str1.Format(_T("%.1lf "), A.arr[r][l]);
			str += str1;
			if (l == A.Line - 1)
			{
				str1.Format(_T("\r\n"));
				str += str1;
			}
			m_edit_a.SetWindowTextW(str);
		}
		m++;
		if (m == A.Line*A.Row)
		{
			m = 0;
			flg ++;
			str = (_T(""));
		}
	}
	if (flag == 1 && flg == 1)
	{
		int r, l;
		r = m / B.Line;
		l = m%B.Line;
		UpdateData(TRUE);
		B.arr[r][l] = m_edit_data;
		if (m<(B.Line*B.Row))
		{
			CString str1;
			str1.Format(_T("%.1lf "), B.arr[r][l]);
			str += str1;
			if (l == B.Line - 1)
			{
				str1.Format(_T("\r\n"));
				str += str1;
			}
			m_edit_b.SetWindowTextW(str);
		}
		m++;
		if (m == B.Line*B.Row)
		{
			m = 0;
			flg ++;
			str = (_T(""));
		}
	}
}
void CMyMatDlg::OnBnClickedButtongetpixel()
{
	UpdateData(TRUE);
	double value = A.getPixel(m_edit_x - 1, m_edit_y - 1);
	CString str;
	str.Format(_T("%.1lf "), value);
	m_edit_single.SetWindowTextW(str);

}
void CMyMatDlg::OnBnClickedButtonsetpixel()
{
	UpdateData(TRUE);
	A.setPixel(m_edit_x - 1, m_edit_y - 1, m_edit_value);
	m_edit_a.SetWindowTextW(A.out());
}
void CMyMatDlg::OnBnClickedButtongetrow()
{
	UpdateData(TRUE);
	C.getRow(A, m_edit_getrl-1);
	m_edit_single.SetWindowTextW(C.out());
	memset(C.arr, 0, sizeof(C.arr));
}
void CMyMatDlg::OnBnClickedButtongetline()
{
	UpdateData(TRUE);
	C.getLine(A, m_edit_getrl-1);
	m_edit_single.SetWindowTextW(C.out());
	memset(C.arr, 0, sizeof(C.arr));
}