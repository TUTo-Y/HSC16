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
int Open(int i, int j);////i��ʾ��ʽ,j��ʾ��ǰ_J_

void Open_1();

void Open_2();

void Open_3();

void Open_4();

void Open_5();

void Open_6();

void Open_7();

void Open_8();
		
void Open_9();

void Open_10();

void Open_11();

void Open_12();

void Open_13();

void Open_14();
/***************** ִ�� *****************/

////i��ʾ��ʽ,a��ʾ��Դ�ļ�,j��ʾ��ǰ_J_
int Open(int i, int j)
{
	////ͼƬ
	IMAGE I;
	////���ƴ�С
	int x = JPG[j].x,
		y = JPG[j].y;
	while (x > 900 || y > 900)
	{
		x /= 2;
		y /= 2;
	}
	while (x < 200 || y < 200)
	{
		x *= 2;
		y *= 2;
	}
	////�Ըı�Ĵ�С��ȡͼƬ
	loadimage(&I, JPG[j].IP, x, y, true);
	////���ͼƬ�������ʽ
	setfillstyle(BS_DIBPATTERN, BS_PATTERN, &I);
	////������ʽѡ��
	switch (i)
	{
	case 1:
		Open_1();
		break;
	case 2:
		Open_2();
		break;
	case 3:
		Open_3();
		break;
	case 4:
		Open_4();
		break;
	case 5:
		Open_5();
		break;
	case 6:
		Open_6();
		break;
	case 7:
		Open_7();
		break;
	case 8:
		Open_8();
		break;
	case 9:
		Open_9();
		break;
	case 10:
		Open_10();
		break;
	case 11:
		Open_11();
		break;
	case 12:
		Open_12();
		break;
	case 13:
		Open_13();
		break;
	case 14:
		Open_14();
		break;
	default:
		return 1;
		break;
	}
	return 0;
}


void Open_1()
{
	int i;
	int j;
	setorigin(0, 0);
	for(i = y/2, j = y/2; i >= 0, j <= y; i--, j++)
	{
		int pts_1[] = {x/2, y/2,  0, y/2,  0, i};
		int pts_2[] = {x/2, y/2,  x, y/2,  x, j};
		solidpolygon((POINT*)pts_1, 3);
		solidpolygon((POINT*)pts_2, 3);
		if(i%3 == 0)
			Sleep(1);
	}

	for(i = 0, j = x; i <= x, j >= 0; i++, j--)
	{
		int pts_1[] = {x/2, y/2,  0, 0,  i, 0};
		int pts_2[] = {x/2, y/2,  x, y,  j, y};
		solidpolygon((POINT*)pts_1, 3);
		solidpolygon((POINT*)pts_2, 3);
		if(i%3 == 0)
			Sleep(1);
	}

	for(i = 0, j = y; i <= y/2, j >= y/2; i++, j--)
	{
		int pts_1[] = {x/2, y/2,  x, 0,  x, i};
		int pts_2[] = {x/2, y/2,  0, y,  0, j};
		solidpolygon((POINT*)pts_1, 3);
		solidpolygon((POINT*)pts_2, 3);
		if(i%3 == 0)
			Sleep(1);
	}
}

void Open_2()
{
	////����ԭ�㲻������Ļ
	//setorigin(rand()%x-jpg.getwidth()/2, rand()%y-jpg.getheight()/2);
	setorigin(0, 0);

	for(int i = 0; x>y ? i<=x/2 : i<=y/2; i++)
	{
		solidrectangle(0, 0, i, i);
		solidrectangle(x - i, 0, x, i);
		solidrectangle(0, y - i, i, y);
		solidrectangle(x - i, y - i, x, y);
		Sleep(1);
	}
}


void Open_3()
{
	////����ԭ�㲻������Ļ
	//setorigin(rand()%x-jpg.getwidth()/2, rand()%y-jpg.getheight()/2);
	setorigin(0, 0);
	int i;
	for(i=0; i<=x/2; i++)////���Ͻǵ�������
	{
		int pts[] = {x/2, y/2, x/2, 0, x/2 + i, 0};
		solidpolygon((POINT*)pts, 3);
		if(i%4 == 0)
			Sleep(1);
	}
	
	for(i=0; i<=y; i++)////�ұߵ�������
	{
		int pts[] = {x/2, y/2, x, 0, x, i};
		solidpolygon((POINT*)pts, 3);
		if(i%4 == 0)
			Sleep(1);
	}
	
	for(i=0; i<=x; i++)////�±ߵ�������
	{
		int pts[] = {x/2, y/2, x, y, x - i, y};
		solidpolygon((POINT*)pts, 3);
		if(i%4 == 0)
			Sleep(1);
	}
	
	for(i=0; i<=y; i++)////��ߵ�������
	{
		int pts[] = {x/2, y/2, 0, y, 0, y - i};
		solidpolygon((POINT*)pts, 3);
		if(i%4 == 0)
			Sleep(1);
	}

	for(i=0; i<=x/2; i++)////���Ͻǵ�������
	{
		int pts[] = {x/2, y/2, 0, 0, i, 0};
		solidpolygon((POINT*)pts, 3);
		if(i%4 == 0)
			Sleep(1);
	}
}


void Open_4()
{
	////����ԭ�㲻������Ļ
	//setorigin(rand()%x-jpg.getwidth()/2, rand()%y-jpg.getheight()/2);
	setorigin(0, 0);

	for(int i=0; i<(int)sqrt((x/2)*(x/2)+(y/2)*(y/2))+10; i++)
	{
		solidcircle((int)x/2, (int)y/2, i);
		Sleep(1);
	}
}


void Open_5()
{
	////����ԭ�㲻������Ļ
	//setorigin(rand()%x-jpg.getwidth()/2, rand()%y-jpg.getheight()/2);
	setorigin(0, 0);

	for(int i = 0; x>y? i <= x/2: i <= y/2; i++)
	{
		int pts[4][6] = {
			{x/2 - i, y/2, x/2, y/2 - i, x/2, y/2 + i},
			{x/2, y/2 - i, x/2 + i, y/2, x/2 - i, y/2},
			{x/2 + i, y/2, x/2, y/2 - i, x/2, y/2+ i},
			{x/2, y/2 + i, x/2 + i, y/2, x/2 - i, y/2},
		};
		for(int j = 0; j<4; j++)
			solidpolygon((POINT*)pts[j], 3);
		Sleep(1);
	}
}


void Open_6()
{
	///ԭ��
	setorigin(0, 0);

	for(int i=0; i<(int)sqrt(x*x+y*y)+10; i++)
	{
		solidcircle(x, y, i);
		Sleep(1);
	}
}


void Open_7()
{
	///ԭ��
	setorigin(0, 0);

	for(int i = 0 ;x>y? i<y/2: i<x/2; i++)
	{
		solidrectangle(0, 0, x, i);
		solidrectangle(0, y - i, x, y);
		solidrectangle(0, 0, i, y);
		solidrectangle(x - i, 0, x, y);

		Sleep(1);
	}
}


void Open_8()
{
	////����ԭ�㲻������Ļ
	//setorigin(rand()%x-jpg.getwidth()/2, rand()%y-jpg.getheight()/2);
	setorigin(0, 0);

	for(int j = 0; j <= y/2; j++)
	{
		solidrectangle( 0, y/2 - j, x, y/2 + j);
		Sleep(1);
	}
}


void Open_9()
{
	////����ԭ�㲻������Ļ
	//setorigin(rand()%x-jpg.getwidth()/2, rand()%y-jpg.getheight()/2);
	setorigin(0, 0);
	int o = x - y;
	
	for(int i = o, j = 0; i <= (x - o)/2 || j <= y/2; i++, j++)
	{
		solidrectangle( x/2 - i, y/2 - j, x/2 + i, y/2 + j);
		Sleep(1);
	}
}


void Open_10()
{
	////����ԭ�㲻������Ļ
	//setorigin(rand()%x-jpg.getwidth()/2, rand()%y-jpg.getheight()/2);
	setorigin(0, 0);
	
	for(int i = 0; x>y? i <= x/2: i <= y/2; i++)
	{
		int pts[4][6] = {
			{0, 0, 0, y, i, y/2},
			{0, 0, x, 0, x/2, i},
			{x, y, x, 0, x - i, y/2},
			{x, y, 0, y, x/2, y-i},
		};
		
		for(int j = 0; j<4; j++)
			solidpolygon((POINT*)pts[j], 3);

		Sleep(1);
	}
}


void Open_11()
{
	////����ԭ�㲻������Ļ
	//setorigin(rand()%x-jpg.getwidth()/2, rand()%y-jpg.getheight()/2);
	setorigin(0, 0);

	BeginBatchDraw();
	for(int i = 0; i < 150; i++)
	{
		for(int Y = 0; Y <= y; Y+=150)
			solidrectangle(0, Y, x, Y+i);
		FlushBatchDraw();
		Sleep(1);
	}
	EndBatchDraw();
}


void Open_12()
{
	////����ԭ�㲻������Ļ
	//setorigin(rand()%x-jpg.getwidth()/2, rand()%y-jpg.getheight()/2);
	setorigin(0, 0);
	for(int i = 0; i <= y; i++)
	{
		int pts[2][6] = {
			{0, y, x, y, x, y - i},
			{x, 0, 0, 0, 0, i},
		};
		for(int j = 0; j<2; j++)
			solidpolygon((POINT*)pts[j], 3);

		Sleep(1);
	}
}


void Open_13()
{
	////����ԭ�㲻������Ļ
	//setorigin(rand()%x-jpg.getwidth()/2, rand()%y-jpg.getheight()/2);
	setorigin(0, 0);
	int i = 0;
	for( i = 0; x>y? i <= x/2 : i <= y/2 ; i++)
	{
		int pts[4][6] = {
			{x/2, y/2, 0, y/2, 0, y/2 - i},
			{x/2, y/2, x/2, 0, x/2 + i, 0},
			{x/2, y/2, x, y/2, x, y/2 + i},
			{x/2, y/2, x/2, y, x/2 - i, y}
		};
		for(int j = 0; j<4; j++)
			solidpolygon((POINT*)pts[j], 3);
		if(i!=0 && i%2==0)
			Sleep(1);
	}
	
	for(i = 0; x>y? i <= x/2 : i <= y/2 ; i++)
	{
		int pts[4][6] = {
			{x/2, y/2, 0, 0, i, 0},
			{x/2, y/2, x, 0, x, i},
			{x/2, y/2, x, y, x-i, y},
			{x/2, y/2, 0, y, 0, y-i}
		};
		for(int j = 0; j<4; j++)
			solidpolygon((POINT*)pts[j], 3);
		if(i!=0 && i%2==0)
			Sleep(1);
	}
}


void Open_14()
{
	////����ԭ�㲻������Ļ
	//setorigin(rand()%x-jpg.getwidth()/2, rand()%y-jpg.getheight()/2);
	setorigin(0, 0);

	for(int i = 0;x>y? i <= x/2+1: i <= y/2+1; i++)
	{
		int pts[8][6] = {
			{x/2, y/2, 0, y/2, 0, y/2 - i},
			{x/2, y/2, 0, 0, i, 0},
			{x/2, y/2, x/2, 0, x/2 + i, 0},
			{x/2, y/2, x, 0, x, i},
			{x/2, y/2, x, y/2, x, y/2 + i},
			{x/2, y/2, x, y, x - i, y},
			{x/2, y/2, x/2, y, x/2 - i, y},
			{x/2, y/2, 0, y, 0, y - i},
		};
		for(int j=0; j<8; j++)
			solidpolygon((POINT*)pts[j], 3);
		Sleep(1);
	}
}

