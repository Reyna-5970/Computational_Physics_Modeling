// libraries
// #include <stdlib.h> // comment out later, will include in main.cpp
// #include <stdio.h> // comment out later, will include in main.cpp
#include <GL/glut.h>
// #include <iostream> // comment out later, will include in main.cpp

using namespace std;

class Flight_Visuals {

	// global vars
	float angle = 0.0f;

	// set up OpenGL 
	void set_window(int x, int y, int width, int height) {
		glutInitWindowPosition(x, y);
		glutInitWindowSize(width, height);
		// RGBA where A is alpha (opacity). instead, RGB used (use glColor3f which takes in 3 arg.s as RGB vals)
		glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // default color mode | [or operator] double buffer window | depth buffer
		glutCreateWindow("Flight Trajectory");
	}

	void render(void) {
		//clear color
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)

		// reset transformations (overwrite with identity matrix)
		glLoadIdentity();
		// translation (shifting of origin); f means float entry
		glTranslatef(-1.0, -1.0, -5.0);

		// airfoil shape
		int i;
		int triangle_amount = 20;
		float tau = 2.0f * PI;
		int x = 0.0;
		int y = 0.0;
		int radius = 0.5;

		glBegin(GL_TRIANGLE_FAN);
			// circle
			glVertex3f(x, y, 0.0);
			for (i = 0; i <= triangle_amount; i++) {
				glVertex3f(
					x + (radius * cos(i * tau / triangle_amount)),
					y + (radius * sin(i * tau / triangle_amount)),
					0.0);
			}
			// triangle
			glVertex3f(x, (y + radius), 0.0);
			glVertex3f(x, (y - radius), 0.0);
			glVertex3f((x + 2), y, 0.0);
		glEnd();

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

	int run(int argc, char *argv[]) {

		// init GLUT and create window
		glutInit(&argc, argv);
		if (!glutInit) {
			fprintf(stderr, "Failed to initialize GLUT");
			return -1;
		}
		set_window(100, 100, 480, 480);

		// clear colors, set background to black
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

		// register callbacks
		glutDisplayFunc(render);
		glutReshapeFunc(change_size);
		glutKeyboardFunc(keyboard);
		glutMouseFunc(mouse);

		// when application is idle, call render method
		glutIdleFunc(render);

		// enter GLUT event processing loop
		glutMainLoop();
		// execution never reaches this point
		return 0;
	}

}; // obj names before ;
