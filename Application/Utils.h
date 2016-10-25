#pragma once

#include <utility>
#include <vector>

namespace Utils
{
	std::pair< CString, std::vector<CString> > ParseFiles(LPCTSTR lpstrFile);

	/*typedef struct
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

	void calcUnitTest(CalcData * pData, int width, INT32 * data, INT32 val, int x, int y);*/
}