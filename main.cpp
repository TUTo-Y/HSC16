#define MAIN_C_
#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )
#include "main.h"
#include "Play.h"
int cmain();
int main(int argc, char** argv)
{
    /* 初始化 */
    Init();

    /* Play */
    Play();
    
    cmain();

    /* 退出 */
    Quit();

    return 0;
}

void Init()
{
    char Path[MAX_PATH];
    FILE* File = NULL;
    srand((int)time(NULL));
    /*初始化SDL*/
    {
        //SDL_Init(SDL_INIT_AUDIO);
        Mix_Init(MIX_INIT_FLAC);
    }
    /*初始化OpenGL*/
    {
        glfwInit();
        /*无窗口修饰*/
        glfwWindowHint(GLFW_DECORATED, GLFW_FALSE);
        GLFWmonitor *monitor = glfwGetPrimaryMonitor();
        const GLFWvidmode* mode = glfwGetVideoMode(monitor);
        glfwWindowHint(GLFW_RED_BITS, mode->redBits);
        glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
        glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
        glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);
#       ifdef _DEBUG
        Window = glfwCreateWindow(1024, 768, "", NULL, NULL);
        /*隐藏窗口*/
        H = glfwGetWin32Window(Window);
        MoveWindow(H, 100, 100, 1024, 768, TRUE);
#       else
        Window = glfwCreateWindow(1024, 768, "", monitor, NULL);
#       endif
        /*隐藏窗口*/
        H = glfwGetWin32Window(Window);
        ShowWindow(H, SW_HIDE);

        glfwMakeContextCurrent(Window);
        gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
        glViewport(0, 0, 1024, 768);
        /*设置渲染*/
        glEnable(GL_DEPTH_TEST);
    }
    /*初始化数据*/
    fopen_s(&File, "资源.txt", "r");
    /*读取图片*/
    glGenTextures(14, Texture);
    for (int i = 0; i< 14; i++)
    {
        fscanf_s(File, "%[^\n]\n", Path, MAX_PATH);
        /*Image*/
        loadimage(&jpg[i], Path);
        memcpy_s(JPG[i].IP, sizeof(JPG[i].IP), Path, sizeof(Path));
        /////加载图片大小
        JPG[i].x = jpg[i].getwidth();
        JPG[i].y = jpg[i].getheight();
       
        /*创建Texture*/
        glBindTexture(GL_TEXTURE_2D, Texture[i]);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, JPG[i].x, JPG[i].y, 0, GL_BGRA, GL_UNSIGNED_BYTE, GetImageBuffer(&jpg[i]));
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    fclose(File);

    /*读取音乐*/
    {
#ifndef _DEBUG
        Mix_OpenAudio(44100,AUDIO_S16SYS,2,2048);
        Chunk = (Mix_Chunk*)SDL_LoadFromFile((char*)"Music\\Cry For The Moon-出羽良彰.flac", SDL_LOAD_CHUNK);
#endif
    }
}

void Quit()
{
    /*关闭SDL*/
    //SDL_Quit();

    Mix_HaltChannel(-1);
    Mix_FreeChunk(Chunk);
    Mix_CloseAudio();
    Mix_Quit();
}


//从文件读取数据
void* SDL_LoadFromFile(char* Path, size_t Set)
{
    register	size_t FileSize = 0;
    void* Mem = NULL;
    void* Data = NULL;
    FILE* File = NULL;

    //打开文件
    if (!fopen_s(&File, Path, "rb"))
    {
        //获取文件大小
        fseek(File, 0L, SEEK_END);
        FileSize = ftell(File);
        rewind(File);
        //分配内存大小
        Mem = malloc(FileSize);
        //读取数据
        fread_s(Mem, FileSize, FileSize, 1, File);
        //读取
        Data = (void*)Mix_LoadWAV_RW(SDL_RWFromMem(Mem, FileSize), 1);
        //释放内存
        if (Mem)
            free(Mem);
        //关闭文件
        fclose(File);
    }
    return Data;
}