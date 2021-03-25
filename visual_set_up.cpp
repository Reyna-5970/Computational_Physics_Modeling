// libraries
#include <GL/glut.h>

// local files
#include "visual_set_up.h"

// set up OpenGL
void Visual_Set_Up::set_window(int x, int y, int w, int h) {
	glutInitWindowPosition(x, y);
	glutInitWindowSize(w, h);
	// RGBA where A is alpha (opacity). instead, RGB used (use glColor3f which takes in 3 args as RGB values)
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // default color mode | [or operator] double buffer window | depth buffer
	glutCreateWindow("Flight Trajectory");
}
