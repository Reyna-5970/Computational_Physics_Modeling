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
		glVertex3f(-0.5, -0.5, 0.0);
		glVertex3f(0.5, 0.0, 0.0);
		glVertex3f(0.0, 0.5, 0.0);
	glEnd();
	glFlush();

	glutSwapBuffers();
}

// program terminates when last statement in main executed
int main(int argc, char *argv[]) {
	
	glutInit(&argc, argv);
	set_window(100, 100, 650, 480);
	glutDisplayFunc(display);

	glutMainLoop();
	// execution never reaches this point
	return 0;
}
