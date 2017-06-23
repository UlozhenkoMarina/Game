// lab_task_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#include <glut.h> 
//#include <glaux.h>
#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
//#include <GL/glew.h>
#endif

// ----------------------------------------------------------
// Function Prototypes
// ----------------------------------------------------------
void display();
void specialKeys();

// ----------------------------------------------------------
// Global Variables
// ----------------------------------------------------------
double rotate_y = 0;
double rotate_x = 0;
double move_x = 0;
double move_y = 0;
double move_z = 0;
double size = 1;
double color_x = 0;
double color_y = 0;
double color_z = 0;

// ----------------------------------------------------------
// display() Callback function
// ----------------------------------------------------------
void display() {

	//  Clear screen and Z-buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Reset transformations
	glLoadIdentity();

	// Other Transformations
	// glTranslatef( 0.1, 0.0, 0.0 );      // Not included
	// glRotatef( 180, 0.0, 1.0, 0.0 );    // Not included

	// Rotate when user changes rotate_x and rotate_y
	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);

	// Other Transformations
	// glScalef( 2.0, 2.0, 0.0 );          // Not included

	//Multi-colored side - FRONT
	glBegin(GL_POLYGON);

	glColor3f(1.0+color_x, 0.0+color_y, 0.0+color_z);     glVertex3f(size*(0.5+move_x),size*( -0.5+move_y), size*(-0.5+move_z));      // P1 is red
	glColor3f(0.0+color_x, 1.0+color_y, 0.0+color_z);     glVertex3f(size*(0.5+move_x),size*( 0.5+move_y),size*( -0.5+move_z));      // P2 is green
	glColor3f(0.0+color_x, 0.0+color_y, 1.0+color_z);     glVertex3f(size*(-0.5+move_x),size*( 0.5+move_y),size*( -0.5+move_z));      // P3 is blue
	glColor3f(1.0+color_x, 0.0+color_y, 1.0+color_z);     glVertex3f(size*(-0.5+move_x), size*(-0.5+move_y),size*( -0.5+move_z));      // P4 is purple

	glEnd();

	// White side - BACK
	glBegin(GL_POLYGON);
	glColor3f(1.0+color_x, 1.0+color_y, 1.0+color_z);
	glVertex3f(size*(0.5+move_x),size*( -0.5+move_y),size*( 0.5+move_z));
	glVertex3f(size*(0.5+move_x), size*(0.5+move_y),size*( 0.5+move_z));
	glVertex3f(size*(-0.5+move_x),size*( 0.5+move_y),size*( 0.5+move_z));
	glVertex3f(size*(-0.5+move_x), size*(-0.5+move_y),size*( 0.5+move_z));
	glEnd();

	// Purple side - RIGHT
	glBegin(GL_POLYGON);
	glColor3f(1.0+color_x, 0.0+color_y, 1.0+color_z);
	glVertex3f(size*(0.5+move_x),size*( -0.5+move_y),size*( -0.5+move_z));
	glVertex3f(size*(0.5+move_x), size*(0.5+move_y),size*( -0.5+move_z));
	glVertex3f(size*(0.5+move_x), size*(0.5+move_y),size*( 0.5+move_z));
	glVertex3f(size*(0.5+move_x),size*( -0.5+move_y),size*( 0.5+move_z));
	glEnd();

	// Green side - LEFT
	glBegin(GL_POLYGON);
	glColor3f(0.0+color_x, 1.0+color_y, 0.0+color_z);
	glVertex3f(size*(-0.5+move_x), size*(-0.5+move_y),size*( 0.5+move_z));
	glVertex3f(size*(-0.5+move_x),size*( 0.5+move_y),size*( 0.5+move_z));
	glVertex3f(size*(-0.5+move_x),size*( 0.5+move_y),size*( -0.5+move_z));
	glVertex3f(size*(-0.5+move_x),size*( -0.5+move_y),size*( -0.5+move_z));
	glEnd();

	// Blue side - TOP
	glBegin(GL_POLYGON);
	glColor3f(0.0+color_x, 0.0+color_y, 1.0+color_z);
	glVertex3f(size*(0.5+move_x),size*( 0.5+move_y),size*( 0.5+move_z));
	glVertex3f(size*(0.5+move_x),size*( 0.5+move_y),size*( -0.5+move_z));
	glVertex3f(size*(-0.5+move_x),size*( 0.5+move_y),size*( -0.5+move_z));
	glVertex3f(size*(-0.5+move_x), size*(0.5+move_y),size*( 0.5+move_z));
	glEnd();

	// Red side - BOTTOM
	glBegin(GL_POLYGON);
	glColor3f(1.0+color_x, 0.0+color_y, 0.0+color_z);
	glVertex3f(size*(0.5+move_x), size*(-0.5+move_y),size*( -0.5+move_z));
	glVertex3f(size*(0.5+move_x), size*(-0.5+move_y),size*( 0.5+move_z));
	glVertex3f(size*(-0.5+move_x),size*( -0.5+move_y),size*( 0.5+move_z));
	glVertex3f(size*(-0.5+move_x),size*( -0.5+move_y),size*( -0.5+move_z));
	glEnd();

	glFlush();
	glutSwapBuffers();

}

// ----------------------------------------------------------
// specialKeys() Callback Function
// ----------------------------------------------------------
void specialKeys(int key, int x, int y) {

	//  Right arrow - increase rotation by 5 degree
	if (key == GLUT_KEY_RIGHT)
		rotate_y += 5;

	//  Left arrow - decrease rotation by 5 degree
	else if (key == GLUT_KEY_LEFT)
		rotate_y -= 5;

	else if (key == GLUT_KEY_UP)
		rotate_x += 5;

	else if (key == GLUT_KEY_DOWN)
		rotate_x -= 5;
	else if (key == GLUT_KEY_F1)
	{
		move_x += 0.05;
	}
	else if (key == GLUT_KEY_F2)
	{
		move_x -= 0.05;
	}
	else if (key == GLUT_KEY_F3)
	{
		move_y += 0.05;
	}
	else if (key == GLUT_KEY_F4)
	{
		move_y -= 0.05;
	}
	else if (key == GLUT_KEY_F10)
	{
		size /= 2;
	}
	else if (key == GLUT_KEY_F11)
	{
		if((size*2+0.5+move_x)<1 && (size * 2 + 0.5 + move_y)<1 && (size * 2 + 0.5 + move_z)<1)
		size *= 2;
	}
	else if (key == GLUT_KEY_F5)
	{
		color_x += 0.1;
	}
	else if (key == GLUT_KEY_F6)
	{
		color_x -= 0.1;
	}
	else if (key == GLUT_KEY_F7)
	{
		color_y += 0.1;
	}
	else if (key == GLUT_KEY_F8)
	{
		color_y -= 0.1;
	}
	else if (key == GLUT_KEY_F9)
	{
		color_z += 0.1;
	}
	else if (key == GLUT_KEY_F12)
	{
		color_z -= 0.1;
	}
	//  Request display update
	glutPostRedisplay();

}

// ----------------------------------------------------------
// main() function
// ----------------------------------------------------------
int main(int argc, char* argv[]) {

	//  Initialize GLUT and process user parameters
	glutInit(&argc, argv);

	//  Request double buffered true color window with Z-buffer
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	// Create window
	glutCreateWindow("Awesome Cube");

	//  Enable Z-buffer depth test
	glEnable(GL_DEPTH_TEST);

	// Callback functions
	glutDisplayFunc(display);
	glutSpecialFunc(specialKeys);

	//  Pass control to GLUT for events
	glutMainLoop();

	//  Return to OS
	return 0;

}
