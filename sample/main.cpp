//
//  main.cpp
//  sample
//
//  Created by Hidesato on 2022/03/11.
//

#include <cstdlib>
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

int main(int argc, const char * argv[]) {
    if(glfwInit()==GL_FALSE){
        //初期化失敗
        std::cerr << "Can't initialize GLFW" << std::endl;
        return -1;
    }
    //終了時の処理を登録する。cstdlibの関数。glfwTerminateでリソースの全解放？
    atexit(glfwTerminate);
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,2);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT,GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
    //ウィンドウ作成
    GLFWwindow *const window(glfwCreateWindow(640, 480, "Practice !", NULL, NULL));
    if(window==NULL){
        // ウィンドウが作成できなかった
        std::cerr << "Can't create GLFW window." << std::endl;
        return 1;
    }
    //作成したウィンドウをOpenGLの対象にする
    glfwMakeContextCurrent(window);
    
    //GLEWの初期化
    //プラットフォームでサポートされていないOpenGLの機能を有効にする。
    if(glewInit() != GLEW_OK){
        std::cerr << "Cant initialize GLEW" << std::endl;
        return -1;
    }
    
    glfwSwapInterval(1);
    
    // 背景色を指定する
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    
    // ウィンドウが開いている間繰り返す
     while (glfwWindowShouldClose(window) == GL_FALSE)
     {
     // ウィンドウを消去する
     glClear(GL_COLOR_BUFFER_BIT);
     //
     // ここで描画処理を行う
     //
     // カラーバッファを入れ替える
     glfwSwapBuffers(window);
     // イベントを取り出す
     glfwWaitEvents();
         
     }
}
