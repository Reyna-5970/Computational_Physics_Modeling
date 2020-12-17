// file for creating animation, don't worry about the math just yet

// libraries
#include </usr/include/GL/glut.h>

// set up OpenGL
void set_window(void){
//	glutInitWindowPosition(int x, int y);
//	glutInitWindowSize(int width, int height)
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // default color mode | double buffer window | depth buffer
	glutCreateWindow("Flight_Trajectory");
}

// program terminates when last statement in main executed
int main(int argc, char *argv[]){

	glutInit(&argc, argv);
	set_window();

	glutMainLoop();
	// execution never reaches this point
	return 0;
}
