// MyMatDlg.cpp : 实现文件
#include "stdafx.h"
#include "MyMat.h"
#include "MyMatDlg.h"
#include "afxdialogex.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
// CMyMatDlg 对话框
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
	//界面组件的变量设置
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
	//界面组件的消息处理程序设置
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
// CMyMatDlg 消息处理程序
BOOL CMyMatDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标
	return TRUE;
}
void CMyMatDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文
		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);
		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;
		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}
//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMyMatDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
//自定义的消息处理程序
//包括矩阵的运算、矩阵的构造、矩阵的元素的设置
//矩阵元素的提取、矩阵行列信息的提取等等
void CMyMatDlg::OnBnClickedButtonadd()
{
	flg = 0;
	if (A.Row != B.Row || A.Line != B.Line)   //判段是否符合运算规则
		m_edit_double.SetWindowTextW(_T("输入的矩阵不能相加！"));
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
	if (A.Row != B.Row || A.Line != B.Line)   //判段是否符合运算规则
		m_edit_double.SetWindowTextW(_T("输入的矩阵不能相减！"));
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
	if (A.Line != B.Row)//判断矩阵是否符合运算规则
		m_edit_double.SetWindowTextW(_T("输入的矩阵不能相乘！"));
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
		m_edit_single.SetWindowTextW(_T("无法计算逆矩阵！"));
	}
	else
	{
		C.bansui(A);
		double hls = D.hanglieshi(A);
		memset(D.arr, 0, sizeof(D.arr));
		if(hls ==0)
		{
			m_edit_single.SetWindowTextW(_T("矩阵不可逆"));
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