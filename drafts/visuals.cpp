// include standard headers
#include <stdio.h>
#include <stdlib.h>

// always include glew before gl.h and glfw3.h (it's magic)
#include <GL/glew.h>
// glfw handles window and keyboard
#include <GL/glfw.h>
// use for 3D math
#include <glm/glm.hpp>

// allows us to type "vec3" instead of "glm::vec3"
using namespace glm;

int main(void) {
	
	// initialize glfw
	glewExperimental = true; // core profile
	if (!glwInit()) {
		fprintf( stderr, "Failed to initialize GLFW/n" );
		return -1;
	}

	// create OpenGL window
	
	glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); makes MacOS happy
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // we don't want old OpenGL

	GLFWwindow* window; // variable is global for simplicity
	window = glfwCreateWindow(1024, 768, "Name", NULL, NULL);
	if( window == NULL ) {
		fprintf( stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.");
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window); // init glew
	glewExperimental = true; // needed in core profile
	if (glewInit() != GLEW_OK) {
		fprintf( stderr, "Failed to initialize GLEW\n");
		return -1;
	}

	// ensure we can capture esc key being pressed
	glfwSetInputMode(window, GLFW_STICKY_keys, GL_TRUE);

	do {
		// clear the screen
		glClear(GL_COLOR_BUFFER_BIT);

		// draw here

		// swap buffers
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	while(glfwGetKey(window, GLFW_KWY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window) == 0);

}
