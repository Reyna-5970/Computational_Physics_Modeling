// creating animation

// libraries
// #include <stdlib>
#include <GL/glut.h>

// set up OpenGL
void set_window(int x, int y, int width, int height) {
	glutInitWindowPosition(x, y);
	glutInitWindowSize(width, height);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // default color mode | double buffer window | depth buffer
	glutCreateWindow("Flight Trajectory");
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glBegin(GL_POLYGON);
		glVertex3f(-2, -2, -5.0);
		glVertex3f(2, 0.0, -5.0);
		glVertex3f(0.0, 2, -5.0);
	glEnd();
	glFlush();

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

// program terminates when last statement in main executed
int main(int argc, char *argv[]) {
	
	// init GLUT and create window
	glutInit(&argc, argv);
	set_window(100, 100, 650, 480);

	// register callbacks
	glutDisplayFunc(display);
	glutReshapeFunc(change_size);

	// enter GLUT event processing loop
	glutMainLoop();
	// execution never reaches this point
	return 0;
}
