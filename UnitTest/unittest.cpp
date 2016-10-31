#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Application/Utils.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include "../Library/Library.h"

#include <vector>
#include "../Application/ApplicationDlg.h"

namespace UnitTest
{
	TEST_CLASS(ParseFilesUnitTest)
	{
	public:

		TEST_METHOD(ParseFiles_TestOneFile)
		{
			auto result = ParseFiles(L"C:\\directory\\subdirectory\\file.name.ext\0");
			Assert::AreEqual(result.first, L"C:\\directory\\subdirectory\\", L"directory");
			Assert::IsTrue(result.second.size() == 1, L"count of files");
			Assert::AreEqual(result.second[0], L"file.name.ext", "filename");
		}

		TEST_METHOD(ParseFiles_TestMultipleFiles)
		{
			auto result = ParseFiles(L"C:\\directory\\subdirectory\0file1.name.ext\0file2.name.ext\0");
			Assert::AreEqual(result.first, L"C:\\directory\\subdirectory\\", L"directory");
			Assert::IsTrue(result.second.size() == 2, L"count of files");
			Assert::AreEqual(result.second[0], L"file1.name.ext", "filename 1");
			Assert::AreEqual(result.second[1], L"file2.name.ext", "filename 2");
		}
	};

	TEST_CLASS(CalcUnitTest_UnitTest)
	{
	public:

		TEST_METHOD(Test_Histogram)
		{
			Gdiplus::Color color = (255,0,10);
			Gdiplus::Bitmap pBitmap(100, 100);
			for (int x = 0; x < 100; x++)
				for (int y = 0; y < 100; y++)
					pBitmap.SetPixel(x, y, color);

			CalcData *testData = new CalcData;
			unsigned int R, G, B;
			std::vector<unsigned> R;
			std::vector<unsigned> G;
			std::vector<unsigned> B;

			testData->obr = &pBitmap;
			testData->hisA.assign(256, 0);
			testData->hisR.assign(256, 0);
			testData->hisG.assign(256, 0);
			testData->hisB.assign(256, 0);
			testData->m_pWnd = this;
			testData->bCancel = FALSE;

			RECT r = { 0, 0,(LONG)testData->obr->GetWidth(),(LONG)testData->obr->GetHeight() };
			Gdiplus::Rect rect = { r.left, r.top, r.right - r.left, r.bottom - r.top };
			Gdiplus::BitmapData* bmpData = new Gdiplus::BitmapData;
			INT32 * data;
			INT32 val;

			testData->obr->LockBits(&rect, Gdiplus::ImageLockModeRead, PixelFormat32bppARGB, bmpData);
			data = (INT32*)bmpData->Scan0;

			for (int x = 0; x < 100; x++)
				for (int y = 0; y < 100; y++)
					Utils::calcUnitTest(testData, 100, data, val, x, y);

			 R = 100*100;
			 G = 100 * 100;
			 B = 100 * 100;

			Assert::AreEqual(testData->hisR[255], R, L"Red");
			Assert::AreEqual(testData->hisG[0], G, L"Green");
			Assert::AreEqual(testData->hisB[10], B, L"Blue");
		}

	};
}
