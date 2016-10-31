#pragma once

#include <utility>
#include <vector>
#include "ApplicationDlg.h"

namespace Utils
{
	std::pair< CString, std::vector<CString> > ParseFiles(LPCTSTR lpstrFile);

	void calcUnitTest(CalcData * pData, int width, INT32 * data, INT32 val, int x, int y);
}