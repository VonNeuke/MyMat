
// MyMatDlg.h : ͷ�ļ�
#pragma once
#include "afxwin.h"
#include "ARRAY.h"
// CMyMatDlg �Ի���
class CMyMatDlg : public CDialogEx
{
// ����
public:
	CMyMatDlg(CWnd* pParent = NULL);	// ��׼���캯��
// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MYMAT_DIALOG };
#endif
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��
// ʵ��
protected:
	HICON m_hIcon;
	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonadd();
	afx_msg void OnBnClickedButtonsub();
	afx_msg void OnBnClickedButtonmutiply();
	afx_msg void OnBnClickedButtontrans();
	afx_msg void OnBnClickedButtoninv();
	afx_msg void OnBnClickedButtonA();
	afx_msg void OnBnClickedButtonB();
	afx_msg void OnBnClickedButtoninput();
	int m_edit_row;
	int m_edit_col;
	double m_edit_data;
	CEdit m_edit_a;
	CEdit m_edit_b;
	CEdit m_edit_single;
	CEdit m_edit_double;
	int flg;
	int flag;
	ARRAY A, B, C, D;
	int m_edit_x;
	int m_edit_y;
	double m_edit_value;
	afx_msg void OnBnClickedButtongetpixel();
	afx_msg void OnBnClickedButtonsetpixel();
	int m_edit_getrl;
	afx_msg void OnBnClickedButtongetrow();
	afx_msg void OnBnClickedButtongetline();
};
