// creating animation

// libraries
// #include <stdlib>
#include <GL/glut.h>
#include <iostream>

// global vars
float angle = 0.0f;

// set up OpenGL
void set_window(int x, int y, int width, int height) {
	glutInitWindowPosition(x, y);
	glutInitWindowSize(width, height);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // default color mode | double buffer window | depth buffer
	glutCreateWindow("Flight Trajectory");
}

void render(void) {
	// clear color and depth buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	// reset transformations
	glLoadIdentity();
	// set the camera
	gluLookAt(	0.0f, 0.0f, 10.0f,
				0.0f, 0.0f, 0.0f,
				0.0f, 1.0f, 0.0f);
	glRotatef(angle, 0.0f, 1.0f, 0.0f);
	
	// polygon in question
	// (x, y, z) where x and y init in bottom left & z is depth
	glBegin(GL_POLYGON);
		glVertex3f(-2, -2, -5.0);
		glVertex3f(2, 0.0, -5.0);
		glVertex3f(0.0, 2, -5.0);
	glEnd();
	glFlush();

	// angle change --> animation
	angle += 0.1f;

	// cause front & back buffers to switch (showing what was previously drawn in other buffer)
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
}

// program terminates when last statement in main executed
int main(int argc, char *argv[]) {
	
	// init GLUT and create window
	glutInit(&argc, argv);
	set_window(100, 100, 650, 480);

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
