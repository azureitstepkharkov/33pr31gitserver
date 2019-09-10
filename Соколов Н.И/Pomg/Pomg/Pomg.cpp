#include"pch.h"
#include <string>
#include <windows.h>
#include <iostream>
#include <conio.h>
#include <sstream> 
#include <math.h> 
#include <gl\gl.h>
#include <gl\glu.h>
#include "GL/freeglut.h"
#pragma comment(lib, "Opengl32.lib")
#include"StringHelper.h"
#include"MathHelper.h"
#include"OpenGSSysteam.h"

//using namespace std;


//window size and update rate (60 fps)

// rackets in general


// score

//
MashHelper ah;


#define VK_W 0x57//char = (char)int
#define VK_S 0x53
//openGlHelper
void enable2D(int width, int height) {
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0f, width, 0.0f, height, 0.0f, 1.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void drawRect(float x, float y, float width, float height) {
	glBegin(GL_QUADS);
	glVertex2f(x, y);
	glVertex2f(x + width, y);
	glVertex2f(x + width, y + height);
	glVertex2f(x, y + height);
	glEnd();
}
void drawText(float x, float y, std::string text) {
	glRasterPos2f(x, y);
	glutBitmapString(GLUT_BITMAP_8_BY_13, (const unsigned char*)text.c_str());
}
void keyboard() {
	// left racket
	if (GetAsyncKeyState(VK_W)) ah.racket_left_y += ah.racket_speed;
	if (GetAsyncKeyState(VK_S)) ah.racket_left_y -= ah.racket_speed;

	// right racket
	if (GetAsyncKeyState(VK_UP)) ah.racket_right_y += ah.racket_speed;
	if (GetAsyncKeyState(VK_DOWN)) ah.racket_right_y -= ah.racket_speed;
}
void draw() {
	// clear (has to be done at the beginning)
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	
	// draw rackets
	drawRect(ah.racket_left_x, ah.racket_left_y, ah.racket_width, ah.racket_height);
	drawRect(ah.racket_right_x, ah.racket_right_y, ah.racket_width, ah.racket_height);

	// draw ball
	drawRect(ah.ball_pos_x - ah.ball_size / 2, ah.ball_pos_y - ah.ball_size / 2, ah.ball_size, ah.ball_size);
	
	// draw score
	drawText(OpenGSSysteam::width / 2 - 10, OpenGSSysteam::height - 15, StringHelper::int2str(ah.score_left) + ":" + StringHelper::int2str(ah.score_right));

	// swap buffers (has to be done at the end)
	glutSwapBuffers();
}
void update(int value) {
	// input handling
	keyboard();

	// update ball
	ah.updateBall();

	// Call update() again in 'interval' milliseconds
	glutTimerFunc(OpenGSSysteam::interval, update, 0);

	// Redisplay frame
	glutPostRedisplay();
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(OpenGSSysteam::width, OpenGSSysteam:: height);
	glutCreateWindow("Pong Example");
	// 
	//

	glutDisplayFunc(draw);
	glutTimerFunc(OpenGSSysteam::interval, update, 0);

	enable2D(OpenGSSysteam::width, OpenGSSysteam:: height);
	glColor3f(1.0f, 1.0f, 1.0f);
	glutMainLoop();
	return 0;
}
