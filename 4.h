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
////��״��ͼ����
void TP_1();
////ȫ����ͼ
void TP_2();
////���ͼƬ
void TP_3();
/***************** ִ�� *****************/
////��״��ͼ����
void TP_1()
{
	for(int i = 1; i < _J_; i++)
	{
		if(i!=0 && i%6 == 0)
		{
			settextcolor(WHITE);
			setfillstyle(BS_SOLID);
			Open_3();
			cleardevice();
		}

		OpenLocal((i-1)%10+1, i);
	}


	settextcolor(WHITE);
	setfillstyle(BS_SOLID);
	Open_11();
}


////��״��ͼ����
void TP_2()
{
	settextcolor(WHITE);
	setfillstyle(BS_SOLID);
	for(int i = 0; i < _J_; i++)
	{
		if(i == _J_-1)
		{
			Open(11, i);
			break;
		}
		Open(i%13+2, i);
	}
	

	settextcolor(WHITE);
	setfillstyle(BS_SOLID);
	Open_11();
}


////���ͼƬ
void TP_3()
{
	setorigin(0, 0);
	//cleardevice();
	for(int i = 0; i<_J_; i++)
	{
		IMAGE Temp;
		while(JPG[i].x>900 || JPG[i].y>900){JPG[i].x/=2;JPG[i].y/=2;}
		while(JPG[i].x<200 || JPG[i].y<200){JPG[i].x*=2;JPG[i].y*=2;}
		setorigin(rand()%x-JPG[i].x/2, rand()%y-JPG[i].y/2);
		loadimage(&Temp, _T(JPG[i].IP), JPG[i].x, JPG[i].y, false);
		putimage(0, 0, &Temp);
		Sleep(800);
	}
	Sleep(100);
	flower();
}





