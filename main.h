#pragma once
/*OpenGLFW for Windows*/
#define GLFW_EXPOSE_NATIVE_WIN32
/* C */
#include <io.h>
#include <math.h>
#include <time.h>
#include <stdio.h>
#include <direct.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <process.h>
#include <graphics.h>
/* SDL */
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <SDL_image.h>
#pragma comment(lib, "SDL2")
#pragma comment(lib, "SDL2main")
#pragma comment(lib, "SDL2_image")
#pragma comment(lib, "SDL2_mixer")
#pragma comment(lib, "SDL2_ttf")
/* OpenGL */
#include <glm\glm.hpp>
#include <GLAD\glad.h>
#include <GLFW\glfw3.h>
#include <GLFW\glfw3native.h>
#pragma comment(lib, "OpenGL32")
#pragma comment(lib, "OpenGLAD")
#pragma comment(lib, "GLFW3")

#include "opengl.h"

struct _JPG_1
{
	int x;		////图片的x
	int y;		////图片的y
	char IP[_MAX_PATH];////图片的name
};

#ifdef MAIN_C_

unsigned int Texture[14] = {0};
GLFWwindow* Window = NULL;
Mix_Chunk* Chunk = NULL;
struct _JPG_1 JPG[14] = { 0 };
HWND H;////绘图窗口
IMAGE jpg[14];
#else
extern unsigned int Texture[14];
extern GLFWwindow* Window;
extern Mix_Chunk* Chunk;
extern HWND H;////绘图窗口
extern IMAGE jpg[14];
extern struct _JPG_1 JPG[14];
#endif



void Init();
void Quit();

#define SDL_LOAD_SURFACE 0x1
#define SDL_LOAD_MUSIC   0x2
#define SDL_LOAD_CHUNK   0x3
#define SDL_LOAD_TTF     0x4
//从文件读取数据
void* SDL_LoadFromFile(char* Path, size_t Set);


