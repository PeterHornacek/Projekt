#include "stdafx.h"
#include "Utils.h"

namespace Utils
{
	//	parse file names from file name string in OPENFILENAME struct
	//	returns pair of directory and vector of filenames
	//

	

	std::pair< CString, std::vector<CString> > ParseFiles(LPCTSTR lpstrFile)
	{
		CString cs = lpstrFile;

		// skip directory name
		while (*lpstrFile) ++lpstrFile;

		if (*(++lpstrFile))
		{
			CString csDirectory;
			std::vector<CString> names;

			csDirectory = cs + _T("\\");
			// iterate filenames
			for (; *lpstrFile; ++lpstrFile)
			{
				names.push_back(lpstrFile);

				while (*lpstrFile) ++lpstrFile;
			}

			return std::make_pair(csDirectory, names);
		}
		else
		{	// only one filename
			CString csName, csExt;
			_tsplitpath_s(cs, nullptr, 0, nullptr, 0, csName.GetBuffer(_MAX_FNAME), _MAX_FNAME, csExt.GetBuffer(_MAX_EXT), _MAX_EXT);
			csName.ReleaseBuffer();
			csExt.ReleaseBuffer();

			return std::make_pair(cs.Left(cs.GetLength() - csName.GetLength() - csExt.GetLength()), std::vector<CString>({ csName + csExt }));
		}
	}

	/*void calcUnitTest(CalcData * pData, int width, INT32 * data, INT32 val, int x, int y)
	{
		int A, R, G, B;

		if (pData->bCancel == true)
			return;

		val = *(data + y * width + x);
		R = (val >> 16) & 0xFF;
		G = (val >> 8) & 0xFF;
		B = val & 0xFF;
		A = (R + G + B) / 3;

		pData->hisA[A] = pData->hisA[A] + 1;
		pData->hisR[R] = pData->hisR[R] + 1;
		pData->hisG[G] = pData->hisG[G] + 1;
		pData->hisB[B] = pData->hisB[B] + 1;
	}*/
}
