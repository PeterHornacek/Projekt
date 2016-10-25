
// ApplicationDlg.h : header file
//

#pragma once

#include "LogDlg.h"
#include <GdiPlus.h>
#include <vector>


//definicia struktury CalcData
typedef struct
{
	Gdiplus::Bitmap* obr;
	std::vector<unsigned> hisR;
	std::vector<unsigned> hisG;
	std::vector<unsigned> hisB;
	std::vector<unsigned> hisA;
	CWnd* m_pWnd;
	bool bCancel;
	int pocet;
}CalcData;

typedef struct
{
	std::vector<unsigned> hisR;
	std::vector<unsigned> hisG;
	std::vector<unsigned> hisB;
	std::vector<unsigned> hisA;
	INT32 * pole;
	int startH;
	int koniecH;
	int sirka;
	bool* bCancel;

}Ulozisko;

class CStaticImage : public CStatic
{
public:
	// Overridables (for owner draw only)
	void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct) override;
};

class CStaticHistogram : public CStatic
{
	void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct) override;
};

// CApplicationDlg dialog
class CApplicationDlg : public CDialogEx
{
// Construction
public:
	enum
	{
		WM_DRAW_IMAGE = (WM_USER + 1),
		WM_DRAW_HISTOGRAM
	};

	CApplicationDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_APPLICATION_DIALOG };
#endif

	protected:
	void DoDataExchange(CDataExchange* pDX) override;	// DDX/DDV support

	void OnOK() override {}
	void OnCancel() override {}
	void curveHist(WPARAM wParam, CDC *pDC, std::vector<unsigned> hist, COLORREF color);
	void columnHist(WPARAM wParam, CDC *pDC, std::vector<unsigned> hist, COLORREF color);


// Implementation
protected:
	HICON m_hIcon;

	BOOL m_bShowAlpha = FALSE;
	BOOL m_bShowRed = TRUE;
	BOOL m_bShowGreen = FALSE;
	BOOL m_bShowBlue = FALSE;
	BOOL m_bShowCtype = TRUE;
	BOOL m_bShowCutype = FALSE;
	BOOL m_bShowCpixel = TRUE;
	BOOL m_bShowClockB = FALSE;

	BOOL m_bCheckLuminance = FALSE;
	BOOL m_bCheckRed = TRUE;
	BOOL m_bCheckGreen = FALSE;
	BOOL m_bCheckBlue = FALSE;
	BOOL m_bCheckCtype = TRUE;
	BOOL m_bCheckCutype = FALSE;
	BOOL m_bCheckCpixel = TRUE;
	BOOL m_bCheckClockB = FALSE;

	int m_MT = 2;

	// Generated message map functions
	BOOL OnInitDialog() override;
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	std::vector<unsigned> m_histogramAlpha;
	std::vector<unsigned> m_histogramRed;
	std::vector<unsigned> m_histogramGreen;
	std::vector<unsigned> m_histogramBlue;

	CalcData* m_pCalcData = nullptr;

	afx_msg void OnFileOpen();
	afx_msg void OnUpdateFileOpen(CCmdUI *pCmdUI);
	afx_msg void OnFileClose();
	afx_msg void OnUpdateFileClose(CCmdUI *pCmdUI);
	afx_msg LRESULT OnKickIdle(WPARAM wParam, LPARAM lParam);
	afx_msg void OnClose();
	afx_msg void OnSizing(UINT nSide, LPRECT lpRect);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg LRESULT OnDrawImage(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnDrawHistogram(WPARAM wParam, LPARAM lParam);
	afx_msg void OnDestroy();
	afx_msg LRESULT OnFinish(WPARAM wParam, LPARAM lParam);
protected:
	CListCtrl m_ctrlFileList;
	CStaticImage m_ctrlImage;
	CStaticHistogram m_ctrlHistogram;

	CPoint m_ptFileList;
	CPoint m_ptHistogram;
	CPoint m_ptImage;

	CString m_csDirectory;

	CLogDlg m_ctrlLog;

	Gdiplus::Bitmap * m_pBitmap;
	DWORD m_nMaxThreads;
public:
	afx_msg void OnLvnItemchangedFileList(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnLogOpen();
	afx_msg void OnUpdateLogOpen(CCmdUI *pCmdUI);
	afx_msg void OnLogClear();
	afx_msg void OnUpdateLogClear(CCmdUI *pCmdUI);
	afx_msg void OnHistogramRed();
	afx_msg void OnHistogramGreen();
	afx_msg void OnHistogramBlue();
	afx_msg void OnHistogramLminance();
	afx_msg void OnUpdateHistogramRed(CCmdUI *pCmdUI);
	afx_msg void OnUpdateHistogramGreen(CCmdUI *pCmdUI);
	afx_msg void OnUpdateHistogramBlue(CCmdUI *pCmdUI);
	afx_msg void OnUpdateHistogramLminance(CCmdUI *pCmdUI);
	afx_msg void OnHistogramtypeColumns();
	afx_msg void OnHistogramtypeCurve();
	afx_msg void OnUpdateHistogramtypeColumns(CCmdUI *pCmdUI);
	afx_msg void OnUpdateHistogramtypeCurve(CCmdUI *pCmdUI);
	afx_msg void OnCalculatingPixel();
	afx_msg void OnCalculatingLockbits();
	afx_msg void OnUpdateCalculatingPixel(CCmdUI *pCmdUI);
	afx_msg void OnUpdateCalculatingLockbits(CCmdUI *pCmdUI);
};
