//---------------------------------------------------------------------------
#include <vcl.h>
#include <iostream.h>
#include <fstream.h>

#pragma hdrstop

#include "uMyWinFunc.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
AnsiString MyMac()
{
  ifstream infile;
  bool blRead = true;
  string strMac;

  system("ipconfig /all > mac.txt");
  infile.open("mac.txt");
  while(infile && blRead) // read the file line by line
  {
    infile>>strMac;
    if(strMac.size() == 17) // XX-XX-XX-XX-XX-XX
    {
      // �p�G �D���W�� �Ψ䥦��T ��n17�Ӧr���ܡA�i��|�X��
      blRead=false;
    }
  }
  infile.close();

  if(blRead)
    strMac = ""; // �S�������d

  remove("mac.txt");
  return strMac.c_str();
}
//---------------------------------------------------------------------------
AnsiString GetAppVer()
{
  String strVer;
	DWORD dwVerInfoSize = 0;
	AnsiString szFile = Application->ExeName;
	dwVerInfoSize = GetFileVersionInfoSize(szFile.c_str(), &dwVerInfoSize);
	BYTE *bVerInfoBuf = new BYTE[dwVerInfoSize];
	if (GetFileVersionInfo(szFile.c_str(), 0, dwVerInfoSize, bVerInfoBuf))
	{
		VS_FIXEDFILEINFO *vsInfo;
		UINT vsInfoSize;
		if (VerQueryValue(bVerInfoBuf, "\\", (void**)&vsInfo, &vsInfoSize))
		{
			int iFileVerMajor   = HIWORD(vsInfo->dwFileVersionMS);
			int iFileVerMinor   = LOWORD(vsInfo->dwFileVersionMS);
			int iFileVerRelease = HIWORD(vsInfo->dwFileVersionLS);
			int iFileVerBuild   = LOWORD(vsInfo->dwFileVersionLS);

			strVer = IntToStr(iFileVerMajor) + "." + IntToStr(iFileVerMinor) +
			"." + IntToStr(iFileVerRelease) + "." + IntToStr(iFileVerBuild);
		}
	}

	delete bVerInfoBuf;
  return strVer;
}
//---------------------------------------------------------------------------
