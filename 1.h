/*********************************************************
* ���� : ֣���� | �����߰�

  * ����ʱ�� : 2019 - 7 - 6
  * �޸�ʱ�� : 2019 - 7 - 11
  * ���ʱ�� : 2019 - 7 - 13
  
	* ����ժ��ѧϰ����, ����ֹδ��������ͬ��۸ĳ���󷢲�
	
	  * ��ע : ��
***********************************************************/

/**********************************************************
*	����:
*		�������� : VC6.0
*		ͼƬ�ṩ : �������� | �ϼ���
*		���� : 
*			��ͼ : EasyX
*			
***********************************************************/


/******** ͷ�ļ� ********/
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
#define MZ "�ټ���һ"
/////////////////////////////////////
//ȫ�ֱ���
/////////////////////////////////////

//IMAGE jpg[_J_];

const int x = GetSystemMetrics(SM_CXSCREEN), y = GetSystemMetrics(SM_CYSCREEN);
#if 0
struct _JPG_1
{
	int x;		////ͼƬ��x
	int y;		////ͼƬ��y
	char IP[_MAX_PATH];////ͼƬ��name
}JPG[_J_] = {0};
struct _JC_
{
	HANDLE h;
}JC = {0};

HWND H;////��ͼ����
#endif
/********** ���� **********/
////��ʼ����ͼ����
void HJ_CSH();
////ȥ�߿�
HWND Bian(HWND H);
void TransparentWindow(HWND hwnd, COLORREF crkcolor, BYTE bAlpha, DWORD dwFlags);
/********** ִ�� **********/
////��ʼ����ͼ����
void HJ_CSH()
{
	srand((int)time(NULL));
	////�����ʼ��
	////����1
	SetWindowPos(Bian(H = initgraph(x, y, NOCLOSE | NOMINIMIZE)), HWND_TOPMOST, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOACTIVATE);// | SWP_NOMOVE
	////����2
	//SetWindowPos(Bian(H = initgraph(x, y, NOCLOSE | NOMINIMIZE)),HWND_DESKTOP, 0, 0, 0, 0, SWP_NOSIZE);

	setorigin(0, 0);
	////���Ʊ�����ɫ
	setbkcolor(WHITE);
	cleardevice();
	////���ݱ�����ɫ͸��
	TransparentWindow(H, WHITE, 100, 0x1);
}


////ȥ�߿�
HWND Bian(HWND H)
{
	long style = GetWindowLong(H, GWL_STYLE);
	style &= ~WS_CAPTION;
	SetWindowLong(H, GWL_STYLE, style);
	return H;
}

////����͸��
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

