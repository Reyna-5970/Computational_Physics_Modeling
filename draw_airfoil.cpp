// libraries
#include <GL/glut.h>

/**
	vars:
	t = max thickness as fraction of chord
	x = pos along chord from 0 to 1
	y_t = half thickness at given val x

	parametric functions:
	y_t = 5t(0.4 sqrt(t) - 0.3x + 0.04x^2 - 0.24x^3 + 0.1x^4) {0 <= x <= 1}
	y_t = -5t(0.4 sqrt(t) - 0.3x + 0.04x^2 - 0.24x^3 + 0.1x^4) {0 <= x <= 1}
**/
