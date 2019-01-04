/*
 ============================================================================
 Name        : Trace.cu
 Author      : stomo
 Version     :
 Copyright   : Your copyright notice
 Description : CUDA compute reciprocals
 ============================================================================
 */

#include <iostream>
#include <cstdlib>
#include <vector>

#include "Task.hpp"

#if defined (__APPLE__) || defined(MACOSX)
  #pragma clang diagnostic ignored "-Wdeprecated-declarations"
  #include <GLUT/glut.h>
  #ifndef glutCloseFunc
  #define glutCloseFunc glutWMCloseFunc
  #endif
#else
#include <GL/freeglut.h>
#endif

#define ZOOM 50      // 拡大率

void resize(int w, int h)
{
	// Window全体をView portにする
	glViewport(0,0,w,h);

	// 変換行列の初期化
	glLoadIdentity();

	// Screen上の表示領域をView portの大きさに比例させる
//	glOrtho( -(double)w/ZOOM, (double)w/ZOOM, -(double)h/ZOOM, (double)h/ZOOM, -1.0, 1.0);
	glOrtho( 0.0, 2.0*(double)w/ZOOM, -(double)h/ZOOM, 0.0, -1.0, 1.0);
}

void display(void)
{
	//////////////////////////////////////////////
	// 背景を黒に
	glClearColor(0.0, 0.0, 0.0, 1.0); // 塗りつぶしの色を指定
	glClear(GL_COLOR_BUFFER_BIT);     // 塗りつぶし

	std::vector<Task> t;

	t.push_back(Task( 0, 0, 0.0, 1.0 ));
	t.push_back(Task( 1, 1, 1.1, 2.1 ));
	t.push_back(Task( 2, 2, 1.1, 2.6 ));
	t.push_back(Task( 3, 3, 2.8, 5.6 ));

	for(std::vector<Task>::iterator itr = t.begin(); itr != t.end(); ++itr)
		(*itr).Draw();


	glFlush();
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);          // OpenGL初期化
	glutInitWindowSize(1000,500);  // 初期Windowサイズ指定
	glutCreateWindow(argv[0]);      // Windowを開く
	glutDisplayFunc(display);       // Windowに描画
	glutReshapeFunc(resize);
	glutMainLoop();                 // イベント待ち

	return EXIT_SUCCESS;
}
