// file for creating animation, don't worry about the math just yet

// libraries
#include <GL/glut.h>

// set up OpenGL
void initialize(int argc, char **argv){
	glutInit(&argc, argv);
//	glutInitWindowPosition(int x, int y);
//	glutInitWindowSize(int width, int height)
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // default color mode | double buffer window | depth buffer
	glutCreateWindow("Flight_Trajectory");
}

// program terminates when last statement in main executed
int main(int argc, char **argv){

	initialize(argc, argv);

	return 1;
}
