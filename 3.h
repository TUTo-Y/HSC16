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
int OpenLocal(int i, int j);////i��ʾ��ʽ,j��ʾ��ǰ_J_

void OpenLocal_1(IMAGE jpg);

void OpenLocal_2(IMAGE jpg);

void OpenLocal_3(IMAGE jpg);

void OpenLocal_4(IMAGE jpg);

void OpenLocal_5(IMAGE jpg);

void OpenLocal_6(IMAGE jpg);

void OpenLocal_7(IMAGE jpg);

void OpenLocal_8(IMAGE jpg);
		
void OpenLocal_9(IMAGE jpg);
		
void OpenLocal_10(IMAGE jpg);
		
void OpenLocal_11(IMAGE jpg);
/***************** ִ�� *****************/

////i��ʾ��ʽ,a��ʾ��Դ�ļ�,j��ʾ��ǰ_J_
int OpenLocal(int i, int j)
{
	////ͼƬ
	IMAGE I;
	////���ƴ�С
	int x = JPG[j].x,
		y = JPG[j].y;
	while(x>500 || y>500)
	{
		x/=2;
		y/=2;
	}
	while(x<250 || y<250)
	{
		x*=2;
		y*=2;
	}
	////�Ըı�Ĵ�С��ȡͼƬ
	loadimage(&I, _T(JPG[j].IP), x, y, true);
	////���ͼƬ�������ʽ
	setfillstyle(BS_DIBPATTERN, BS_PATTERN, &I);
	////������ʽѡ��
	switch(i)
	{
	case 1:
		OpenLocal_1(I);
		break;
	case 2:
		OpenLocal_2(I);
		break;
	case 3:
		OpenLocal_3(I);
		break;
	case 4:
		OpenLocal_4(I);
		break;
	case 5:
		OpenLocal_5(I);
		break;
	case 6:
		OpenLocal_6(I);
		break;
	case 7:
		OpenLocal_7(I);
		break;
	case 8:
		OpenLocal_8(I);
		break;
	case 9:
		OpenLocal_9(I);
		break;
	case 10:
		OpenLocal_10(I);
		break;
	case 11:
		OpenLocal_11(I);
		break;
	default:
		return 1;
		break;
	}
	return 0;
}


void OpenLocal_1(IMAGE jpg)
{
	////����ԭ�㲻������Ļ
	setorigin(rand()%x-jpg.getwidth()/2, rand()%y-jpg.getheight()/2);
	//setorigin((x-500)/2, (y-500)/2);
	
	for(int i = 0; i <= 500; i++)
	{
		int pts[2][6] = {
			{0, 500, 500, 500, 500, 500 - i},
			{500, 0, 0, 0, 0, i},
		};
		for(int j = 0; j<2; j++)
			solidpolygon((POINT*)pts[j], 3);

		Sleep(1);
	}

}

void OpenLocal_2(IMAGE jpg)
{
	////����ԭ�㲻������Ļ
	setorigin(rand()%x-jpg.getwidth()/2, rand()%y-jpg.getheight()/2);
	//setorigin((x-500)/2, (y-500)/2);
	int i;
	for(i = 0; i <= 250; i++)
	{
		int pts[4][6] = {
			{250, 250, 0, 250, 0, 250 - i},
			{250, 250, 250, 0, 250 + i, 0},
			{250, 250, 500, 250, 500, 250 + i},
			{250, 250, 250, 500, 250 - i, 500}
		};
		for(int j = 0; j<4; j++)
			solidpolygon((POINT*)pts[j], 3);

		Sleep(1);
	}

	for(i = 0; i <= 250; i++)
	{
		int pts[4][6] = {
			{250, 250, 0, 0, i, 0},
			{250, 250, 500, 0, 500, i},
			{250, 250, 500, 500, 500-i, 500},
			{250, 250, 0, 500, 0, 500-i}
		};
		for(int j = 0; j<4; j++)
			solidpolygon((POINT*)pts[j], 3);

		Sleep(1);
	}
}

void OpenLocal_3(IMAGE jpg)
{
	////����ԭ�㲻������Ļ
	setorigin(rand()%x-jpg.getwidth()/2, rand()%y-jpg.getheight()/2);
	//setorigin((x-500)/2, (y-500)/2);

	for(int i = 0; i <= 250; i++)
	{
		int pts[8][6] = {
			{250, 250, 0, 250, 0, 250 - i},
			{250, 250, 0, 0, i, 0},
			{250, 250, 250, 0, 250 + i, 0},
			{250, 250, 500, 0, 500, i},
			{250, 250, 500, 250, 500, 250 + i},
			{250, 250, 500, 500, 500 - i, 500},
			{250, 250, 250, 500, 250 - i, 500},
			{250, 250, 0, 500, 0, 500 - i},
		};
		for(int j=0; j<8; j++)
			solidpolygon((POINT*)pts[j], 3);
		Sleep(1);
	}
}

void OpenLocal_4(IMAGE jpg)
{
	////����ԭ�㲻������Ļ
	setorigin(rand()%x-jpg.getwidth()/2, rand()%y-jpg.getheight()/2);
	//setorigin((x-500)/2, (y-500)/2);

	for(int i = 0 ;i <= 250; i++)
	{
		solidcircle(250, 250, i);
		Sleep(1);
	}
}


void OpenLocal_5(IMAGE jpg)
{
	////����ԭ�㲻������Ļ
	setorigin(rand()%x-jpg.getwidth()/2, rand()%y-jpg.getheight()/2);
	//setorigin((x-500)/2, (y-500)/2);

	for(int i = 0; i<=250; i++)
	{
		int pts[4][6] = {
			{250 - i, 250, 250, 250 - i, 250, 250 + i},
			{250, 250 - i, 250 + i, 250, 250 - i, 250},
			{250 + i, 250, 250, 250 - i, 250, 250 + i},
			{250, 250 + i, 250 + i, 250, 250 - i, 250},
		};
		for(int j = 0; j<4; j++)
			solidpolygon((POINT*)pts[j], 3);
		Sleep(1);
	}
}


void OpenLocal_6(IMAGE jpg)
{
	////����ԭ�㲻������Ļ
	setorigin(rand()%x-jpg.getwidth()/2, rand()%y-jpg.getheight()/2);
	//setorigin((x-500)/2, (y-500)/2);

	for(int i = 0, j = 0; i <= 250 && j <= 250; i++, j++)
	{
		solidrectangle(0, 0, 500, j);
		solidrectangle(0, 500-j, 500, 500);
		solidrectangle(0, 0, i, 500);
		solidrectangle(500 - i, 0, 500, 500);

		Sleep(1);
	}
}


void OpenLocal_7(IMAGE jpg)
{
	////
	setorigin(rand()%x-jpg.getwidth()/2, rand()%y-jpg.getheight()/2);
	//setorigin((x-500)/2, (y-500)/2);

	for(int i = 0; i <= 250; i++)
	{
		solidrectangle( 250 - i, 250 - i, 250 + i, 250 + i);
		Sleep(1);
	}
}


void OpenLocal_8(IMAGE jpg)
{
	////����ԭ�㲻������Ļ
	setorigin(rand()%x-jpg.getwidth()/2, rand()%y-jpg.getheight()/2);
	//setorigin((x-500)/2, (y-500)/2);
	
	for(int i = 0; i <= 250; i++)
	{
		int pts[4][6] = {
			{0, 0, 0, 500, i, 250},
			{0, 0, 500, 0, 250, i},
			{500, 500, 500, 0, 500 - i, 250},
			{500, 500, 0, 500, 250, 500 - i},
		};
		
		for(int j = 0; j<4; j++)
			solidpolygon((POINT*)pts[j], 3);

		Sleep(1);
	}
}


void OpenLocal_9(IMAGE jpg)
{
	////����ԭ�㲻������Ļ
	setorigin(rand()%x-jpg.getwidth()/2, rand()%y-jpg.getheight()/2);
	//setorigin((x-500)/2, (y-500)/2);

	BeginBatchDraw();
	for(int i = 0; i < 15; i++)
	{
		for(int Y = 0; Y <= 500; Y+=15)
			solidrectangle(0, Y, 500, Y+i);
		FlushBatchDraw();
		Sleep(1);
	}
	EndBatchDraw();
}


void OpenLocal_10(IMAGE jpg)
{
	////����ԭ�㲻������Ļ
	setorigin(rand()%x-jpg.getwidth()/2, rand()%y-jpg.getheight()/2);
	
	for(int i = 0; i<=250; i++)
	{
		solidrectangle(0, 0, i, i);
		solidrectangle(500 - i, 0, 500, i);
		solidrectangle(0, 500 - i, i, 500);
		solidrectangle(500 - i, 500 - i, 500, 500);
		Sleep(1);
	}
}


void OpenLocal_11(IMAGE jpg)
{
	////����ԭ�㲻������Ļ
	setorigin(rand()%x-jpg.getwidth()/2, rand()%y-jpg.getheight()/2);
	int i;
	for( i=0; i<=250; i++)////���Ͻǵ�������
	{
		int pts[] = {250, 250, 250, 0, 250 + i, 0};
		solidpolygon((POINT*)pts, 3);
		Sleep(1);
	}
		
	for(i=0; i<=500; i++)////�ұߵ�������
	{
		int pts[] = {250, 250, 500, 0, 500, i};
		solidpolygon((POINT*)pts, 3);
		Sleep(1);
	}

	for(i=0; i<=500; i++)////�±ߵ�������
	{
		int pts[] = {250, 250, 500, 500, 500 - i, 500};
		solidpolygon((POINT*)pts, 3);
		Sleep(1);
	}

	for(i=0; i<=500; i++)////��ߵ�������
	{
		int pts[] = {250, 250, 0, 500, 0, 500 - i};
		solidpolygon((POINT*)pts, 3);
		Sleep(1);
	}

	for(i=0; i<=250; i++)////���Ͻǵ�������
	{
		int pts[] = {250, 250, 0, 0, i, 0};
		solidpolygon((POINT*)pts, 3);
		Sleep(1);
	}
}


