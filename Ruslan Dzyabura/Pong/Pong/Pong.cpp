﻿// Pong.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include"StringHelper.h"
#include"MathsHelper.h"
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
// a few keycodes from 
// http://msdn.microsoft.com/en-us/library/windows/desktop/dd375731%28v=vs.85%29.aspx

// window size and update rate (60 fps)



//
MathsHelper mh;
//
//

//OpenGlSystem
void enable2D(int width, int height) {
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0f, width, 0.0f, height, 0.0f, 1.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
//OpenGlSystem
void drawRect(float x, float y, float width, float height) {
	glBegin(GL_QUADS);
	glVertex2f(x, y);
	glVertex2f(x + width, y);
	glVertex2f(x + width, y + height);
	glVertex2f(x, y + height);
	glEnd();
}
//OpenGlSystem
void drawText(float x, float y, std::string text) {
	glRasterPos2f(x, y);
	glutBitmapString(GLUT_BITMAP_8_BY_13, (const unsigned char*)text.c_str());
}
void draw() {
	
	// clear (has to be done at the beginning)
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	// draw rackets
	drawRect(mh.racket_left_x, mh.racket_left_y,mh.racket_width,mh.racket_height);
	drawRect(mh.racket_right_x, mh.racket_right_y,mh. racket_width,mh. racket_height);

	// draw ball
	drawRect(mh.ball_pos_x - mh.ball_size / 2,mh. ball_pos_y - mh.ball_size / 2, mh.ball_size,mh. ball_size);
	 
	// draw score
	drawText(OpenGlSystem::width / 2 - 10, OpenGlSystem::height - 15, StringHelper::int2str(mh.score_left) + ":" + StringHelper::int2str(mh.score_right));

	// swap buffers (has to be done at the end)
	glutSwapBuffers();
}
void keyboard() {
	// left racket
	if (GetAsyncKeyState(VK_W))  mh.racket_left_y += mh.racket_speed;
	if (GetAsyncKeyState(VK_S))  mh.racket_left_y -= mh.racket_speed;

	// right racket
	if (GetAsyncKeyState(VK_UP))  mh.racket_right_y += mh.racket_speed;
	if (GetAsyncKeyState(VK_DOWN))  mh.racket_right_y -= mh.racket_speed;
}


void update(int value) {
	// input handling
	keyboard();

	// update ball
	mh.updateBall();

	// Call update() again in 'interval' milliseconds
	glutTimerFunc(OpenGlSystem::interval, update, 0);

	// Redisplay frame
	glutPostRedisplay();
}
//
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(OpenGlSystem::width, OpenGlSystem::height);
	glutCreateWindow("Pong Example");
	//Регистрация функций обратного вызова 
	glutDisplayFunc(draw);
	glutTimerFunc(OpenGlSystem::interval, update, 0);
	//установка размеров сцены и "базового" цвета
	enable2D(OpenGlSystem::width, OpenGlSystem::height);
	glColor3f(1.0f, 1.0f, 1.0f);
	glutMainLoop();
	return 0;
}

