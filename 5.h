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

/***************** ���� *****************/
////��
void flower();
////��
int HuuaDuo(HDC dstDC,HDC srcDC);
void puman(HDC dstDC,HDC srcDC, int chang, int gao);
////����
void GW();
///����
void QingPing();
////Ф���뼰������
void XPW();
/***************** ִ�� *****************/

////��
void flower()
{
	////ԭ���趨
	setorigin(x/2,y/2);//683,384

	IMAGE img;
	loadimage(&img,_T("Image\\hh.gif"));
	HDC dstDC = GetImageHDC();
    HDC srcDC = GetImageHDC(&img);

	HuuaDuo(dstDC,srcDC);///��
	GW();///����
	puman(dstDC,srcDC, x, y);////��
	///����
	QingPing();
	Sleep(100);

	XPW();
}


int HuuaDuo(HDC dstDC,HDC srcDC)////��
{

	double i;
	int x;
	int y;
	int R1=340;
	for(i=30;i<=150;i+=5)
	{
		x=-70+340-R1*cos(i*PI/180);
		y=-80+16-R1*sin(i*PI/180);
		TransparentBlt(dstDC, x, y, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
		FlushBatchDraw();
		Sleep(40);	
	}
	TransparentBlt(dstDC,570,-210, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(40);
	double j;
	int R2=600;
	for(j=-10;j>=-60;j-=3)
	{
		x=(int)-10+R2*cos(j*PI/180);
		y=(int)-300-R2*sin(j*PI/180);
		TransparentBlt(dstDC, x,y, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
		FlushBatchDraw();
		Sleep(40);
	}
	TransparentBlt(dstDC,290,210, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(40);
	TransparentBlt(dstDC,260,225, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(40);
	TransparentBlt(dstDC,230,240, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(40);
	TransparentBlt(dstDC,200,255, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(40);
	TransparentBlt(dstDC,170,270, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(40);
	TransparentBlt(dstDC,140,283, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(40);
	TransparentBlt(dstDC,110,296, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(40);
	TransparentBlt(dstDC,80,306, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(40);
	TransparentBlt(dstDC,50,314, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(40);
	TransparentBlt(dstDC,20,320, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(40);
	TransparentBlt(dstDC,-10,326, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(40);
	TransparentBlt(dstDC,-40,320, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(40);
	TransparentBlt(dstDC,-70,314, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(40);
	TransparentBlt(dstDC,-100,306, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(40);
	TransparentBlt(dstDC,-130,296, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	TransparentBlt(dstDC,-160,283, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(40);
	TransparentBlt(dstDC,-190,270, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(40);
	TransparentBlt(dstDC,-220,255, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(40);
	TransparentBlt(dstDC,-250,240, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(40);
	TransparentBlt(dstDC,-280,225, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(40);
	TransparentBlt(dstDC,-310,210, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(40);

	for(j=-120;j>=-140;j-=3)
	{
		x=-15+R2*cos(j*PI/180);
		y=-310-R2*sin(j*PI/180);
		TransparentBlt(dstDC, x,y, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
		FlushBatchDraw();
		Sleep(40);
	}
	TransparentBlt(dstDC,-480,70, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(40);
	TransparentBlt(dstDC,-506,50, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(40);
	TransparentBlt(dstDC,-530,30, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(40);
	TransparentBlt(dstDC,-550,10, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(40);
	TransparentBlt(dstDC,-565,-10, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(40);
	TransparentBlt(dstDC,-583,-35, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(40);
	TransparentBlt(dstDC,-598,-60, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(40);
	TransparentBlt(dstDC,-608,-85, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(40);
	TransparentBlt(dstDC,-618,-110, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(40);
	TransparentBlt(dstDC,-626,-130, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(40);
	TransparentBlt(dstDC,-634,-150, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(40);
	TransparentBlt(dstDC,-640,-170, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(40);
	TransparentBlt(dstDC,-646,-190, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(40);
	TransparentBlt(dstDC,-644,-210, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
	FlushBatchDraw();
	Sleep(40);
	
	for(i=30;i<=150;i+=5)
	{
		x=-340-R1*cos(i*PI/180);
		y=-80+16-R1*sin(i*PI/180);
		TransparentBlt(dstDC, x, y, 100,100, srcDC, 0, 0, 100, 100, 0x000000);
		FlushBatchDraw();
		Sleep(40);	
	}
	return 0;
}


void puman(HDC dstDC,HDC srcDC, int chang, int gao)
{
	int x,y;
	int i;
	srand((unsigned int) time (NULL));
	for(i=0;i<1500;i++)
	{
		x=rand()%chang-chang/2-50;
		y=rand()%gao-gao/2-50;
		TransparentBlt(dstDC,x,y,100,100,srcDC ,0,0,100,100,0x000000);
		FlushBatchDraw();
		Sleep(5);
	}

	Sleep(1000);
	setbkmode(TRANSPARENT);
	LOGFONT f;
	gettextstyle(&f);
	f.lfHeight=80;
	f.lfWidth=40;
	settextstyle(&f);
	for(i=0; i<20; i++)
	{
		settextcolor(RGB(rand()%255, rand()%255, rand()%255));
		outtextxy(-textwidth("�������")/2, -200, _T("�������")); 
		Sleep(120);
	}
	settextcolor(RGB(0, 255, 255));
	outtextxy(-textwidth("�������")/2, -200, _T("�������"));


	for(i=0; i<20; i++)
	{
		settextcolor(RGB(rand()%255, rand()%255, rand()%255));
		outtextxy(-textwidth("�ȴ�������ȥѰ��")/2, -60, _T("�ȴ�������ȥѰ��"));
		Sleep(120);
	}
	settextcolor(RGB(0, 255, 255));
	outtextxy(-textwidth("�ȴ�������ȥѰ��")/2, -60, _T("�ȴ�������ȥѰ��"));


	for(i=0; i<20; i++)
	{
		settextcolor(RGB(rand()%255, rand()%255, rand()%255));
		outtextxy(-textwidth("�¸���ǰ��!")/2, 80, _T("�¸���ǰ��!"));
		Sleep(120);
	}
	settextcolor(RGB(0, 255, 255));
	outtextxy(-textwidth("�¸���ǰ��!")/2, 80, _T("�¸���ǰ��!"));
	Sleep(2000);
}


void GW()
{
	char str[8][50] = {
			"��һ������,���ǻ�����",
			"��Ҳ��������Щ����",
			"Ҳ��Ϊ����,���������",
			"���������ѹ�",
			"����һ�ݷ���������",
			"��лÿһ����ֿ������",
			"ÿһ�ֶ������ǻ���",
			"��л������",
	};
	IMAGE img6;
	LOGFONT f;
	gettextstyle(&f);                     // ��ȡ��ǰ��������
	getimage(&img6,-150,-120,750,600);
	f.lfHeight = 60;
	f.lfWidth = 30;
	f.lfWeight=1000;
	strcpy_s(f.lfFaceName, LF_FACESIZE,_T("����"));
	setbkmode(TRANSPARENT);

	settextstyle(&f);
	setorigin(0, 0);
	
	for(int str_one_number = 0; str_one_number<8; str_one_number++)
	{
		for(int i=0; i<20; i++)
		{
			settextcolor(RGB(rand()%255, rand()%255, rand()%255));
			outtextxy((x - textwidth(str[str_one_number]))/2, y/8*str_one_number, _T(str[str_one_number]));
			Sleep(100);
		}
#if 1	////��ɫͳһ
		settextcolor(RGB(0, 255, 255));
		outtextxy((x - textwidth(str[str_one_number]))/2, y/8*str_one_number, _T(str[str_one_number]));
#endif
	}

	setorigin(x/2, y/2);
	///////////	///////////	///////////
	Sleep(2000);

}


void QingPing()///����
{
	IMAGE I;
	////��ȡͼƬ
	loadimage(&I, _T("Image\\TC.gif"));
	////���ͼƬ�������ʽ
	setfillstyle(BS_DIBPATTERN, BS_PATTERN, &I);
	Open_1();

	settextcolor(WHITE);
	setfillstyle(BS_SOLID);
	Open_1();
}


void XPW()
{
	IMAGE img(x, y*3);
	char a[15][100]={
		"�����ǵ�����", 
		"�ܿ��ģ�Ҳ������", 
		"16�����",
		"���ܲ�����ȫ����", 
		"��л���ʱ��",
		"ϣ�������ϧ���ʱ��",
		"��һ����ܿ�",
		"�����еĵ��",
		"�������õ�����",
		"������",
		"������һ���༶",
		"��л�ҵ���Ա",
		"��л�ҵ�ͬѧ",
		"лл���!",
		"����:֣����",
	};
	////ԭ���0
	setorigin(0, 0);
	////���������ɫ
	setbkmode(TRANSPARENT);
	////��������
	settextstyle(40, 20, _T("����"));
	settextcolor(RGB(125, 255, 125));
	////ʹ��������ͼ
	BeginBatchDraw();

	int c1 = 1;
	int color_1 = 0;
	for (int j = y; j >= -3 * y; j--)
	{
		if (color_1 + c1 > 255 || color_1 + c1 < 0)
			c1 *= -1;

		color_1 += c1;

		cleardevice();
		for (int i = 0; i < 15; i++)
		{
			settextcolor(RGB(255 - color_1, color_1, 0));
			outtextxy((x - textwidth(a[i])) / 2, (y / 5 * i) + j, a[i]);
		}
		settextcolor(RGB(255 - color_1, color_1, 0));

		settextstyle(100, 50, _T("����"));
		outtextxy((x - textwidth("лл!")) / 2, y * 3 + y / 2 + j, "лл!");

		FlushBatchDraw();
		Sleep(10);
	}
	////����������ͼ
	EndBatchDraw();
	Sleep(2000);

	settextcolor(WHITE);
	setfillstyle(BS_SOLID);
	Open_8();
}