#define OPENGL_C_
#include "main.h"
#include "opengl.h"
/*
*   \brief 从文件读取数据
*   \param FileName : 文件名
*   \return 文件数据
*/
char* __getfiledata(const char* FileName)
{
    FILE* File = NULL;
    char* Str = NULL;
    unsigned int Long;
    if (!fopen_s(&File, FileName, "r"))
    {
        /* 获取文件大小 */
        fseek(File, 0L, SEEK_END);
        Long = ftell(File);
        rewind(File);
        /* 读取数据 */
        Str = (char*)malloc(Long);
        fread_s(Str, Long, Long, 1, File);
        /* 结束 */
        fclose(File);
    }
    return Str;
}

/**
 *  \brief	创建一个着色器
 *
 *  \param	ShaderStr  : 着色器源码字符串
 *  \param	ShaderType : 着色器类型
 *
 *  \return 着色器对象
 */
unsigned int openglCreateShader(const char* ShaderStr, const unsigned int ShaderType)
{
	register unsigned int Shader;
	/* 创建着色器 */
	Shader = glCreateShader(ShaderType);
	/* 绑定 */
	glShaderSource(Shader, 1, &ShaderStr, 0);
	/* 编译着色器 */
	glCompileShader(Shader);
	/* 返回 */
	return Shader;
}


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
unsigned char openglCreateProgram(struct openglShader* Shader, const char* VShader, const char* FShader, const char* VShaderF, const char* FShaderF)
{
    unsigned int VS = 0,
                  FS = 0;
    GLint Long;
    char         *Str = NULL;

    /* openglCreateProgram */
    /* 初始化 */
    if(Shader)
        memset(Shader, 0, sizeof(struct openglShader));
    else
        return 0;

    /* 创建顶点着色器 */
    if(VShader) // 字符串
        VS = openglCreateShader(VShader, GL_VERTEX_SHADER);
    else if(VShaderF) // 文件
    {
        /* 读取文件 */
        Str = __getfiledata(VShaderF);
        VS = openglCreateShader(Str, GL_VERTEX_SHADER);
        if(Str)
            free(Str);
    }
    /* 读取日志 */
    glGetShaderiv(VS, GL_INFO_LOG_LENGTH, &Long);
    Shader->vlog = (char*)malloc(Long + 1);
    glGetShaderInfoLog(VS, Long + 1, NULL, Shader->vlog);

    /* 创建片元着色器 */
    if(FShader) // 字符串
        FS = openglCreateShader(FShader, GL_FRAGMENT_SHADER);
    else if(FShaderF) // 文件
    {
        /* 读取文件 */
        Str = __getfiledata(FShaderF);
        FS = openglCreateShader(Str, GL_FRAGMENT_SHADER);
        if(Str)
            free(Str);
    }
    /* 读取日志 */
    glGetShaderiv(FS, GL_INFO_LOG_LENGTH, &Long);
    Shader->flog = (char*)malloc(Long + 1);
    glGetShaderInfoLog(FS, Long + 1, NULL, Shader->flog);

    /* 创建着色器程序 */
    Shader->program = glCreateProgram();
	glAttachShader(Shader->program, VS);
	glAttachShader(Shader->program, FS);
	glLinkProgram(Shader->program);
	glUseProgram(Shader->program);
    /*释放着色器*/
    glDeleteShader(VS);
	glDeleteShader(FS);

    /* 读取日志 */
    glGetProgramiv(Shader->program, GL_INFO_LOG_LENGTH, &Long);
    Shader->plog = (char*)malloc(Long + 1);
    glGetProgramInfoLog(Shader->program, Long + 1, NULL, Shader->plog);

    glGetProgramiv(Shader->program, GL_LINK_STATUS, &Long);
    return (unsigned char)Long;
}

/**
 *  \brief	设置LocationID
 *
 *  \param	Shader	: 着色器结构体
 *  \param	ArrayName		: 数组位置
 *  \param	LocationName	: Uniform名字
 *
 *  \return 是否越界
 */
BOOL openglSetUniform(struct openglShader* Shader, unsigned int ArrayName, ...)
{
    /*可变参列表*/
    va_list List;
    unsigned int Number = 0;
    char* String = NULL;

    va_start(List, ArrayName);
    Number = ArrayName;
    String = va_arg(List, char*);
    do {
        /*设置*/
        Shader->uniform[Number] = glGetUniformLocation(Shader->program, String);

        /*下一个*/
        Number = va_arg(List, unsigned int);
        String = va_arg(List, char*);
    } while (Number);

    /*退出可变参*/
    va_end(List);
    return TRUE;
}