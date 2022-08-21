#include "Play.h"

/*顶点着色器*/
const char* VShader_1 = {
"#version 330 core\n\
layout(location = 0) in vec3 aPos;\n\
layout(location = 1) in vec2 aTexCoord;\n\
out vec2 TexCoord;\n\
uniform mat4 proj;\n\
uniform mat4 view;\n\
uniform mat4 model;\n\
void main()\n\
{\n\
    gl_Position = proj * view * model * vec4(aPos, 1.0f);\n\
    TexCoord = aTexCoord; \n\
}"
};
const char* VShader_2 = {
"#version 330 core\n\
layout(location = 0) in vec3 aPos;\n\
layout(location = 1) in vec2 aTexCoord;\n\
layout(location = 2) in float C;\n\
out vec2 TexCoord;\n\
out float Chose;\n\
uniform mat4 proj;\n\
uniform mat4 view;\n\
uniform mat4 model;\n\
void main()\n\
{\n\
    gl_Position = proj * view * model * vec4(aPos, 1.0f);\n\
    TexCoord = aTexCoord; \n\
    Chose = C;\n\
}"
};
/*片段着色器*/
const char* FShader_1 = {
"#version 330 core\n\
out vec4 FragColor;\n\
in vec2 TexCoord;\n\
uniform sampler2D ourTexture;\n\
void main()\n\
{\n\
    FragColor = texture(ourTexture, TexCoord);\n\
}"
};
const char* FShader_2 = {
"#version 330 core\n\
out vec4 FragColor;\n\
in vec2 TexCoord;\n\
in float Chose;\n\
uniform sampler2D ourTexture[6];\n\
void main()\n\
{\n\
if(Chose < 0.1f)\n\
    FragColor = texture(ourTexture[0], TexCoord); \n\
else if(Chose <= 1.1f)\n\
    FragColor = texture(ourTexture[1], TexCoord); \n\
else if(Chose <= 2.1f)\n\
    FragColor = texture(ourTexture[2], TexCoord); \n\
else if(Chose <= 3.1f)\n\
    FragColor = texture(ourTexture[3], TexCoord); \n\
else if(Chose <= 4.1f)\n\
    FragColor = texture(ourTexture[4], TexCoord); \n\
else if(Chose <= 5.1f)\n\
    FragColor = texture(ourTexture[5], TexCoord); \n\
}"
};


openglShader Shader[2] = { 0 };

enum
{
    proj = 0, view = 1, model = 2
};

void Play()
{
    /*获取桌面背景*/
    unsigned int DeskImage;
    int w, h;
    {
        IMAGE Black;
        w = GetSystemMetrics(SM_CXSCREEN);
        h = GetSystemMetrics(SM_CYSCREEN);
        /* 设置IMAGE大小 */
        Resize(&Black, w, h);
        /* 复制HDC */
        BitBlt(GetImageHDC(&Black), 0, 0, w, h, GetWindowDC(GetDesktopWindow()), 0, 0, SRCCOPY);
        /*创建Texture*/
        glGenTextures(1, &DeskImage);
        glBindTexture(GL_TEXTURE_2D, DeskImage);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, w, h, 0, GL_BGRA, GL_UNSIGNED_BYTE, GetImageBuffer(&Black));
        glGenerateMipmap(GL_TEXTURE_2D);
    }
  
    float Point_Out[] = {
        -3.0f,  3.0f, 7.0f, 0.0f, 1.0f,
        -3.0f, -3.0f, 7.0f, 0.0f, 0.0f,
         3.0f, -3.0f, 7.0f, 1.0f, 0.0f,

         3.0f, -3.0f, 7.0f, 1.0f, 0.0f,
         3.0f,  3.0f, 7.0f, 1.0f, 1.0f,
        -3.0f,  3.0f, 7.0f, 0.0f, 1.0f
    };
    float Point_Box[] = {
        -1.0f, -1.0f, 1.0f, 0.0f, 1.0f, 0.0f,
         1.0f, -1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
         1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
         1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
        -1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f,
        -1.0f, -1.0f, 1.0f, 0.0f, 1.0f, 0.0f,

        -1.0f, -1.0f, -1.0f, 0.0f, 1.0f, 1.0f,
         1.0f, -1.0f, -1.0f, 1.0f, 1.0f, 1.0f,
         1.0f, 1.0f, -1.0f, 1.0f, 0.0f, 1.0f,
         1.0f, 1.0f, -1.0f, 1.0f, 0.0f, 1.0f,
        -1.0f, 1.0f, -1.0f, 0.0f, 0.0f, 1.0f,
        -1.0f, -1.0f, -1.0f, 0.0f, 1.0f, 1.0f,

        -1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 2.0f,
        -1.0f, 1.0f, -1.0f, 1.0f, 0.0f, 2.0f,
        -1.0f, -1.0f, -1.0f, 0.0f, 0.0f, 2.0f,
        -1.0f, -1.0f, -1.0f, 0.0f, 0.0f, 2.0f,
        -1.0f, -1.0f, 1.0f, 0.0f, 1.0f, 2.0f,
        -1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 2.0f,

         1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 3.0f,
         1.0f, 1.0f, -1.0f, 1.0f, 0.0f, 3.0f,
         1.0f, -1.0f, -1.0f, 0.0f, 0.0f, 3.0f,
         1.0f, -1.0f, -1.0f, 0.0f, 0.0f, 3.0f,
         1.0f, -1.0f, 1.0f, 0.0f, 1.0f, 3.0f,
         1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 3.0f,

        -1.0f, -1.0f, -1.0f, 0.0f, 0.0f, 4.0f,
         1.0f, -1.0f, -1.0f, 1.0f, 0.0f,4.0f,
         1.0f, -1.0f, 1.0f, 1.0f, 1.0f,4.0f,
         1.0f, -1.0f, 1.0f, 1.0f, 1.0f,4.0f,
        -1.0f, -1.0f, 1.0f, 0.0f, 1.0f,4.0f,
        -1.0f, -1.0f, -1.0f, 0.0f, 0.0f, 4.0f,

        -1.0f, 1.0f, -1.0f, 0.0f, 0.0f, 5.0f,
         1.0f, 1.0f, -1.0f, 1.0f, 0.0f, 5.0f,
         1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 5.0f,
         1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 5.0f,
        -1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 5.0f,
        -1.0f, 1.0f, -1.0f, 0.0f, 0.0f, 5.0f
    };
    /*顶点*/
    float Point_Desk[4][30] = {
        {
            -1.0f,  1.0f, 0.0f, 0.0f, 0.0f,
            -1.0f,  0.0f, 0.0f, 0.0f, 0.5f,
            0.0f,  0.0f, 0.0f, 0.5f, 0.5f,

            0.0f,  0.0f, 0.0f, 0.5f, 0.5f,
            0.0f,  1.0f, 0.0f, 0.5f, 0.0f,
            -1.0f,  1.0f, 0.0f, 0.0f, 0.0f
        },
        {
            0.0f,  1.0f, 0.0f, 0.5f, 0.0f,
            0.0f,  0.0f, 0.0f, 0.5f, 0.5f,
            1.0f,  0.0f, 0.0f, 1.0f, 0.5f,

            1.0f,  0.0f, 0.0f, 1.0f, 0.5f,
            1.0f,  1.0f, 0.0f, 1.0f, 0.0f,
            0.0f,  1.0f, 0.0f, 0.5f, 0.0f
        },
        {
            -1.0f,  0.0f, 0.0f, 0.0f, 0.5f,
            -1.0f, -1.0f, 0.0f, 0.0f, 1.0f,
            0.0f, -1.0f, 0.0f, 0.5f, 1.0f,

            0.0f, -1.0f, 0.0f, 0.5f, 1.0f,
            0.0f,  0.0f, 0.0f, 0.5f, 0.5f,
            -1.0f,  0.0f, 0.0f, 0.0f, 0.5f
        },
        {
            0.0f,  0.0f, 0.0f, 0.5f, 0.5f,
            0.0f, -1.0f, 0.0f, 0.5f, 1.0f,
            1.0f, -1.0f, 0.0f, 1.0f, 1.0f,

            1.0f, -1.0f, 0.0f, 1.0f, 1.0f,
            1.0f,  0.0f, 0.0f, 1.0f, 0.5f,
            0.0f,  0.0f, 0.0f, 0.5f, 0.5f
        }
        };
    float Point_Full[] = {
        -1.0f,  1.0f, 0.0f, 0.0f, 0.0f,
        -1.0f, -1.0f, 0.0f, 0.0f, 1.0f,
         1.0f, -1.0f, 0.0f, 1.0f, 1.0f,

         1.0f, -1.0f, 0.0f, 1.0f, 1.0f,
         1.0f,  1.0f, 0.0f, 1.0f, 0.0f,
        -1.0f,  1.0f, 0.0f, 0.0f, 0.0f
    };

#ifndef _DEBUG
    /*开始*/
    Mix_PlayChannel(-1, Chunk, 0);
    Mix_Volume(-1, MIX_MAX_VOLUME);
#endif

    /*分离桌面*/
        /*缓存对象*/
        unsigned int VAO_Desk[5], VBO_Desk[5];
        glGenVertexArrays(5, VAO_Desk);
        glGenBuffers(5, VBO_Desk);
        for (int i = 0; i < 4; i++)
        {//Desk
            glBindVertexArray(VAO_Desk[i]);
            glBindBuffer(GL_ARRAY_BUFFER, VBO_Desk[i]);
            glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 30, Point_Desk[i], GL_STATIC_DRAW);
            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(0 * sizeof(float)));
            glEnableVertexAttribArray(0);
            glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
            glEnableVertexAttribArray(1);
        }
        //Full
        glBindVertexArray(VAO_Desk[4]);
        glBindBuffer(GL_ARRAY_BUFFER, VBO_Desk[4]);
        glBufferData(GL_ARRAY_BUFFER, sizeof(Point_Full), Point_Full, GL_STATIC_DRAW);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(0 * sizeof(float)));
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
        glEnableVertexAttribArray(1);


        /*着色器*/
        openglCreateProgram(&Shader[0], VShader_1, FShader_1, NULL, NULL);
        glUseProgram(Shader[0].program);
        openglSetUniform(
            &Shader[0],
            (unsigned int)proj, "proj",
            (unsigned int)view, "view",
            (unsigned int)model, "model",
            0);

        /*设置视口*/
        glm::mat4 Model = glm::mat4(1.0f);
        glUniformMatrix4fv(Shader[0].uniform[proj], 1, GL_FALSE, glm::value_ptr(Model));
        glUniformMatrix4fv(Shader[0].uniform[view], 1, GL_FALSE, glm::value_ptr(Model));
        glUniformMatrix4fv(Shader[0].uniform[model], 1, GL_FALSE, glm::value_ptr(Model));
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        ShowWindow(H, SW_SHOW);
        glfwRestoreWindow(Window);
        /*分屏桌面*/
        float Temp_a = (float)glfwGetTime(), Temp_b;
        while ((Temp_b = (float)glfwGetTime()) <= Temp_a + 3.5f)
        {
            float i;
            i = (Temp_b - Temp_a) / 3.5f;
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            /*桌面*/
            {
                glBindTexture(GL_TEXTURE_2D, DeskImage);

                glBindTexture(GL_TEXTURE_2D, DeskImage);
                glUniformMatrix4fv(Shader[0].uniform[model], 1, GL_FALSE, glm::value_ptr(glm::rotate(glm::translate(Model, glm::vec3(-i, i, 0.0f)), (float)glm::radians(90.0f * (i / 1.0f)), glm::vec3(0.0f, 0.0f, 1.0f))));
                glBindVertexArray(VAO_Desk[0]);
                glDrawArrays(GL_TRIANGLES, 0, 6);

                glUniformMatrix4fv(Shader[0].uniform[model], 1, GL_FALSE, glm::value_ptr(glm::rotate(glm::translate(Model, glm::vec3(i, i, 0.0f)), (float)glm::radians(90.0f * (i / 1.0f)), glm::vec3(0.0f, 0.0f, 1.0f))));
                glBindVertexArray(VAO_Desk[1]);
                glDrawArrays(GL_TRIANGLES, 0, 6);

                glUniformMatrix4fv(Shader[0].uniform[model], 1, GL_FALSE, glm::value_ptr(glm::rotate(glm::translate(Model, glm::vec3(-i, -i, 0.0f)), (float)glm::radians(90.0f * (i / 1.0f)), glm::vec3(0.0f, 0.0f, 1.0f))));
                glBindVertexArray(VAO_Desk[2]);
                glDrawArrays(GL_TRIANGLES, 0, 6);

                glUniformMatrix4fv(Shader[0].uniform[model], 1, GL_FALSE, glm::value_ptr(glm::rotate(glm::translate(Model, glm::vec3(i, -i, 0.0f)), (float)glm::radians(90.0f * (i / 1.0f)), glm::vec3(0.0f, 0.0f, 1.0f))));
                glBindVertexArray(VAO_Desk[3]);
                glDrawArrays(GL_TRIANGLES, 0, 6);
            }

            /*粘贴背景*/
            {
                glBindTexture(GL_TEXTURE_2D, Texture[0]);
                glUniformMatrix4fv(Shader[0].uniform[model], 1, GL_FALSE, glm::value_ptr(Model));
                glBindVertexArray(VAO_Desk[4]);
                glDrawArrays(GL_TRIANGLES, 0, 6);
            }
            /*传递*/
            glfwSwapBuffers(Window);
            glfwPollEvents();
        }

    /*箱体旋转*/
    unsigned int VAO_box, VBO_box;
    unsigned int VAO_out, VBO_out;

    /*Box*/
    glGenVertexArrays(1, &VAO_box);
    glGenBuffers(1, &VBO_box);
    glBindVertexArray(VAO_box);
    glBindBuffer(GL_ARRAY_BUFFER, VBO_box);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Point_Box), Point_Box, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(0 * sizeof(float)));
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2, 1, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(5 * sizeof(float)));
    glEnableVertexAttribArray(2);

    /*Out*/
    glGenVertexArrays(1, &VAO_out);
    glGenBuffers(1, &VBO_out);
    glBindVertexArray(VAO_out);
    glBindBuffer(GL_ARRAY_BUFFER, VBO_out);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Point_Out), Point_Out, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(0 * sizeof(float)));
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    /*着色器*/
    openglCreateProgram(&Shader[1], VShader_2, FShader_2, NULL, NULL);
    
    glUseProgram(Shader[1].program);
    openglSetUniform(
        &Shader[1],
        (unsigned int)proj, "proj",
        (unsigned int)view, "view",
        (unsigned int)model, "model",
        0);
    glUniform1i(glGetUniformLocation(Shader[1].program, "ourTexture[0]"), 0);
    glUniform1i(glGetUniformLocation(Shader[1].program, "ourTexture[1]"), 1);
    glUniform1i(glGetUniformLocation(Shader[1].program, "ourTexture[2]"), 2);
    glUniform1i(glGetUniformLocation(Shader[1].program, "ourTexture[3]"), 3);
    glUniform1i(glGetUniformLocation(Shader[1].program, "ourTexture[4]"), 4);
    glUniform1i(glGetUniformLocation(Shader[1].program, "ourTexture[5]"), 5);
    glUniform1i(glGetUniformLocation(Shader[0].program, "ourTexture"), 0);
    for (int i = 0; i < 6; i++)
    {
        glActiveTexture(GL_TEXTURE0 + i);
        glBindTexture(GL_TEXTURE_2D, Texture[i]);
    }

    /*设置视口*/
    glUniformMatrix4fv(Shader[1].uniform[proj], 1, GL_FALSE, glm::value_ptr(glm::perspective(glm::radians(45.0f), 1024.0f / 768.0f, 0.1f, 100.0f)));
    glUniformMatrix4fv(Shader[1].uniform[view], 1, GL_FALSE, glm::value_ptr(glm::lookAt(glm::vec3(0.0f, 0.0f, 3.0f),
        glm::vec3(0.0f, 0.0f, 0.0f),
        glm::vec3(0.0f, 1.0f, 0.0f))));
    glUniformMatrix4fv(Shader[1].uniform[model], 1, GL_FALSE, glm::value_ptr(Model));
    

    Temp_a = (float)glfwGetTime(), Temp_b;
    while ((Temp_b = (float)glfwGetTime()) <= Temp_a + 17.0f)
    {
        float i;
        i = (Temp_b - Temp_a);

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        /*渲染*/
        {
            glUniformMatrix4fv(Shader[1].uniform[view], 1, GL_FALSE, glm::value_ptr(glm::lookAt(glm::vec3(0.0f, 0.0f, i + 3.0f),
                glm::vec3(0.0f, 0.0f, 0.0f),
                glm::vec3(0.0f, 1.0f, 0.0f))));
            glUseProgram(Shader[1].program);

            /* 绘制内部箱子 */
            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, Texture[0]);
            glUniformMatrix4fv(Shader[1].uniform[model], 1, GL_FALSE, glm::value_ptr(glm::rotate(Model, (float)i, glm::vec3(0.5f, 1.0f, 0.3f))));
            glBindVertexArray(VAO_box);
            glDrawArrays(GL_TRIANGLES, 0, 36);

            /* 绘制外部箱子 */
            /*一圈*/
            for (int j = 0; j < 360; j += 72)
            {
                glActiveTexture(GL_TEXTURE0);
                glBindTexture(GL_TEXTURE_2D, Texture[6 + (j/ 72)]);
                
                glUniformMatrix4fv(Shader[1].uniform[model], 1, GL_FALSE, glm::value_ptr(glm::rotate(glm::rotate(Model, glm::radians((float)j), glm::vec3(0.0f, 1.0f, 0.0f)), (float)i, glm::vec3(0.5f, 1.0f, 0.3f))));
                glBindVertexArray(VAO_out);
                glDrawArrays(GL_TRIANGLES, 0, 6);
            }

            /*3 S*/
            if (i > 14.0f)
            {
                float j = i - 14.0f;
                /*绘制桌面*/
                glUseProgram(Shader[0].program);
                glBindTexture(GL_TEXTURE_2D, DeskImage);
                glUniformMatrix4fv(Shader[0].uniform[model], 1, GL_FALSE, glm::value_ptr(glm::rotate(glm::translate(Model, glm::vec3((1.0f - j/3.0f) * 2.0f, 0.0f, 0.0f)), glm::radians(j / 3.0f * 360.0f), glm::vec3(0.0f, 0.0f, 1.0f))));
                glBindVertexArray(VAO_Desk[4]);
                glDrawArrays(GL_TRIANGLES, 0, 6);
            }
        }

        glfwSwapBuffers(Window);
        glfwPollEvents();
        Sleep(1);
    }
    glfwTerminate();
}
