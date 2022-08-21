#ifndef OPENGL_H_
#define OPENGL_H_

/* 标准输入输出库 */
#include <stdio.h>
#include <string.h>
#include <windows.h>

/* GLAD */
#ifndef __glad_h_
#include <GLAD\GLAD.h>
#endif // GLAD

/* GLFW */
#ifndef _glfw3_h_
#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>
#endif // GLFW

/* 着色器程序结构体 */
struct openglShader
{
    /* 着色器程序 */
    unsigned int program;
    /* uniform */
    unsigned int uniform[20];
    /* 日志 */
    char *vlog, /* 顶点着色器日志 */
         *flog, /* 片元着色器日志 */
         *plog; /* 着色器程序日志 */
};


/**
 *  \brief	创建一个着色器
 *
 *  \param	ShaderStr  : 着色器源码字符串
 *  \param	ShaderType : 着色器类型
 *
 *  \return 着色器对象
 */
unsigned int openglCreateShader(const char *ShaderStr, const unsigned int ShaderType);


/**
 *  \brief	创建一个着色器程序
 *
 *  \param	Shader   : 着色器程序结构体
 *  \param	VShader  : 顶点着色器源码字符串
 *  \param	FShader  : 片元着色器源码字符串
 *  \param	VShaderF : 顶点着色器源码文件
 *  \param	FShaderF : 片元着色器源码文件
 *
 *  \return 是否编译成功
 */
unsigned char openglCreateProgram(struct openglShader *Shader, const char *VShader, const char *FShader, const char *VShaderF, const char *FShaderF);

/**
 *  \brief	设置LocationID
 *
 *  \param	Shader	: 着色器结构体
 *  \param	ArrayName		: 数组位置
 *  \param	LocationName	: Uniform名字
 *
 *  \return 是否越界
 */
BOOL openglSetUniform(struct openglShader* Shader, unsigned int ArrayName, ...);



#endif // OPENGL_H_
