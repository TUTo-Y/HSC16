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

////保存
int BAOCUN(char *argv);
////保存界面
int BC();
////结束时
void JS_WIN();
////进程 桌面控制
DWORD __stdcall R_C(LPVOID lp);

void JS_WIN()
{
    FILE* File;
    /*初始化数据*/
    fopen_s(&File, "资源.txt", "r");
    char Path[MAX_PATH];

    for (int i = 0; 1; i++)
    {
        fscanf_s(File, "%[^\n]\n", Path, MAX_PATH);
        SystemParametersInfo(SPI_SETDESKWALLPAPER, 0, Path, SPIF_SENDWININICHANGE | SPIF_UPDATEINIFILE);
        Sleep(2000);
        if (i % 14 == 0)
            rewind(File);
    }
}

