// libraries
#include <GL/glut.h>
#include <math.h> //comment out when oop
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

// local files
#include "animation.h"

// global vars
float angle = 0.0f;

// set up OpenGL 
void set_window(int x, int y, int width, int height) {
	glutInitWindowPosition(x, y);
	glutInitWindowSize(width, height);
	// RGBA where A is alpha (opacity). instead, RGB used (use glColor3f which takes in 3 args as RGB values)
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); //default color mode | [or operator] double buffer window | depth buffer
	glutCreateWindow("Flight Trajectory");
}

void render() {
	// clear color
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// reset transformations (overwrite with identity matrix)
	glLoadIdentity();
	// translation (shifting of origin); f means float entry
	glTranslatef(-1.0, -1.0, -5.0);
	// rotation linear transformation matrix
	// around the vector x, y, z
	glRotatef(angle, 0.0f, 1.0f, 0.0f);

	// polygon in question
	// (x, y, z) where bottom left is origin & z is depth
	glBegin(GL_POLYGON); // 3f denotes 3D. change to 2f if 2D

	// all vertices below this method will match this color
	// "shading" determines how color is distributed (e.g. gradient for diff colored vertices)
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(0.0f, 1.0f, 0.0f);
		glVertex3f(1.0f, 0.0f, 0.0f);
	glEnd();

	// angle change --> animation
	angle += 1;

	// cause front & back buffers to switch (showing what was previously drawn in other buffer)
	// double buffer eliminates distortion problem with single buffer mode
	glutSwapBuffers();
}

void change_size(int w, int h) {
	
	// prevent division by 0 when window is too short
	if (h == 0) {
		h = 1;
	}
	float ratio = 1.0 * w / h;

	// use the projection matrix
	glMatrixMode(GL_PROJECTION);

	// reset matrix
	glLoadIdentity();

	// set the viewport to be the entire window
	glViewport(0, 0, w, h);
	// set the correct perspective
	gluPerspective(45, ratio, 1, 1000);
	// go back to modelview
	glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char c, int x, int y) {
	// enter keyboard commands
}

void mouse(int button, int state, int x, int y) {
	// enter mouse commands
	// GLUT_LEFT_BUTTON | GLUT_RIGHT_BUTTON | GLUT_MIDDLE_BUTTON
	// GLUT_UP | GLUT_DOWN
	// lighthouse3d.com/tutorials/glut-tutorial/the-mouse/
}

// program terminates when last statement in main executed
int main(int argc, char *argv[]) {

	// init GLUT and create window
	glutInit(&argc, argv);
	if (!glutInit) {
		fprintf(stderr, "Failed to initialize GLUT");
		return -1;
	}
	set_window(100, 100, 480, 480);

	// gluOrtho2D( left, right, bottom, top) <<<< mapping (it's an orthogonal projection matrix!)
	// R2 space --> R2 space on plane where z = -1
	// stackoverflow.com/questions/49705057/not-understanding-the-glutortho2d-function
	// gluOrtho2D(0.0, 10.0, 0.0, 10.0);
	
	// clear colors. sets background to black
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	// register callbacks
	glutDisplayFunc(render);
	glutReshapeFunc(change_size);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);

	// when application is idle, call render function
	glutIdleFunc(render);

	// enter GLUT event processing loop
	glutMainLoop();
	// execution never reaches this point
	return 0;
}
