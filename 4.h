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



/***************** 函数 *****************/
////形状绘图播放
void TP_1();
////全屏绘图
void TP_2();
////随机图片
void TP_3();
/***************** 执行 *****************/
////形状绘图播放
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


////形状绘图播放
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


////随机图片
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





