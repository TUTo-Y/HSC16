/*********************************************************
* 作者 : 郑德泓 | 初二七班

  * 创建时间 : 2019 - 7 - 6
  * 修改时间 : 2019 - 7 - 11
  * 完成时间 : 2019 - 7 - 13
  
	* 可以摘抄学习代码, 但禁止未经过作者同意篡改程序后发布
	
	  * 备注 : 略
***********************************************************/

/**********************************************************
*	环境:
*		开发环境 : VC6.0
*		图片提供 : 赖星月阳 | 孟佳怡
*		其他 : 
*			绘图 : EasyX
*			
***********************************************************/


/******** 头文件 ********/
#include <windows.h>
#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include<commctrl.h>
#include<TLHELP32.H>
#include<Commdlg.h>
#include<Shlobj.h>
#include <graphics.h>
#include <conio.h>
#include <direct.h>
#include <mmsystem.h>
#include <stdlib.h>
#include "main.h"
#pragma comment( lib, "MSIMG32.LIB")
#define WS_EX_LAYERED 0x00080000
#define PI 3.14159265357

#define	_J_ 14
#define MZ "再见高一"
/////////////////////////////////////
//全局变量
/////////////////////////////////////

//IMAGE jpg[_J_];

const int x = GetSystemMetrics(SM_CXSCREEN), y = GetSystemMetrics(SM_CYSCREEN);
#if 0
struct _JPG_1
{
	int x;		////图片的x
	int y;		////图片的y
	char IP[_MAX_PATH];////图片的name
}JPG[_J_] = {0};
struct _JC_
{
	HANDLE h;
}JC = {0};

HWND H;////绘图窗口
#endif
/********** 函数 **********/
////初始化绘图界面
void HJ_CSH();
////去边框
HWND Bian(HWND H);
void TransparentWindow(HWND hwnd, COLORREF crkcolor, BYTE bAlpha, DWORD dwFlags);
/********** 执行 **********/
////初始化绘图界面
void HJ_CSH()
{
	srand((int)time(NULL));
	////界面初始化
	////方案1
	SetWindowPos(Bian(H = initgraph(x, y, NOCLOSE | NOMINIMIZE)), HWND_TOPMOST, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOACTIVATE);// | SWP_NOMOVE
	////方案2
	//SetWindowPos(Bian(H = initgraph(x, y, NOCLOSE | NOMINIMIZE)),HWND_DESKTOP, 0, 0, 0, 0, SWP_NOSIZE);

	setorigin(0, 0);
	////控制背景颜色
	setbkcolor(WHITE);
	cleardevice();
	////根据背景颜色透明
	TransparentWindow(H, WHITE, 100, 0x1);
}


////去边框
HWND Bian(HWND H)
{
	long style = GetWindowLong(H, GWL_STYLE);
	style &= ~WS_CAPTION;
	SetWindowLong(H, GWL_STYLE, style);
	return H;
}

////窗口透明
void TransparentWindow(HWND hwnd, COLORREF crkcolor, BYTE bAlpha, DWORD dwFlags)
{
	HINSTANCE hm = GetModuleHandle(_T("USER32.DLL"));
	if (!hm)
		return;
	FARPROC fun = GetProcAddress(hm, "SetLayeredWindowAttributes");
	bool (WINAPI * SetLayeredWindowAttributes)(HWND, COLORREF, BYTE, DWORD) = (bool (WINAPI*) (HWND, COLORREF, BYTE, DWORD))fun;

	if (SetLayeredWindowAttributes)
	{
		LONG ret = GetWindowLong(hwnd, GWL_EXSTYLE);
		ret |= WS_EX_LAYERED;
		SetWindowLong(hwnd, GWL_EXSTYLE, ret);
		SetLayeredWindowAttributes(hwnd, crkcolor, bAlpha, dwFlags);
	}
	FreeLibrary(hm);
}

