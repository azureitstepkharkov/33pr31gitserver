// Pong_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include"StringHelper.h"
#include"MathHelper.h"
#include"OpenGLSystem.h"
#include <string>
#include <windows.h>
#include <iostream>
#include <conio.h>
#include <sstream> 
#include <math.h> 
#include <gl\gl.h>
#include <gl\glu.h>
#include "GL/freeglut.h"

//freeglut - производитель
#pragma comment(lib, "Opengl32.lib")

MathHelper mh;
//

// rackets in general



//
//

//OpenGLSystem
void enable2D(int width, int height) {
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0f, width, 0.0f, height, 0.0f, 1.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
//OpenGLSystem
void drawRect(float x, float y, float width, float height) {
	glBegin(GL_QUADS);
	glVertex2f(x, y);
	glVertex2f(x + width, y);
	glVertex2f(x + width, y + height);
	glVertex2f(x, y + height);
	glEnd();
}
//OpenGLSystem
void drawText(float x, float y, std::string text) {
	glRasterPos2f(x, y);
	glutBitmapString(GLUT_BITMAP_8_BY_13, (const unsigned char*)text.c_str());
}

//////////
void update(int value) {
	// input handling
	keyboard();

	// update ball
	updateBall();

	// Call update() again in 'interval' milliseconds
	glutTimerFunc(interval, update, 0);

	// Redisplay frame
	glutPostRedisplay();
}

//OpenGLSystem

void draw() {
	// clear (has to be done at the beginning)
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	// draw rackets
	drawRect(mh.racket_left_x, mh.racket_left_y,mh. racket_width,mh. racket_height);
	drawRect(mh.racket_right_x,mh. racket_right_y,mh. racket_width, mh.racket_height);

	// draw ball
	drawRect(mh.ball_pos_x - mh.ball_size / 2, mh.ball_pos_y - mh.ball_size / 2, mh.ball_size, mh.ball_size);
	//StringHelper sh;
	// draw score
	drawText(width / 2 - 10, height - 15, int2str(score_left) + ":" + int2str(score_right));
	StringHelper::int2str(score_left)+":"+
		StringHelper:: + int2str(score_right));
	// swap buffers (has to be done at the end)
	glutSwapBuffers();
}



	

	// make sure that length of dir stays at 1
	MathHelper::vec2_norm(ball_dir_x, ball_dir_y);
}


//
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(OpenGLSystem::width, height);
	glutCreateWindow("Pong Example");
	//Регистрация функций обратного вызова 
	glutDisplayFunc(draw);
	glutTimerFunc(OpenGLSystem::interval, update, 0);
	//установка размеров сцены и "базового" цвета
	enable2D(OpenGLSystem::width, OpenGLSystem::height);
	glColor3f(1.0f, 1.0f, 1.0f);
	glutMainLoop();
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

