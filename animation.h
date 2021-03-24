#ifndef ANIMATION
#define ANIMATION

class Animation {

	// constants
	const static float window_angle = 0.0f;
	const static float PI = 3.14159;

	public:
		void set_window(int x, int y, int width, int height);
		void render();
		void change_size(int w, int h);
		void keyboard(unsigned char c, int x, int y);
		void mouse(int button, int state, int x, int y);
		int run(int argc, char *argv[]);
};

#endif
