/*
 * Task.hpp
 *
 *  Created on: 2018/12/28
 *      Author: stomo
 */

#ifndef TASK_HPP_
#define TASK_HPP_

#if defined (__APPLE__) || defined(MACOSX)
  #pragma clang diagnostic ignored "-Wdeprecated-declarations"
  #include <GLUT/glut.h>
  #ifndef glutCloseFunc
  #define glutCloseFunc glutWMCloseFunc
  #endif
#else
#include <GL/freeglut.h>
#endif

#include <iostream>

class Task {

protected:
	size_t thdid_;    // スレッドID
	size_t tskid_;   // タスク名（整数値）
	double start_;  // タスク開始時刻
	double finsh_; // タスク終了時刻

public:
	Task();
	Task( const size_t thd, const size_t task, const double start, const double finish );

	// Getters
	size_t thread_id() {
		return thdid_;
	}

	size_t task_id() {
		return tskid_;
	}

	double start_t() {
		return start_;
	}

	double finish_t() {
		return finsh_;
	}

	// Operator << overload
	friend std::ostream& operator << (std::ostream& os, const Task& t) {
		os << t.thdid_ << ", " << t.tskid_ << ", " << t.start_ << ", " << t.finsh_;
		return os;
	}

	void Draw();
};

Task::Task()
{
	thdid_ = 0; tskid_ = 0; start_ = 0.0; finsh_ = 0.0;
}

Task::Task( const size_t thd, const size_t task, const double start, const double finish )
{
	thdid_ = thd; tskid_ = task; start_ = start; finsh_ = finish;
}

void Task::Draw()
{
	switch(tskid_) {
	case 0:
		glColor3d(1.0,0.0,0.0);  // 赤
		break;
	case 1:
		glColor3d(0.0,1.0,0.0);  // 緑
		break;
	case 2:
		glColor3d(0.0,0.0,1.0);  // 青
		break;
	case 3:
		glColor3d(1.0,1.0,1.0);  // 白
		break;
	}

	double Ytop = -1.0*thdid_;
	double Ybottom = -1.0*(thdid_ + 0.9);

	double Xleft = start_;
	double Xright = finsh_;

	glBegin(GL_QUAD_STRIP);        // 四角形の描画
	glVertex2d( Xleft,  Ytop );
	glVertex2d( Xright, Ytop );
	glVertex2d( Xleft,  Ybottom );
	glVertex2d( Xright, Ybottom );
	glEnd();
}

#endif /* TASK_HPP_ */
