// ConsoleApplication1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "windows.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "LiskApi.h"
typedef void(__stdcall *InitAPI)  (char* nodeurl);
typedef char* (__stdcall *Status)  (void);
InitAPI Foo = 0;
Status Bar = 0;
int main()
{
	HINSTANCE hInst;
	
	hInst = LoadLibrary("E:\\libLiskWin\\Win32\\Release\\libLiskApi.dll");//��̬����Dll  
	if (!hInst) {
		printf("load error!");
	}
	Foo = (InitAPI)GetProcAddress(hInst, "InitAPI");
	Bar = (Status)GetProcAddress(hInst, "Status");
	Foo("http://test01.lisk.asia:7000");
	printf("Bar()=%s", Bar());
	system("pause");
	FreeLibrary(hInst);
	return 0;
}

